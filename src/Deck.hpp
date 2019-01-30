#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Card.hpp"
#include "Hand.hpp"

class Deck : public Hand{
  public:

    //Janitor Functions
    Deck();

    //Member Functions
    Card* deal();

  private:

    //Utility Member Functions
    void populate();
    void shuffle();

};

#endif
