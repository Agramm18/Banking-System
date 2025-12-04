@echo off
setlocal EnableDelayedExpansion

echo ========================================
echo Building Banking System (MSVC auto)
echo ========================================
echo.

:: Compiler auswählen
set COMPILER=msvc
:: set COMPILER=mingw

echo Using compiler: %COMPILER%
echo.

:: ====== VCPKG Pfade ======
set VCPKG_ROOT=C:\vcpkg
set VCPKG_INCLUDE=%VCPKG_ROOT%\installed\x64-windows\include
set VCPKG_LIB=%VCPKG_ROOT%\installed\x64-windows\lib

:: ====== libsodium prüfen ======
if not exist "%VCPKG_INCLUDE%\sodium.h" (
    echo ERROR: sodium.h wurde NICHT gefunden!
    echo Erwartet unter: %VCPKG_INCLUDE%
    goto end
)

if not exist "%VCPKG_LIB%\libsodium.lib" (
    echo ERROR: libsodium.lib wurde NICHT gefunden!
    echo Erwartet unter: %VCPKG_LIB%
    goto end
)

echo Found libsodium under vcpkg.
echo Include: %VCPKG_INCLUDE%
echo Lib:     %VCPKG_LIB%
echo.

:: ====== Build-Ordner erstellen ======
if not exist build mkdir build
if not exist build\obj mkdir build\obj

:: CPP-Dateien sammeln
set "files="
for /R src %%f in (*.cpp) do (
    set "files=!files! "%%f""
)

echo Found files:
echo !files!
echo.

:: ============================
:: MinGW Build
:: ============================
if "%COMPILER%"=="mingw" (
    echo Compiling with MinGW g++...
    g++ -std=c++20 -g !files! ^
        -I include ^
        -I %VCPKG_INCLUDE% ^
        -L %VCPKG_LIB% -lsodium ^
        -o build\main.exe
    goto checkResult
)

:: ============================
:: MSVC Build
:: ============================
if "%COMPILER%"=="msvc" (

    echo Searching for MSVC environment...

    for /f "delims=" %%i in ('dir "C:\Program Files\Microsoft Visual Studio\" /s /b ^| findstr /i vcvars64.bat') do (
        set VCVARS=%%i
        goto foundVC
    )

    echo ERROR: vcvars64.bat nicht gefunden!
    goto end

    :foundVC
    echo Loading MSVC environment:
    echo %VCVARS%
    call "%VCVARS%"
    echo MSVC environment loaded.
    echo.

    :: MSVC Include/Lib erweitern
    set INCLUDE=%INCLUDE%;%VCPKG_INCLUDE%
    set LIB=%LIB%;%VCPKG_LIB%

    echo Compiling with MSVC...

    :: OBJ kompilieren
    for %%f in (!files!) do (
        set "fname=%%~nf"
        cl /std:c++20 /EHsc /Zc:__cplusplus /nologo ^
            /I include ^
            /I %VCPKG_INCLUDE% ^
            /c "%%f" ^
            /Fo"build\obj\!fname!.obj"

        if !errorlevel! neq 0 (
            echo ERROR beim Kompilieren: %%f
            goto end
        )
    )

    :: Linking
    echo Linking...
    set objfiles=
    for %%o in (build\obj\*.obj) do (
        set objfiles=!objfiles! "%%o"
    )

    link /OUT:build\main.exe !objfiles! libsodium.lib
)

:checkResult
if %errorlevel%==0 (
    echo.
    echo Build successful! Run with: build\main.exe
) else (
    echo.
    echo Build failed!
)

:end
echo.
pause
endlocal