//declare functions here

#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct Card{
    //value of each card
    int rank;
    //This will let us know who to assign the card to
    string holder;
}Card;

typedef struct Hand{
    //Array of cards that can be in a hand
    Card *cards;
    int n_cards;
}Hand;

typedef struct Player{
    //Assigns a hand to a player
    Hand hand;
    //name of the player
    string name;
}Player;

typedef struct Deck{
    //For the amount of cards in the deck
    Card cards[52];
    int num_cards;
    //To get the top card of the deck
    int top_card;
}Deck;



#endif