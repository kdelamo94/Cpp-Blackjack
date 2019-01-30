#include "Deck.hpp"

Deck::Deck(){
  m_hand.reserve(52);
  populate();
  shuffle();
}

void Deck::populate(){
    int rank;
    int suit;
    for(rank = Card::ACE; rank != Card::KING; rank = static_cast<Card::Rank>(rank + 1)){
      for(suit = Card::CLUBS; suit != Card::SPADES; suit = suit + 1){
        m_hand.push_back(new Card(
          static_cast<Card::Rank>(rank),
          static_cast<Card::Suit>(suit)
        ));
      }
    }
}

void Deck::shuffle(){
  srand(static_cast<unsigned int>(time(0)));

  vector<Card *>::iterator myIter;
  vector<Card *>::iterator randIter;

  for(myIter = m_hand.begin(); myIter != m_hand.end() - 1; myIter++){
    randIter = myIter + (rand() % (m_hand.end() - myIter - 1)) + 1;
    Card* temp = (*randIter);
    (*randIter) = (*myIter);
    (*myIter) = temp;
  }

}

Card* Deck::deal(){
  Card* topCard = m_hand[m_hand.size() - 1];
  m_hand.pop_back();
  return topCard;
}
