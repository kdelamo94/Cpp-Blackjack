
#Variables
CFLAGS = -O
CC = g++

#Commands
blackjack: Card.o Hand.o Deck.o GenericPlayer.o House.o Player.o Game.o main.o
	$(CC) $(CFLAGS) -o blackjack Card.o Hand.o Deck.o GenericPlayer.o House.o Player.o Game.o main.o

Card.o: Card.cpp
	$(CC) $(CFLAGS) -c Card.cpp

Hand.o: Hand.cpp
	$(CC) $(CFLAGS) -c Hand.cpp

Deck.o: Deck.cpp
	$(CC) $(CFLAGS) -c Deck.cpp

GenericPlayer.o: GenericPlayer.cpp
	$(CC) $(CFLAGS) -c GenericPlayer.cpp

House.o: House.cpp
	$(CC) $(CFLAGS) -c House.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -r *.o

debug: Card.cpp Hand.cpp Deck.cpp GenericPlayer.cpp House.cpp Player.cpp Game.cpp main.cpp
	$(CC) $(CFLAGS) -g -o blackjack-db Card.cpp Hand.cpp Deck.cpp GenericPlayer.cpp House.cpp Player.cpp Game.cpp main.cpp
