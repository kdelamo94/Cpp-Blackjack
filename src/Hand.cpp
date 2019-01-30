#include "Hand.hpp"

//Janitor Functions

/*Constructor*/
/*reserver slots for 5 cards. Most games will need no more cards*/
Hand::Hand(){
  m_hand.reserve(5);
}



//Member Functions

/*Add a card to the hand*/
void Hand::addCard(Card* card){
  m_hand.push_back(card);
}

/*Flip a Card in the hand, given the index of the card in the hand*/
void Hand::flipACard(int index){
  m_hand[index] -> flip();
}

/*Clear all objects from the hand, clear the hand vector itself*/
void Hand::clear(){
  vector<Card*>::iterator iter;

  //delete every pointed to object.
  for(iter = m_hand.begin(); iter != m_hand.end(); iter++){
    delete (*iter);
  }

  //Empty the array of Card pointers
  m_hand.clear();
}


//Constant Member Functions

/*Get the total value of the hand*/
int Hand::getTotal() const{
    int total = 0;
    vector<Card*>::const_iterator iter;

    bool containsAce = false;

    //Sum up cards, also check to see if they have an ACE
    for(iter = m_hand.begin(); iter != m_hand.end(); iter++){
      total += (*iter) -> getValue();
      if(((*iter) -> getValue()) == Card::ACE){
        containsAce = true;
      }
    }

    //If the hand contains an Ace, check if it's beneficial to make ACE 11
    if(containsAce && total <= 11){
      total += 10;
    }

    return total;
}


//Friend functions

/*Output overloading*/
/*Create a function to have a default output for piping to streams*/
ostream& operator<<(ostream& os, const Hand& hand){

  vector<Card*>::const_iterator iter;

  for(iter = hand.m_hand.begin(); iter != hand.m_hand.end(); iter++){
    if(iter == hand.m_hand.end() - 1){
      int total = hand.getTotal();
      os << (*(*iter)) << "\t(" << total << ")";
    } else {
      os << (*(*iter)) << "\t";
    }

  }
      return os;
}
