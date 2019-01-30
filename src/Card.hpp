#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

using namespace std;

class Card{

  //Friend Functions
  friend ostream& operator<<(ostream& os, const Card& card);

  public:

    //Global Constants and Enums
    enum Rank {
      ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
      JACK, QUEEN, KING
    };

    enum Suit {
      CLUBS, DIAMONDS, HEARTS, SPADES
    };

    //Janitor Functions
    Card(Rank rank, Suit suit);

    //Member Functions
    void flip();

    //Constant Member Functions
    int getValue() const;

private:

  //Data Members
  Rank m_rank;
  Suit m_suit;
  bool m_isFaceUp;

};

#endif
