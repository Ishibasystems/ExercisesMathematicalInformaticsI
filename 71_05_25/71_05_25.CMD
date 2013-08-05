@echo off

if not exist "%VS90COMNTOOLS%vsvars32.bat" goto missing
call "%VS90COMNTOOLS%vsvars32.bat"
cl 71_05_25.C Polish_Notation.C
del 71_05_25.OBJ Polish_Notation.OBJ
goto :eof

:missing
echo Error: VitualStudio2008がインストールされているか確認して下さい。
pause
goto :eof
