Compile the Program:
1) simply click make -f makefile
2) the executable for this file is "GoFish" 
3) run the program with ./GoFish
4) once the program is done the results can be found in the file "gofish_result.txt"

Notes when running the program: 
1) there are preconditions created in the deck for functions who are supposed to fail
 when they do not need to return a card, but the driver program takes care of those.
2) There really should not be any preconditions the user needs to do but,

My version of the game operates as such: 

1) The game begins with the players and deck being created. (deck is shuffled)
2) both players then draw 7 cards.
3) The pairs from draw are always booked immediately. 
4) the players only draw cards when they have no cards left in hand
or when the opponent does not have the asked for card.
5) The next players turn always occurs once the opponent has drawn a card. 
6) A players turn is repeated until forced to draw a card. 
7) The game will end when the deck and both players have no cards left.
8) The game will end with either a tie or one person winning based off the number of pairs booked.
9) pairs are always booked after every action resulting in an added card, but the result 
may not immediately be printed to the output file - will be shown shortly after is so.
