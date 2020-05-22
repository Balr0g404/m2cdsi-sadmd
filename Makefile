all: main
	rm *.o

main: parse data print main.cpp
	g++ -o output data.o parse.o print.o main.cpp

data: class/data.cpp
	g++ -c -o data.o class/data.cpp

parse:
	g++ -c -o parse.o class/parse.cpp

print:
	g++ -c -o print.o class/print.cpp

clean:
	rm *.o