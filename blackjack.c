#include "./blackjack.h"

//declare structs here

//define functions here

//This will set all the values in the deck in acending order

Deck* deckInit(Deck *deck){
    deck = (Deck*)malloc(sizeof(struct Deck));
    if(deck==NULL){
        printf("Error allocating memory\n");
    }
    return deck;
}

Deck* populateDeck(Deck *deck){
    int i=0;
    for(int suit=1; suit<5; suit++){
        for(int rank=1; rank<14; rank++){
            deck->cards[i].rank = rank;
            deck->cards[i].suit = suit;
            i++;
        }
    }
    deck->num_cards = NUMOFCARDS;
    return deck;
}

Deck* shuffleDeck(Deck *deck){
    Card temp;
    time_t t;
    srand((unsigned) time(&t));
    //loops for number of cards and swaps them with temp where
    // temp holds a random card
    for(int i=0; i<deck->num_cards; i++){
        int rand_num = rand()%NUMOFCARDS;
        temp = deck->cards[rand_num];
        deck->cards[rand_num] = deck->cards[i];
        deck->cards[i] = temp;
    }
    deck->top_card_num=0;
    deck->top_card=deck->cards[deck->top_card_num];
    return deck;
}

Game* gameInit(Game* game){
    game = (Game*)malloc(sizeof(struct Game));
    if(game == NULL){
        printf("Error allocating memory for game..\n");
    }
    game->players.hand.n_cards = 0;
    game->dealer.hand.n_cards = 0;
    return game;
}

/* Game* createPlayers(Game* game, int num_players){
    game->num_players = num_players;
    game->players = (Player*)malloc(sizeof(Player) * game->num_players);
    return game;
} */

Game* dealCards(Game* game, Deck *deck){
    game->dealer.hand.n_cards = 0;
    game->players.hand.n_cards = 0;
    for(int j=0; j<2; j++){
        game->players.hand.cards[j] = deck->top_card;
        game->players.hand.n_cards++;
        deck->top_card_num++;
        deck->top_card = deck->cards[deck->top_card_num];
    }
    for(int j=0; j<2; j++){
        game->dealer.hand.cards[j] = deck->top_card;
        game->dealer.hand.n_cards++;
        deck->top_card_num++;
        deck->top_card = deck->cards[deck->top_card_num];
    }
    return game;
}

void deleteDeck(Deck* deck){
    free(deck);
    deck = 0;
}

/* void deletePlayers(Game* game){
    free(game->players);
    game->players = 0;
} */

void deleteGame(Game* game){
    free(game);
    game = 0;
}

Game* addCardPlayer(Game* game, Deck* deck/*,  int player */){
    game->players.hand.cards[game->players.hand.n_cards] = deck->top_card;
    game->players.hand.n_cards++;
    deck->top_card_num++;
    deck->top_card = deck->cards[deck->top_card_num];
    return game;
}

Game* addCardDealer(Game* game, Deck* deck){
    game->dealer.hand.cards[game->dealer.hand.n_cards] = deck->top_card;
    game->dealer.hand.n_cards++;
    deck->top_card_num++;
    deck->top_card = deck->cards[deck->top_card_num];
    return game;
}