all: main
	rm *.o

main: parse dataa print solution main.cpp
	g++ -o output parse.o data.o print.o solution.o main.cpp

parse: class/parse.cpp
	g++ -c -o parse.o class/parse.cpp

dataa: class/data.cpp
	g++ -c -o data.o class/data.cpp

print: class/print.cpp
	g++ -c -o print.o class/print.cpp

solution: class/solution.cpp
	g++ -c -o solution.o class/solution.cpp

clean:
	rm *.o