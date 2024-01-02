@echo off
for %%i in ("%cd:~0,-6%") do reg delete HKCU\Softerware\GTTech\%%~nxi /v DockSettings /f