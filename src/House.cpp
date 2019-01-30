#include "House.hpp"

House::House(const string& name):
  GenericPlayer(name)
{}

void House::flipFirst(){
  m_hand.flipACard(0);
}

bool House::isHitting() const{

  bool isHitting = true;

  if(m_hand.getTotal() > 16){
      isHitting = false;
  }

  return isHitting;
}
