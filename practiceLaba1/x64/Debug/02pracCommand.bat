cd "H:\visual studio\practiceLaba1\x64\Debug"
practiceLaba1.exe < 02-alignment.input.txt > 02output.txt 2>NUL
fc /N 02-alignment.expected.txt 02output.txt || pause
pause
