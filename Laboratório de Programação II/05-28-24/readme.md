Para compilar o código usar o seguinte comando no cmd:

clear; Remove-Item -Force -Recurse -Path ./output 2>null; mkdir output 2>null; del null; gcc -Wall -o ./output/out.exe main.c filas.c bandejas.c; start ./output/out.exe;