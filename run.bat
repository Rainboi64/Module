@echo off
echo building module to ./bin/output

gcc ./src/main.c -o ./bin/output.exe

echo starting module from ./bin/output

.\bin\output.exe