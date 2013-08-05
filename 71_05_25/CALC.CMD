@echo off

if not exist "%VS90COMNTOOLS%vsvars32.bat" goto missing
call "%VS90COMNTOOLS%vsvars32.bat"
cl CALC.C Polish_Notation.C
del CALC.OBJ Polish_Notation.OBJ
goto :eof

:missing
echo Error: VitualStudio2008がインストールされているか確認して下さい。
pause
goto :eof
