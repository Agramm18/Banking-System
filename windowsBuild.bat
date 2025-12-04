@echo off
setlocal enabledelayedexpansion

echo ============================================
echo   C++ Build Script (MSVC + vcpkg + libsodium)
echo ============================================

REM -------- Projekt-Root --------
set PROJECT_ROOT=%~dp0

mkdir "%PROJECT_ROOT%build" 2>nul
mkdir "%PROJECT_ROOT%build\obj" 2>nul

echo [OK] Build-Verzeichnis erstellt.

REM -------- MSVC via vswhere.exe finden --------
echo [INFO] Suche Visual Studio Installation...

set VSWHERE_EXE="C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"

for /f "usebackq tokens=*" %%i in (`%VSWHERE_EXE% -latest -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -find **\vcvars64.bat`) do (
    set VC_VARS=%%i
)

if "%VC_VARS%"=="" (
    echo [ERROR] Konnte vcvars64.bat nicht finden!
    exit /b 1
)

echo [OK] MSVC gefunden: %VC_VARS%
call "%VC_VARS%"

REM -------- vcpkg Pfade --------
for /d %%p in ("C:\vcpkg\installed\*") do (
    if exist "%%p\include\sodium.h" (
        set VCPKG_INCLUDE=%%p\include
        set VCPKG_LIB=%%p\lib
        set VCPKG_BIN=%%p\bin
    )
)

echo [OK] vcpkg include: %VCPKG_INCLUDE%
echo [OK] vcpkg lib:     %VCPKG_LIB%

REM -------- libsodium.dll direkt in build/ kopieren --------
copy "%VCPKG_BIN%\libsodium.dll" "%PROJECT_ROOT%build\" >nul
echo [OK] libsodium.dll nach build/ kopiert.

REM -------- CPP-Dateien sammeln --------
set SOURCES=
for /r "%PROJECT_ROOT%src" %%f in (*.cpp) do (
    set SOURCES=!SOURCES! "%%f"
)

echo [INFO] Gefundene Quellen:
echo %SOURCES%

REM -------- Kompilieren: jede Datei einzeln --------
echo [INFO] Kompiliere jede Quelldatei...

set OBJ_FILES=

for %%f in (%SOURCES%) do (
    set FILE_NAME=%%~nf
    echo [CC] %%f

    cl /EHsc /std:c++20 ^
       /I "%PROJECT_ROOT%include" ^
       /I "%VCPKG_INCLUDE%" ^
       /c "%%f" ^
       /Fo"%PROJECT_ROOT%build\obj\!FILE_NAME!.obj"

    if errorlevel 1 (
        echo [ERROR] Kompilierungsfehler bei %%f
        exit /b 1
    )

    set OBJ_FILES=!OBJ_FILES! "%PROJECT_ROOT%build\obj\!FILE_NAME!.obj"
)

REM -------- Linken --------
echo [INFO] Linke Executable...

link ^
  /OUT:"%PROJECT_ROOT%build\main.exe" ^
  %OBJ_FILES% ^
  /LIBPATH:"%VCPKG_LIB%" ^
  libsodium.lib

if errorlevel 1 (
    echo [ERROR] Linker Fehler!
    exit /b 1
)

echo --------------------------------------------
echo [OK] main.exe erfolgreich erstellt!
echo [INFO] Ausgabe unter:
echo        build\main.exe
echo        build\libsodium.dll
echo        build\obj\*.obj
echo --------------------------------------------

endlocal
exit /b 0
