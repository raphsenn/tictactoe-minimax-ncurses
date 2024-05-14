
CXX = clang

compile: playmain

tictactoe.o: tictactoe.c tictactoe.h
	$(CXX) -c tictactoe.c

playmain.o: playmain.c tictactoe.h
	$(CXX) -c playmain.c

playmain: tictactoe.o playmain.o
	$(CXX) -o playmain tictactoe.o playmain.o -lncurses

run:
	./playmain

clean:
	rm -f *.o
	rm -f playmain
