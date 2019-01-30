#include "Game.hpp"

Game::Game()
{}

void Game::play(){
  //Ask how many players
  int playerCount;
  bool validInput = false;
  while(!validInput){

    cout << "How many players? (1 - 7): ";
    cin >> playerCount;
    cout << endl;

    if(playerCount >= 1 && playerCount <= 7){
      //Player count is valid
      validInput = true;
    }else{
      //Player count is not valid
      cout << "Please input an appropriate number!" << endl;
    }

    cout << endl;
  }


  //For the number of players, get their name, add them to the Game
  for(int i = 0; i < playerCount; i++){
    string input;

    cout << "Enter this players name (A default will be provided if blank): ";
    cin >> input;
    cout << endl;

    Player player(input);
    players.push_back(player);

  }

  //Deal out 2 cards per player, plus the house.
  house.addCard(deck.deal());
  house.addCard(deck.deal());

  vector<Player>::iterator pIter;
  for(pIter = players.begin(); pIter != players.end(); pIter++){
    (*pIter).addCard(deck.deal());
    (*pIter).addCard(deck.deal());
  }

  //Hide the houses first cards
  house.flipFirst();

  //Display the cards

  for(pIter = players.begin(); pIter != players.end(); pIter++){
    cout << (*pIter) << endl;
  }
  cout << house << endl;
  cout << endl;

  //For each player, ask them for hits, until they no longer want or bust
  for(pIter = players.begin(); pIter != players.end(); pIter++){
    Player& player = (*pIter);

    //Ask for hit
    while(!player.isBusted()&&player.isHitting()){
      player.addCard(deck.deal());
      cout << player << endl;
    }

    if(player.isBusted()){
      player.bust();
    }
    cout << endl;
  }

  //reveal the houses cards
  house.flipFirst();
  cout << house << endl;

  //while the house is hitting and is not busting, give it cards
  while(!house.isBusted()&&house.isHitting()){
    house.addCard(deck.deal());
    cout << house << endl;
  }

  if(house.isBusted()){
    house.bust();
  }
  
  cout << endl;

  //The house busts
  if(house.isBusted()){
    //All none busting players win
    for(pIter = players.begin(); pIter != players.end(); pIter++){
      Player& player = (*pIter);

      if(player.isBusted()){
        //player busted, they lose
        player.lose();
      }else{
        //player not busted, they win
        player.win();
      }
    }
  } else {
    //The house did not bust
    for(pIter = players.begin(); pIter != players.end(); pIter++){

      Player& player = (*pIter);

      if(!player.isBusted()){
        //player did not bust
        if(player.getTotal() < house.getTotal()){
          //player has smaller total than the house, they lose
          player.lose();
        } else if(player.getTotal() == house.getTotal()) {
          //player has total equal to the house, they push
          player.pushed();
        }
      }else{
        //player busted, they lose
        player.lose();
      }
    }
  }

}
