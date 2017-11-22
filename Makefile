prog1: main.o Kruskal.o
	g++ -std=c++11 -Wall main.o Kruskal.o -o prog2

main.o: main.cpp
	g++ -c main.cpp

garage.o: Kruskal.cpp Kruskal.h
	g++ -c Kruskal.cpp

clean:
	rm *.o prog2
