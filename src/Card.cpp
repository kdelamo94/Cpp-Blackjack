#include "Card.hpp"

Card::Card(Rank rank, Suit suit){
    m_rank = rank;
    m_suit = suit;
    m_isFaceUp = true;
}

ostream& operator<<(ostream& os, const Card& card){
  string rank;
  string suit;

  const string RANKS[] = {
      "A", "2", "3", "4", "5",
      "6", "7", "8", "9", "10",
      "J", "Q", "K"
  };

  const string SUITS[] = {
    "C", "D", "H", "S"
  };

  if(!card.m_isFaceUp){
    //Not face up, card unknown
    rank = "X";
    suit = "X";
  }else{
    //Face Up, display card

    //Find character representation of rank
    rank = RANKS[card.m_rank - 1];

    //Find character representation of suit
    suit = SUITS[card.m_suit];
  }

  os << rank + suit;
  return os;
}

int Card::getValue() const{

  int value;
  if(!m_isFaceUp){
    value = 0;
  } else if(m_rank > 10){
    value = 10;
  } else {
    value = m_rank;
  }

  return value;
}

void Card::flip(){
  m_isFaceUp = !m_isFaceUp;
}
