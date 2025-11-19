#!/bin/bash

echo "🔨 Building Banking System..."

# build Ordner automatisch anlegen, falls er fehlt
mkdir -p build

# Kompiliere alle CPP Dateien
g++ -std=c++17 -g $(find src -name "*.cpp") -I include -o build/main

if [ $? -eq 0 ]; then
    echo "✅ Build successful! Run with: ./build/main"
else
    echo "❌ Build failed!"
fi
