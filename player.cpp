//player.cpp


#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <vector>

using namespace std;
   
   Player::Player() { // default player if no player is entered.

      unsigned int currentTime =  (unsigned)time(0); // will be used for shuffly feature.
      srand(currentTime);  //seed the random number generator
      myName = "XxBotGodxX";

   }
    
   void Player::addCard(Card c) { //adds a card to the hand

      
      myHand.push_back(c); // card c is put at end of vector.

   }

   void Player::bookCards(Card c1, Card c2) { // adds two cards to book. at end of vector.

      myBook.push_back(c1);
      myBook.push_back(c2);

   }
   
   bool Player::checkHandForBook(Card &c1, Card &c2) {

      int length = myHand.size(); // if 2 elemments in vector, return value 2.

      if (length <= 1) { // cant have a pair if there is one or less cards.

         return false;

      }

      for (int i = 0; i < length - 1; i++) { // loops will run through each card in the vector 

         for (int j = i + 1; j < length; j++) { // should stop right at end of vector, and begin one index ahead of i index each outer loop.

            if ((myHand[i]).getRank() == (myHand[j]).getRank()) { // gotta compare the ranks. if equal then return the pairs into c1 and c2.

               c1 = myHand[i];
               c2 = myHand[j];

               return true;

            }

         }

      }

               return false;
  
   }

//   bool Player::rankInHand(Card c) const {

      //already wrote out this function in checkhandforbook and dont think i will use it anywhere else.

//   }

   Card Player::chooseCardFromHand() const {
      
      int length = myHand.size(); // gets the size of hand so we can use % for rand gen.
      long choose = (rand() % length); // num between 0 and n -1 cards. index for hand vector to return card.

      return myHand[choose];

   }

   bool Player::cardInHand(Card c) const { 

      int length = myHand.size(); // if 2 elemments in vector, return value 2.

      if (length < 1) { // cant have the card if there are 0 cards in hand.

         return false;

      }

      for (int i = 0; i < length; i++) { // should stop right at end of vector, 

         if ((myHand[i]).getRank() == c.getRank()) { // gotta compare the ranks. 

            return true;

         }

      }
   
      return false;   

   }

   Card Player::removeCardFromHand(Card c) {
// precondition is that the card has to be confirmed to be in there first.
    
      int length = myHand.size(); // if 2 elemments in vector, return value 2.

      for (int i = 0; i < length; i++) { // should stop right at end of vector, 

         if ((myHand[i]).getRank() == c.getRank()) { // gotta compare the ranks and suits. 

            Card saveCard = myHand[i]; // save from vector to return it.
            myHand.erase(myHand.begin() + i); // delete the card from vector.

            return saveCard; // return deleted card so it can be added to other persons hand and then booked.

         }

      }

   }

   string Player::showHand() const {

      int length = myHand.size(); // if 2 elemments in vector, return value 2.

      if (length < 1) { // cant have the card if there are 0 cards in hand.

         return "";

      }

      string strTotal;

      for (int i = 0; i < length; i++) { // should stop right at end of vector, 

         string strCard = myHand[i].toString();
         strTotal = strTotal + strCard + " "; // hopefully this will make it 4c 4d 6h etc...

      }

      return strTotal;

   }

   string Player::showBooks() const {

      int length = myBook.size(); // if 2 elemments in vector, return value 2.

      if (length < 1) { // cant have the card if there are 0 cards in hand.

         return "";

      }

      string strTotal;

      for (int i = 0; i < length; i++) { // should stop right at end of vector, 

         string strCard = myBook[i].toString();
         strTotal = strTotal + strCard + " "; // hopefully this will make it 4c 4d 6h etc...

      }

      return strTotal;

   }
    
   int Player::getHandSize() const {

      return myHand.size();

   }
  
   int Player::getBookSize() const {

      return myBook.size();

   }

//   bool Player::checkHandForPair(Card &c1, Card &c2) {



//   }

//   bool Player::sameRankInHand(Card c) const { 



//   }




