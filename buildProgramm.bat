@echo off
setlocal EnableDelayedExpansion

echo 🔨 Building Banking System...

REM build Ordner erstellen, falls er nicht existiert
if not exist build mkdir build

REM CPP Dateien sammeln (rekursiv)
set "files="
for /R src %%f in (*.cpp) do (
    set "files=!files! "%%f""
)

echo Gefundene Dateien:
echo !files!
echo.

REM Kompilieren
g++ -std=c++20 -g !files! -I include -o build\main.exe

if %errorlevel%==0 (
    echo.
    echo ✅ Build successful! Run with: build\main.exe
) else (
    echo.
    echo ❌ Build failed!
)

endlocal
pause
