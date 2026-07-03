cd "H:\visual studio\practiceLaba1\x64\Debug"
practiceLaba1.exe < 01.input.txt > 01output.txt 2>NUL
fc /N 01-example.expected.txt 01output.txt || pause
pause