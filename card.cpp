//card.cpp
#include <fstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "card.h"
#include <vector>
#include <sstream>

using namespace std;

   Card::Card() { // default, ace of spades

      myRank = 1;
      mySuit = Card::spades;

   }

   Card::Card(int rank, Suit s) {

      myRank = rank;
      mySuit = s; // since the type is a suit and input is a suit it should be fine without Class::suit...

   }

   string Card::toString()              const {  // return string version e.g. Ac 4h Js
//with the assumption function look like: C2.toString
      return (rankString(myRank) + suitString(mySuit)); // should call the two functions that 

   }

   bool Card::sameSuitAs(const Card& c) const {  // true if suit same as c

      return (mySuit == c.mySuit); //overload operator should come into play here.

   }

   int  Card::getRank()                 const {  // return rank, 1..13

      return myRank;

   }

   string Card::suitString(Suit s)      const {  // return "s", "h",...c, or d.

      string strSuit;
      int suit = s;

         switch (suit) // four special cases will not need to be converted to string since i will hard code their string with a switch.

         {

         case 0: strSuit = "s";
                  break;
         case 1: strSuit = "h";
                  break;
         case 2: strSuit = "d";
                  break;
         case 3: strSuit = "c";
                  break;

         }

      return (strSuit);
   
   }
  
   string Card::rankString(int r)       const {  // return "A", "2", ..."Q"  

      string strRank = "oh fuck something went wrong";
      stringstream ss;

      if (r == 1 || r == 11 || r == 12 || r == 13) {

         switch (r) // four special cases will not need to be converted to string since i will hard code their string with a switch.

         {

         case 1: strRank = "A";
                  break;
         case 11: strRank = "J";
                  break;
         case 12: strRank = "Q";
                  break;
         case 13: strRank = "K";
                  break;
 
         }

      } else { 

         ss << r;
         strRank = ss.str();
       
      }
        
   return (strRank); // should convert the integer r into a string and return it.

   }
    
   bool Card::operator == (const Card& rhs) const { // == and != for the entire cared. suit has its own function ^.

      return (myRank == rhs.myRank && mySuit == rhs.mySuit); // both are integers so no need to compare?

   }

   bool Card::operator != (const Card& rhs) const {

      return (myRank != rhs.myRank && mySuit != rhs.mySuit); // both are integers so no need to compare?

   }

   ostream& operator << (ostream& out, const Card& c) { // print card = 4s or Kd. so call the converting functions to string and fetch functions when needed.

      string card = c.toString(); //will return the string of suit and rank into card, to then be printed.

      out << card;
      return out;  

   }
