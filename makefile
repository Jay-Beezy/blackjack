run: main.o blackjack.o deck.o card.o
	g++ -std=c++11 -g -Wall main.o blackjack.o deck.o card.o -o run

main.o: main.cpp blackjack.h
	g++ -std=c++11 -g -Wall -c main.cpp

blackjack.o: blackjack.h blackjack.cpp
	g++ -std=c++11 -g -Wall -c blackjack.cpp

card.o: card.h card.cpp
	g++ -std=c++11 -g -Wall -c card.cpp

deck.o: deck.h deck.cpp
	g++ -std=c++11 -g -Wall -c deck.cpp

clean:
	rm *.o run
