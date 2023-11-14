CC = g++
CFLAGS = -std=c++20 -g -pedantic -Wall -Wextra

all: main

main: main.o GeneratorWeek.o GeneratorVisitor.o GeneratorWeather.o GeneratorDayTime.o Slope.o Visitor.o	GeneratorFailure.o Repair.o Skilift.o CableCar.o Statistics.o
	$(CC) $(CFLAGS) main.o GeneratorWeek.o GeneratorVisitor.o GeneratorWeather.o GeneratorDayTime.o Slope.o Visitor.o GeneratorFailure.o Repair.o Skilift.o CableCar.o Statistics.o -o main -lsimlib -lm

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

Slope.o:
	$(CC) $(CFLAGS) -c src/Slope.cpp -o Slope.o -lsimlib -lm

Visitor.o:
	$(CC) $(CFLAGS) -c src/Visitor.cpp -o Visitor.o -lsimlib -lm

GeneratorFailure.o:
	$(CC) $(CFLAGS) -c src/GeneratorFailure.cpp -o GeneratorFailure.o -lsimlib -lm

Repair.o:
	$(CC) $(CFLAGS) -c src/Repair.cpp -o Repair.o -lsimlib -lm

Skilift.o:
	$(CC) $(CFLAGS) -c src/Skilift.cpp -o Skilift.o -lsimlib -lm

CableCar.o:
	$(CC) $(CFLAGS) -c src/CableCar.cpp -o CableCar.o -lsimlib -lm

Statistics.o:
	$(CC) $(CFLAGS) -c src/Statistics.cpp -o Statistics.o -lsimlib -lm

zip:
	tar -czvf TODO.tar Makefile src/

clean:
	rm -f *.o main

run: main
	./main
