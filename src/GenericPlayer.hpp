#ifndef GENPL_HPP
#define GENPL_HPP

#include "Card.hpp"
#include "Hand.hpp"

class GenericPlayer{

  //Friend Functions
  friend ostream& operator<<(ostream& os, const GenericPlayer& gPlayer);

public:

  //Janitor Functions
  GenericPlayer(const string& name = "");

  //Member Functions
  void addCard(Card* card);

  //Constant Member Functions
  bool isBusted() const;
  void bust() const;
  int getTotal() const;

  //Pure Virtual Functions (Abstract Functions)
  virtual bool isHitting() const = 0;

protected:

  //Data Members
  Hand m_hand;
  string m_name;
  
};

#endif
