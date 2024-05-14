
CXX = clang

compile: playmain

tictactoe.o:
	$(CXX) -c tictactoe.c

playmain.o:
	$(CXX) -c playmain.c

playmain: tictactoe.o playmain.o
	$(CXX) -o playmain tictactoe.o playmain.o -lncurses

clean:
	rm -f *.o
	rm -f playmain
