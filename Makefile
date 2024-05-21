
CXX = clang++

compile: main

tictactoe.o: tictactoe.cpp tictactoe.h
	$(CXX) -c tictactoe.cpp

terminalmanager.o: terminalmanager.h
	$(CXX) -c terminalmanager.cpp

main.o: main.cpp tictactoe.h terminalmanager.h
	$(CXX) -c main.cpp

main: tictactoe.o main.o terminalmanager.o
	$(CXX) -o main tictactoe.o terminalmanager.o main.o -lncurses

run:
	./main

clean:
	rm -f *.o
	rm -f main