all: Fila.o Main.o
	g++ Fila.o Main.o -o Main.exe

Fila.o: Fila.cpp
	g++ -c Fila.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm Main.exe