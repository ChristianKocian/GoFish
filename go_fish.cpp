// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main( ) {
    
   int numCards = 7;

   Player p1("Joe");
   Player p2("Jane");
   
   Deck d;  //create a deck of cards
   d.shuffle();
   
   dealHand(d, p1, numCards);
   dealHand(d, p2, numCards);
   
   cout << p1.getName() <<" has : " << p1.showHand() << endl;
   cout << p2.getName() <<" has : " << p2.showHand() << endl;
  
   Card c1;
   Card c2; 
   Card currentCard;   
   Card switchCard;
   int playersTurn;

   while (d.size() > 0 && p1.getHandSize() > 0 && p2.getHandSize() > 0) { // keep looping game until deck and hands are empty, meaning all pairs have been made.
// player 1 turn first.

      do { 

         currentCard = p1.chooseCardFromHand(); // picks a card to ask from opponent.
         playersTurn == 0; // will fall out of loop unless cards are paired.

         if (p2.cardInHand(currentCard)) { // player 2 checks for the card that player one chooses.
         
            switchCard = p2.removeCardFromHand(currentCard); // removes the card from player 2.

            p1.addCard(switchCard); // player 1 gets the new card.

            if (p1.checkHandForBook(c1, c2)) { // makes sure there is a pair to book.

               p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
            }

         }   

         playersTurn == 1; // repeats the turn.

      } while (playersTurn == 1); 

      if(p2.cardInHand(currentCard) == false || p1.getHandSize() == 0) {
         
         p1.addCard(d.dealCard()); // draw a card if you have no cards in hand, or if no book found.
      
      }
// player 2 turn.      
      do { 

         currentCard = p2.chooseCardFromHand(); // picks a card to ask from opponent.
         playersTurn == 0; // will fall out of loop unless cards are paired.

         if (p1.cardInHand(currentCard)) { // player 1 checks for the card that player one chooses.
         
            switchCard = p1.removeCardFromHand(currentCard); // removes the card from player 1.

            p2.addCard(switchCard); // player 2 gets the new card.

            if (p2.checkHandForBook(c1, c2)) { // makes sure there is a pair to book.

               p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
            }

         }   

         playersTurn == 1; // repeats the turn.

      } while (playersTurn == 1); 

      if(p1.cardInHand(currentCard) == false || p2.getHandSize() == 0) {
         
         p2.addCard(d.dealCard()); // draw a card if you have no cards in hand, or if no book found.
      
      }

   }
   
   if (p1.getBookSize() > p2.getBookSize()) { // if p1 has more books.

      cout << p1.getName() << " Wins!" << endl; 

   }

   if (p1.getBookSize() < p2.getBookSize()) { // if p2 has more books

      cout << p2.getName() << " Wins!" << endl; 

   }
 
   if (p1.getBookSize() == p2.getBookSize()) { // if draw

      cout << p1.getName() << " and " << p2.getName() << " Tie!" << endl; 

   }

   return EXIT_SUCCESS;  

}



void dealHand(Deck &d, Player &p, int numCards) {
   
   for (int i=0; i < numCards; i++) {
     
      p.addCard(d.dealCard());

   }

}
   



