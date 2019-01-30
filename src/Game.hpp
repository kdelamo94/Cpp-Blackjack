#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "House.hpp"
#include "Deck.hpp"

class Game{
public:
  //Janitor Functions
  Game();

  //Member Functions
  void play();

protected:
  //Data Members
  House house;
  Deck deck;
  vector<Player> players;

};

#endif
