CC = g++
CFLAGS = -std=c++20 -g -pedantic -Wall -Wextra

all: main

main: main.o GeneratorWeek.o GeneratorVisitor.o GeneratorWeather.o GeneratorDayTime.o Visitor.o	
	$(CC) $(CFLAGS) main.o GeneratorWeek.o GeneratorVisitor.o GeneratorWeather.o GeneratorDayTime.o Visitor.o -o main -lsimlib -lm

main.o:
	$(CC) $(CFLAGS) -c src/main.cpp -o main.o -lsimlib -lm

GeneratorWeek.o:
	$(CC) $(CFLAGS) -c src/GeneratorWeek.cpp -o GeneratorWeek.o -lsimlib -lm

GeneratorVisitor.o:
	$(CC) $(CFLAGS) -c src/GeneratorVisitor.cpp -o GeneratorVisitor.o -lsimlib -lm

GeneratorWeather.o:
	$(CC) $(CFLAGS) -c src/GeneratorWeather.cpp -o GeneratorWeather.o -lsimlib -lm

GeneratorDayTime.o:
	$(CC) $(CFLAGS) -c src/GeneratorDayTime.cpp -o GeneratorDayTime.o -lsimlib -lm

Visitor.o:
	$(CC) $(CFLAGS) -c src/Visitor.cpp -o Visitor.o -lsimlib -lm

zip:
	tar -czvf TODO.tar Makefile src/

clean:
	rm -f *.o main

run: main
	./main
