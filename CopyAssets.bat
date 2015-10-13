@echo off
xcopy ..\assets ..\bin\Debug\Assets /E /H /C /R /Q /Y
xcopy ..\assets ..\bin\Release\Assets /E /H /C /R /Q /Y