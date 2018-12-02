all: Fila.o Arquivo.o Usuario.o Main.o
	g++ -Wall -g -std=c++11 -pthread  Fila.o Arquivo.o Usuario.o Main.o -o Main.exe

Fila.o: Fila.cpp
	g++ -Wall -g -std=c++11 -pthread  -c Fila.cpp

Usuario.o: Usuario.cpp
	g++ -Wall -g -std=c++11 -pthread  -c Usuario.cpp

Arquivo.o: Arquivo.cpp
	g++ -Wall -g -std=c++11 -pthread  -c Arquivo.cpp

Main.o: Main.cpp
	g++ -Wall -g -std=c++11 -pthread  -pthread -c Main.cpp

clean:
	rm *.o
	rm Main.exe