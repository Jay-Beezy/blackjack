/*--------------------------------------------------------------
 *
 *@file: blackjack.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 3
 *@description: Contains the implementation for the blackjack program
 *
 --------------------------------------------------------------*/


#include <iostream>
#include "blackjack.h"

//Runs the blackjack game
void blackjack::run(){
  blackjackGame();
}

//The full implementation of the blackjack game
void blackjack::blackjackGame(){

  char gameContinuation;
  char userInput;

  superShuffle();
  initializeHands();

  std::cout << "\n\nWelcome to Blackjack!\n\n";
  std::cout << "House hits on a 16\n\n";

  dealerStart(); //Dealer gets dealt two cards


  playerStart(); //Player gets dealt two cards

  do{
    std::cout << "Do you want to hit or stay? (h/s): ";
    std::cin >> userInput;
    if(userInput == 'h'){
      dealPlayer();
    }
    else if(userInput == 's'){
      system("clear");
      break;
    }
    else{
      std::cout << "Invalid input! Try again. \n";
    }
  }while(playerValue < 21);

  if(playerValue > 21){
    playerAceChecker();
    std::cout << "You busted! \n\n";
  }
  else{
    std::cout << "The house's first card was a : ";
    std::cout << houseArray[0].print() << "\n";
    std::cout << "The house's second card was a : ";
    std::cout << houseArray[1].print() << "\n";
    houseValue = houseArray[0].getValue() + houseArray[1].getValue();
    std::cout << "House's current value : " << houseValue << "\n\n";

    dealHouse(); //deals to the house untill it busts or hits 17+ < 21

    std::cout << "House's current value : " << houseValue << "\n";
    std::cout << "Your current value : " << playerValue << "\n\n";
    if(playerValue > houseValue || houseValue > 21){
      std::cout << "You won! \n\n";
    }
    else if(houseValue > playerValue){
      std::cout << "You lost! \n\n";
    }
    else{
      std::cout << "You both tied! \n\n";
    }
  }

  std::cout << "Would you like to play again? (y/n): ";
  std::cin >> gameContinuation;
  if(gameContinuation == 'y'){
    system("clear");
    blackjackGame();
  }
  else if(gameContinuation == 'n'){
    std::cout << "Thanks for playing! \n";
  }
  else{
    std::cout << "Thanks for playing! \n";
  }
}

void blackjack::superShuffle(){
  myDeck.shuffle();
  myDeck.shuffle();
  myDeck.shuffle();
  myDeck.shuffle();
}

void blackjack::AceTester(){
  playerArray[0] = myDeck.dealTester();
  for(int i = 0; i < 13; i++){
    myDeck.deal();
  }
  playerArray[1] = myDeck.dealTester();
}

void blackjack::dealerStart(){
  houseArray[0] = myDeck.dealTester();
  myDeck.deal();
  houseArray[1] = myDeck.dealTester();
  myDeck.deal();
  std::cout << "House's hand : \t";
  std::cout << houseArray[0].print() << "\n";
  std::cout << "and \t\t| ** of ** | \n\n";
  std::cout << "House's current value : " << houseArray[0].getValue() << " + ??\n\n";
}

void blackjack::initializeHands(){
  for(int i = 0; i < maximumCards; i++){
    playerArray[i] = myDeck.dealEmptyCard();
    houseArray[i] = myDeck.dealEmptyCard();
  }
}

void blackjack::printHands(){
  for(int i = 0; i < maximumCards; i++){
    std::cout << "Player Card Number : " << i << " " << playerArray[i].print() << "\n";
    std::cout << "House Card Number : " << i << " " << houseArray[i].print() << "\n";
  }
}

void blackjack::playerStart(){
  playerArray[0] = myDeck.dealTester();
  myDeck.deal();
  playerArray[1] = myDeck.dealTester();
  myDeck.deal();


  std::cout << "You have been dealt a: \t";
  std::cout << playerArray[0].print() << "\n";
  std::cout << "\t\t\t" << playerArray[1].print() << "\n\n";

  playerValue = playerArray[0].getValue() + playerArray[1].getValue();

  if(playerValue == 22){
    std::string sameSuit = playerArray[0].getSuit();
    playerArray[0] = myDeck.dealSpecialAce(sameSuit);
    playerValue = playerArray[0].getValue() + playerArray[1].getValue();
  }

  std::cout << "Your current value is : " << playerValue  << "\n\n";
}

void blackjack::dealPlayer(){
  for(int i = 1; i <= maximumCards; i++){
    if(playerArray[i+1] == myDeck.dealEmptyCard()){
      playerArray[i+1] = myDeck.dealTester();
      myDeck.deal();
      break;
    }
  }

  std::cout << "\nYou have been dealt a: \t";

  for(int j = 1; j < maximumCards; j++){
    if(playerArray[j+1] != myDeck.dealEmptyCard()){
      std::cout << playerArray[j+1].print() << "\n";
      break;
    }
  }

  for(int k = 2; k < maximumCards; k++){
    playerValue = playerValue + playerArray[k].getValue();
  }

  std::cout << "Value of your hand : " << playerValue << "\n\n";
}

void blackjack::dealHouse(){
  if(houseValue < 17){
    do{
      for(int i = 1; i <= maximumCards; i++){
        if(houseArray[i+1] == myDeck.dealEmptyCard()){
        houseArray[i+1] = myDeck.dealTester();
        myDeck.deal();
        break;
       }
      } 
      std::cout << "\nHouse has been dealt a: \t";

      for(int j = 1; j < maximumCards; j++){
        if(houseArray[j+1] != myDeck.dealEmptyCard()){
          std::cout << houseArray[j+1].print() << "\n";
          break;
        }
      }

      for(int x = 2; x < maximumCards; x++){
        houseValue = houseValue + houseArray[x].getValue();
      }

      houseAceChecker();

      std::cout << "Value of house's hand : " << houseValue << "\n\n";

    }while(houseValue < 17);
  }
}

void blackjack::playerAceChecker(){
  for(int i = 0; i < maximumCards; i++){
    if(playerArray[i].getValue() == 11){
      std::string sameSuit = playerArray[i].getSuit();
      playerArray[i] = myDeck.dealSpecialAce(sameSuit);
      break;
    }
  }
}

void blackjack::houseAceChecker(){
  for(int i = 0; i < maximumCards; i++){
    if(houseArray[i].getValue() == 11){
      std::string sameSuit = houseArray[i].getSuit();
      houseArray[i] = myDeck.dealSpecialAce(sameSuit);
      break;
    }
  }
}