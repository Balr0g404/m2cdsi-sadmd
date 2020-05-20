all: main
	rm *.o

main: parse data main.cpp
	g++ -o output data.o parse.o main.cpp

data: class/data.cpp
	g++ -c -o data.o class/data.cpp

parse:
	g++ -c -o parse.o class/parse.cpp

clean:
	rm *.o