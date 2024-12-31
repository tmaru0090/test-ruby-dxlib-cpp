@REM @echo off
@chcp 65001
@echo ビルドを開始しますー
@cmake . -G"MinGW Makefiles" -Bbuild
@cmake --build build


if exist "bin\script" (
	@echo bin\scriptが存在するので通常通りいきまーす
) else (
	@mkdir "bin\script"
)

if exist "bin\res" (
	@echo bin\resが存在するので通常通りいきまーす
) else (
	@mkdir "bin\res"
)



@xcopy ".\script\" ".\bin\script\" /E /I /H

@xcopy ".\res\" ".\bin\res\" /E /I /H

@REM g++ -pthread -fPIC -g -I"E:/windows/dev-tools/Ruby33-x64/include/ruby-3.3.0/" -I"E:/windows/dev-tools/Ruby33-x64/include/ruby-3.3.0/x64-mingw-ucrt/" main.cpp -o main.exe "E:/windows/dev-tools/Ruby33-x64/lib/libx64-ucrt-ruby330.dll.a"

