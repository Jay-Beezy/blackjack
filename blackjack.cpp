/*--------------------------------------------------------------
 *
 *@file: blackjack.cpp
 *@author: Jake Beesley
 *@assignment: EECS-448 project 4
 *@description: Contains the implementation for the blackjack program
 *
 --------------------------------------------------------------*/


#include <iostream>
#include "blackjack.h"

//Runs the blackjack game
void blackjack::run(){
  establishPlayerMoney();
  blackjackGame();
}

//The full implementation of the blackjack game
void blackjack::blackjackGame(){

  char gameContinuation;
  char userInput;

  superShuffle();
  initializeHands();
  establishPlayerWager();

  std::cout << "\n\n~~~~~ House hits on a 16 ~~~~~\n\n";

  dealerHand[0] = myDeck.nextCard();
  playerHand[0] = myDeck.nextCard();
  dealerHand[1] = myDeck.nextCard();
  playerHand[1] = myDeck.nextCard();

  std::cout << "House's hand : \t";
  std::cout << dealerHand[0].print() << "\n";
  std::cout << "and \t\t| ** of ** | \n\n";
  std::cout << "House's current value : " << dealerHand[0].getValue() << " + ??\n\n";

  std::cout << "You have been dealt a: \t";
  std::cout << playerHand[0].print() << "\n";
  std::cout << "\t\t\t" << playerHand[1].print() << "\n\n";

  playerValue = playerHand[0].getValue() + playerHand[1].getValue();

  if(playerValue == 22){
    std::string sameSuit = playerHand[0].getSuit();
    playerHand[0] = myDeck.dealSpecialAce(sameSuit);
    playerValue = playerHand[0].getValue() + playerHand[1].getValue();
  }

  std::cout << "Your hand's current value is : " << playerValue  << "\n\n";

  do{
    std::cout << "Do you want to hit or stay? (h/s): ";
    std::cin >> userInput;
    if(userInput == 'h'){
      dealPlayer();
      if(playerWillBust() == true){
        playerAceChecker();
      }
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
    removeWager();
  }
  else{
    std::cout << "The house's first card was a : ";
    std::cout << dealerHand[0].print() << "\n";
    std::cout << "The house's second card was a : ";
    std::cout << dealerHand[1].print() << "\n";
    if(dealerWillBust() == true){
      dealerAceChecker();
    }
    houseValue = dealerHand[0].getValue() + dealerHand[1].getValue();
    std::cout << "House's current value : " << generateHouseValue() << "\n\n";
    if(houseValue < 17){
      do{
        if(houseValue < 17 || houseValue < playerValue){
          dealHouse(); //deals to the house untill it busts or hits 17+ < 21
        }
        else{
          break;
        }
      }while(houseValue < 17 || houseValue < playerValue);
    }
    if(houseValue > 21){
      dealerAceChecker();
      endGame(); //Reveal both player's values, determine winner
    }
    else{
      endGame(); //Reveal both player's values, determine winner
    }
  }

  if(playerMoney != 0){
    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> gameContinuation;
    if(gameContinuation == 'y'){
      system("clear");
      blackjackGame();
    }
    else if(gameContinuation == 'n' || playerMoney == 0){
      std::cout << "\n\nThanks for playing! \n";
      std::cout << "You ended with a total of : " << playerMoney << "\n\n";
    }
    else{
      std::cout << "\n\nThanks for playing! \n";
      std::cout << "You ended with a total of : " << playerMoney << "\n\n";
    }
  }
  else{
    std::cout << "Would you like to play a new game? (y/n): ";
    std::cin >> gameContinuation;
    if(gameContinuation == 'y'){
      system("clear");
      run();
    }
    else{
      std::cout << "\n\nThanks for playing! \n";
      std::cout << "You ended with a total of : " << playerMoney << "\n\n";
    }
  }
}

//Shuffles the deck 100 times
void blackjack::superShuffle(){
  for(int i = 0; i < 100; i++){
    myDeck.shuffle();
  }
}

//Sets each card in each hand to an empty card
void blackjack::initializeHands(){
  for(int i = 0; i < maximumCards; i++){
    playerHand[i] = myDeck.dealEmptyCard();
    dealerHand[i] = myDeck.dealEmptyCard();
  }
}

//Tester function that outputs the information of each hand
void blackjack::printHands(){
  for(int i = 0; i < maximumCards; i++){
    std::cout << "Player Card Number : " << i << " " << playerHand[i].print() << "\n";
    std::cout << "House Card Number : " << i << " " << dealerHand[i].print() << "\n";
  }
}

//Deals a card to the player
void blackjack::dealPlayer(){
  for(int i = 1; i <= maximumCards; i++){
    if(playerHand[i+1] == myDeck.dealEmptyCard()){
      playerHand[i+1] = myDeck.nextCard();
      break;
    }
  }

  std::cout << "\nYou have been dealt a: \t";

  for(int j = 1; j < maximumCards; j++){
    if(playerHand[j+1] == myDeck.dealEmptyCard()){
      std::cout << playerHand[j].print() << "\n";
      break;
    }
  }

  playerValue = 0;
  for(int k = 0; k < maximumCards; k++){
    playerValue = playerValue + playerHand[k].getValue();
  }
  if(playerValue > 21){
    playerAceChecker();
  }
  std::cout << "Value of your hand : " << playerValue << "\n\n";
}

//Deals a card to the house
void blackjack::dealHouse(){
  for(int i = 0; i < maximumCards; i++){
    if(dealerHand[i] == myDeck.dealEmptyCard()){ //index 0 and index 1 should be auto skipped, due to dealerStart
      dealerHand[i] = myDeck.nextCard();
      break;
    }
  } 
  std::cout << "\nHouse has been dealt a: \t";

  for(int j = 1; j < maximumCards; j++){
    if(dealerHand[j+1] == myDeck.dealEmptyCard()){
      std::cout << dealerHand[j].print() << "\n";
      break;
    }
  }
  dealerAceChecker();
  std::cout << "Value of house's hand : " << generateHouseValue() << "\n\n";
}

//Generates the value of the house's hand
int blackjack::generateHouseValue(){
  houseValue = 0;
  for(int i = 0; i < maximumCards; i++){
    houseValue = houseValue + dealerHand[i].getValue();
  }
  return(houseValue);
}

//Check if there is an ace in the player's hand
void blackjack::playerAceChecker(){
  for(int i = 0; i < maximumCards; i++){
    if(playerHand[i].getValue() == 11){
      std::string sameSuit = playerHand[i].getSuit();
      playerHand[i] = myDeck.dealSpecialAce(sameSuit);
      break;
    }
  }
  playerValue = 0;
  for(int k = 0; k < maximumCards; k++){
    playerValue = playerValue + playerHand[k].getValue();
  }
}

//Check if there is an ace in the dealer's hand
void blackjack::dealerAceChecker(){
  for(int i = 0; i < maximumCards; i++){
    if(dealerHand[i].getValue() == 11){
      std::string sameSuit = dealerHand[i].getSuit();
      dealerHand[i] = myDeck.dealSpecialAce(sameSuit);
      break;
    }
  }
}

//Determines the winner of the blackjack game
void blackjack::endGame(){
  std::cout << "House's current value : " << houseValue << "\n";
  std::cout << "Your current value : " << playerValue << "\n\n";
  if(playerValue > houseValue || houseValue > 21){
    std::cout << "You won! \n\n";
    rewardWager();
  }
  else if(houseValue > playerValue){
    std::cout << "You lost! \n\n";
    removeWager();
  }
  else{
    std::cout << "You both tied! \n\n";
  }  
}

//Set the value of the player's money
void blackjack::establishPlayerMoney(){
  system("clear");

  std::cout << "\n\nWelcome to Blackjack!\n\n";

  std::cout << "How much money would you like to start with?\n";
  std::cout << "Enter amount : ";
  std::cin >> playerMoney;
  while(std::cin.fail() || playerMoney <= 0){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a valid starting amount : ";
    std::cin >> playerMoney;
  }
  std::cout << "\n";
}

//Set the value of the player's wager
void blackjack::establishPlayerWager(){
  std::cout << "Your current total is : " << playerMoney << "\n";
  std::cout << "How much would you like to wager for the upcoming hand?\n";
  std::cout << "Enter amount : ";
  std::cin >> playerWager;
  while(std::cin.fail() || playerWager <= 0 || playerWager > playerMoney){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a valid wager : ";
    std::cin >> playerWager;
  }
  system("clear");
}

//Reward the player's wager to their money
void blackjack::rewardWager(){
  playerMoney = playerMoney + playerWager;
  std::cout << "You won : " << playerWager << "\n";
  std::cout << "You're current total is : " << playerMoney << "\n\n";
}

//Remove the player's wager from their money
void blackjack::removeWager(){
  playerMoney = playerMoney - playerWager;
  std::cout << "You lost : " << playerWager << "\n";
  std::cout << "You're current total is : " << playerMoney << "\n\n";
}

//Checks if the player is going to bust on the next card
bool blackjack::playerWillBust(){
  int futureValue = myDeck.peekNextCard().getValue();
  if(futureValue + playerValue > 21){
    return(true);
  }
  else{
    return(false);
  }
}

//Checks if the dealer is going to bust on the next card
bool blackjack::dealerWillBust(){
  int futureValue = myDeck.peekNextCard().getValue();
  if(futureValue + houseValue > 21){
    return(true);
  }
  else{
    return(false);
  }
}