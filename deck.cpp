//deck.cpp 

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include <vector>

using namespace std;

   Deck::Deck() { // pristine, sorted deck

      unsigned int currentTime =  (unsigned)time(0); // will be used for shuffly feature.
      srand(currentTime);  //seed the random number generator

      int k = 0;

      for(int rank = 1; rank < 14; rank++) { // creates the 13 ranks of cards per suit.

         for (int suit = 0; suit < 4; suit++) { // creates the suit of 4 types

            Card c(rank, Card::Suit(suit));
            myCards[k] = c; // should create 52 cards from rank 1 to 13.
            k++; // k from 0 to 51 = 52 total.

         }

      }

      myIndex = 0;

   }

   void Deck::shuffle() { // shuffle the deck, all 52 cards present
// interpretation that shuffle resets the deck - not deleting the cards so just reset the index to 0 and begin shuffling.
      myIndex = 0;
  
      for (int i = 0; i < (2 * SIZE); i++) { // repeat grabbing random numbers until process done twice as many times as there are cards.
      
         long index1 = (rand() % SIZE); // gets two random numbers between 0 and total number of nodes. swap the contents of the nodes corresponding to these random numbers.
         long index2 = (rand() % SIZE);

         Card tempCard;

         tempCard = myCards[index2]; // swaps the two cards determinded by rand num indexes in array.
         myCards[index2] = myCards[index1];
         myCards[index1] = tempCard;

      }

   }

   Card Deck::dealCard() { // get a card, after 52 are dealt, fail 
// precondition: the function will not be called when there are no cards left, since the return type must be a card. 
// thus always add an if statement checking the size of the deck remaining, and comparing it to max size or 0 left.
         Card drawCard = myCards[myIndex]; //since index of deck starts at 0, we will pop then increment.
         myIndex ++;

         return drawCard;

   }

   int  Deck::size() const { // # cards left in the deck

      int remainingCards = SIZE - (myIndex + 1); // total cards minus number dealt. plus one bc it started at 0 not 1 index.
      return remainingCards;

   }




