#include "Hand.hpp"
#include "GenericPlayer.hpp"

GenericPlayer::GenericPlayer(const string& name){
  m_name = name;
  cout << m_hand;
}

void GenericPlayer::addCard(Card* card){
  m_hand.addCard(card);
}

bool GenericPlayer::isBusted()const{
  return (m_hand.getTotal() > 21);
}

void GenericPlayer::bust() const{
  cout <<  m_name << " busted!" << endl;
}

int GenericPlayer::getTotal() const{
  return m_hand.getTotal();
}

ostream& operator<<(ostream& os, const GenericPlayer& gPlayer){
  cout << gPlayer.m_name << ":\t" << gPlayer.m_hand;
}
