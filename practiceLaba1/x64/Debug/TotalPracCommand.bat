cd C:\Users\RedmiBook Pro\source\repos\practiceLaba1\x64\Debug
practiceLaba1.exe < 01-example.input.txt > 01output.txt 2>NUL
fc /N 01-example.expected.txt 01output.txt || pause

cd C:\Users\RedmiBook Pro\source\repos\practiceLaba1\x64\Debug
practiceLaba1.exe < 02-alignment.input.txt > 02output.txt 2>NUL
fc /N 02-alignment.expected.txt 02output.txt || pause

cd C:\Users\RedmiBook Pro\source\repos\practiceLaba1\x64\Debug
practiceLaba1.exe < 03-scaling.input.txt > 03output.txt 2>NUL
fc /N 03-scaling.expected.txt 03output.txt || pause
pause


