@echo off
setlocal EnableDelayedExpansion

echo ========================================
echo 🔨 Building Banking System (MSVC auto)
echo ========================================
echo.

:: Wähle den Compiler: msvc oder mingw
set COMPILER=msvc
:: set COMPILER=mingw

echo 🔧 Using compiler: %COMPILER%
echo.

:: Ordner erstellen
if not exist build mkdir build
if not exist build\obj mkdir build\obj

:: CPP-Dateien sammeln
set "files="
for /R src %%f in (*.cpp) do (
    set "files=!files! "%%f""
)

echo Gefundene Dateien:
echo !files!
echo.

:: ============================
:: MinGW Pfad – Standard Build
:: ============================
if "%COMPILER%"=="mingw" (
    echo 🔧 Compiling with MinGW g++...
    g++ -std=c++20 -g !files! -I include -o build\main.exe
    goto checkResult
)

:: =============================
:: MSVC Build mit Autoload
:: =============================
if "%COMPILER%"=="msvc" (

    echo 🔧 Searching for MSVC environment...

    :: Automatische Suche nach vcvars64.bat
    for /f "delims=" %%i in ('dir "C:\Program Files\Microsoft Visual Studio\" /s /b ^| findstr /i vcvars64.bat') do (
        set VCVARS=%%i
        goto foundVC
    )

    echo ❌ ERROR: Could not find vcvars64.bat on your system.
    echo ➜ Ensure Visual Studio with Desktop C++ tools is installed.
    goto end

    :foundVC
    echo 🔧 Loading MSVC environment:
    echo     %VCVARS%
    echo.

    call "%VCVARS%"

    echo 🔧 MSVC environment loaded.
    echo.

    echo 🔧 Compiling with MSVC...

    :: Kompilieren zu OBJ
    for %%f in (!files!) do (
        set "fname=%%~nf"
        cl /std:c++20 /EHsc /Zc:__cplusplus /nologo /I include /c "%%f" /Fo"build\obj\!fname!.obj"
        if !errorlevel! neq 0 (
            echo ❌ Fehler beim Kompilieren: %%f
            goto end
        )
    )

    :: Linken
    echo 🔧 Linking...
    set objfiles=
    for %%o in (build\obj\*.obj) do (
        set objfiles=!objfiles! "%%o"
    )

    link /OUT:build\main.exe !objfiles!
)

:checkResult
if %errorlevel%==0 (
    echo.
    echo ✅ Build successful! Run with: build\main.exe
) else (
    echo.
    echo ❌ Build failed!
)

:end
echo.
pause
endlocal
