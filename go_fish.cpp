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

   string readwrite;

   ofstream myFile ("gofish_results.txt");

   if (myFile.is_open()) {

      cout << "file opened, game in progress" << endl;
//      getline (cin, readwrite);

//      myFile << readwrite;

   } else {

      cout << "file did not open" << endl;

   }
  
   int numCards = 7;
   Card c1;
   Card c2; //storage for functions to interchange values. all 4 Cards.
   Card currentCard;   
   Card switchCard;
   Card dealtCard;
   int playersTurn;
   bool boolResult;

   Player p1("Joe"); // generic names.
   myFile << "player 1 is: " << p1.getName() << "\n";
   Player p2("Jane");
   myFile << "player 2 is: " << p2.getName() << "\n";
   
   Deck d;  //create a deck of cards and shuffles it.
   d.shuffle();
   myFile << "Deck shuffled and ready to deal\n";
   
   dealHand(d, p1, numCards); // handsize of 7 per player dealt.
   dealHand(d, p2, numCards);
   myFile << "both hands have been dealt!\n";
   
   myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
   myFile << p2.getName() << " has: " << p2.showHand() << "\n";

   myFile << p1.getName() << " books the starting pairs\n";
   myFile << p2.getName() << " books the starting pairs\n";

   while (p1.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.
  
      p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
   }

   while (p2.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.

      p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
   }

   myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
   myFile << p2.getName() << " has: " << p2.showHand() << "\n";
   myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
   myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

   while (d.size() > 0 || p1.getHandSize() > 0 || p2.getHandSize() > 0) { // keep looping game until deck and hands are empty, meaning all pairs have been made.
// player 1 turn first.
      playersTurn = 0;
      myFile << p1.getName() << "'s turn\n";

      do { 

         if (playersTurn == 1) {

            myFile << p1.getName() << " goes again\n";

         }

         if (p1.getHandSize() > 0) {

            currentCard = p1.chooseCardFromHand(); // picks a card to ask from opponent.
            playersTurn = 0; // will fall out of loop unless cards are paired.
            myFile << p1.getName() << " asks - Do you have a " << currentCard.rankString(currentCard.getRank()) << "?\n";

            boolResult = p2.cardInHand(currentCard); // checks for the asked card.

            if (boolResult == true) { // player 2 checks for the card that player one chooses.

               myFile << p2.getName() << " says - Yes. I have a " << currentCard.rankString(currentCard.getRank()) << "\n";
               switchCard = p2.removeCardFromHand(currentCard); // removes the card from player 2.
               p1.addCard(switchCard); // player 1 gets the new card.

//               myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
//               myFile << p2.getName() << " has: " << p2.showHand() << "\n";
//               myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
//               myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

               if (p1.checkHandForBook(c1, c2)) { // makes sure there is a pair to book.

                  myFile << p1.getName() << " books the " << currentCard.rankString(currentCard.getRank()) << "\n";
                  p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
               }

               myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
               myFile << p2.getName() << " has: " << p2.showHand() << "\n";
               myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
               myFile << p2.getName() << " books: " << p2.showBooks() << "\n";
               playersTurn = 1; // repeats the turn.

            }   

         }

      } while (playersTurn == 1 && p1.getHandSize() > 0); 

      if(p1.getHandSize() > 0 && boolResult == false) {
         
         myFile << p2.getName() << " says - Go Fish!\n";

         if (d.size() > 0) {

            dealtCard = d.dealCard();
            p1.addCard(dealtCard); // draw a card if you have no cards in hand, or if no book found.
            myFile << p1.getName() << " draws " << dealtCard.toString() << "\n";

         } else {
 
            myFile << p1.getName() << ": No cards left to draw\n";

         }
      
      }
      
      while (p1.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.
  
         p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
      }

//      myFile << p1.getName() << " has: " << p1.showHand() << "\n";
//      myFile << p2.getName() << " has: " << p2.showHand() << "\n";
//      myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
//      myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

      if(p1.getHandSize() == 0) {
         
         myFile << p1.getName() << " has no cards left in hand\n";

         if (d.size() > 0) {

            dealtCard = d.dealCard();
            p1.addCard(dealtCard); // draw a card if you have no cards in hand, or if no book found.
            myFile << p1.getName() << " draws " << dealtCard.toString() << "\n";
      
         } else {

            myFile << p1.getName() << ": No cards left to draw\n";

         }

      }

      while (p1.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.
  
         p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
      }

      myFile << p1.getName() << " has: " << p1.showHand() << "\n";
      myFile << p2.getName() << " has: " << p2.showHand() << "\n";
      myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
      myFile << p2.getName() << " books: " << p2.showBooks() << "\n";
// player 2 turn.      
      playersTurn = 0;
      myFile << p2.getName() << "'s turn\n";

      do { 

         if (playersTurn == 1) {

            myFile << p2.getName() << " goes again\n";

         }

         if (p2.getHandSize() > 0) {

            currentCard = p2.chooseCardFromHand(); // picks a card to ask from opponent.
            playersTurn = 0; // will fall out of loop unless cards are paired.
            myFile << p2.getName() << " asks - Do you have a " << currentCard.rankString(currentCard.getRank()) << "?\n";

            boolResult = p1.cardInHand(currentCard); // checks for the asked card.

            if (boolResult == true) { // player 1 checks for the card that player 2 chooses.
         
               myFile << p1.getName() << " says - Yes. I have a " << currentCard.rankString(currentCard.getRank()) << "\n";
               switchCard = p1.removeCardFromHand(currentCard); // removes the card from player 1.
               p2.addCard(switchCard); // player 2 gets the new card.

//               myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
//               myFile << p2.getName() << " has: " << p2.showHand() << "\n";
//               myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
//               myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

               if (p2.checkHandForBook(c1, c2)) { // makes sure there is a pair to book.

                  myFile << p2.getName() << " books the " << currentCard.rankString(currentCard.getRank()) << "\n";
                  p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
               }

               myFile << p1.getName() << " has: " << p1.showHand() << "\n"; // prints name and hands.
               myFile << p2.getName() << " has: " << p2.showHand() << "\n";
               myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
               myFile << p2.getName() << " books: " << p2.showBooks() << "\n";
               playersTurn = 1; // repeats the turn.

            }   

         }

      } while (playersTurn == 1 && p2.getHandSize() > 0); 

      if(p2.getHandSize() > 0 && boolResult == false) {
         
         myFile << p1.getName() << " says - Go Fish!\n";

         if (d.size() > 0) {

            dealtCard = d.dealCard();
            p2.addCard(dealtCard); // draw a card if you have no cards in hand, or if no book found.
            myFile << p2.getName() << " draws " << dealtCard.toString() << "\n";
      
         } else {

            myFile << p2.getName() << ": No cards left to draw\n";

         }

      }
      
      while (p2.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.
  
         p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
      }

//      myFile << p1.getName() << " has: " << p1.showHand() << "\n";
//      myFile << p2.getName() << " has: " << p2.showHand() << "\n";
//      myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
//      myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

      if(p2.getHandSize() == 0) {

         myFile << p2.getName() << " has no cards left in hand\n";

         if (d.size() > 0) {

            dealtCard = d.dealCard();
            p2.addCard(dealtCard); // draw a card if you have no cards in hand, or if no book found.
            myFile << p2.getName() << " draws " << dealtCard.toString() << "\n";

         } else {

            myFile << p2.getName() << ": No cards left to draw\n";

         }
      
      }

      while (p2.checkHandForBook(c1, c2)) { // books all the pairs that exist in open hand.
  
         p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2)); // books the pair. deletes the booked pair from hand.
            
      }

      myFile << p1.getName() << " has: " << p1.showHand() << "\n";
      myFile << p2.getName() << " has: " << p2.showHand() << "\n";
      myFile << p1.getName() << " books: " << p1.showBooks() << "\n"; // prints name and hands.
      myFile << p2.getName() << " books: " << p2.showBooks() << "\n";

   }
// outcome of game. no turns left.   
   cout << "game has been decided, check the output file 'gofish_results.txt'\n";

   if (p1.getBookSize() > p2.getBookSize()) { // if p1 has more books.

      myFile << p1.getName() << " Wins!" << endl; 

   }

   if (p1.getBookSize() < p2.getBookSize()) { // if p2 has more books

      myFile << p2.getName() << " Wins!" << endl; 

   }
 
   if (p1.getBookSize() == p2.getBookSize()) { // if draw

      myFile << p1.getName() << " and " << p2.getName() << " Tie!" << endl; 

   }

   myFile.close();
   return EXIT_SUCCESS;  

}



void dealHand(Deck &d, Player &p, int numCards) {
   
   for (int i=0; i < numCards; i++) {
     
      p.addCard(d.dealCard());

   }

}
   



