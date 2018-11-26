all: Fila.o Arquivo.o Usuario.o Main.o
	g++ Fila.o Arquivo.o Usuario.o Main.o -o Main.exe

Fila.o: Fila.cpp
	g++ -c Fila.cpp

Usuario.o: Usuario.cpp
	g++ -c Usuario.cpp

Arquivo.o: Arquivo.cpp
	g++ -c Arquivo.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm Main.exe