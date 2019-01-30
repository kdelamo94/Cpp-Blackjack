#ifndef HAND_HPP
#define HAND_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"

using namespace std;

class Hand {

  //Friend Functions
  friend ostream& operator<<(ostream& os, const Hand& hand);

  public:
    
    //Janitor Functions
    Hand();

    //Member Functions
    void addCard(Card* card);
    void flipACard(int index);
    void clear();

    //Constant Member Functions
    int getTotal() const;

  protected:

    //Data Members
    vector<Card*> m_hand;
};

#endif
