#include "Player.hpp"

using namespace std;

Player::Player(const string& name):
  GenericPlayer(name)
{}

bool Player::isHitting() const {
  string response;

  while(true){

    cout << m_name << ", would you like a hit (y/n)? ";
    cin >> response;

    if(response == "y"){
      //Player wants a hit
      return true;
    } else if(response == "n"){
      //Player does not want a hit
      return false;
    } else {
      cout << "Not a valid choice!" << endl;
    }
  }
}

void Player::win() const{
  cout << m_name << " wins." << endl;
}

void Player::lose() const{
  cout << m_name << " loses." << endl;
}

void Player::pushed() const{
  cout << m_name << " pushes." << endl;
}
