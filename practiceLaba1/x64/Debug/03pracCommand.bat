cd "H:\visual studio\practiceLaba1\x64\Debug"
practiceLaba1.exe < 03-scaling.input.txt > 03output.txt 2>NUL
fc /N 03-alignment.expected.txt 03output.txt || pause
pause
