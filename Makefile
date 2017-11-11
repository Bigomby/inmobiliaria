BIN=inmobiliaria

all: build clean

main.o:
	g++ -c src/main.cpp

database.o:
	g++ -c src/database/database.cpp

menu.o:
	g++ -c src/menu/menu.cpp

build: main.o database.o menu.o
	g++ main.o database.o menu.o -o $(BIN)

clean:
	rm -f *.o
