all:test.out
test.out: population.o prey.o predator.o main.cpp
	g++ -o test.out -Wall population.o prey.o predator.o main.cpp 

population.o: population.cpp population.h
	g++ -o population.o -c -Wall population.cpp

prey.o: prey.cpp prey.h
	g++ -o prey.o -c -Wall prey.cpp

predator.o: predator.cpp predator.h
	g++ -o predator.o -c -Wall predator.cpp

bwindow.o: bwindow.cpp bwindow.h
	g++ -o bwindow.o -c bwindow.cpp

clean: 
	rm *.o 
	rm *.out

