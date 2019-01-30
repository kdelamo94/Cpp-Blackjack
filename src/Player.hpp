#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "GenericPlayer.hpp"

class Player : public GenericPlayer{
public:
  //Janitor Functions
  Player(const string& name = "");

  //Constant Member Functions
  void win() const;
  void lose() const;
  void pushed() const;

  //Overriden Functions
  virtual bool isHitting() const;

private:
  //Static Member Functions
  static int m_noPlayers;

};

#endif
