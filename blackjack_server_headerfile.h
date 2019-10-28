#include <vector>
#include <iostream> //using printf atm
#include <stdlib.h>
#include <assert.h>


#define ACE   0x01
#define TWO   0x02
#define THREE 0x03
#define FOUR  0x04
#define FIVE  0x05
#define SIX   0x06
#define SEVEN 0x07
#define EIGHT 0x08
#define NINE  0x09
#define TEN   0x0a
#define JACK  0x0b
#define QUEEN 0x0c
#define KING  0x0d

//Spades, hearts, clubs, diamond
#define SPADES    0x10
#define HEARTS    0x20
#define CLUBS     0x30
#define DIAMONDS  0x40

#define DECKS_USED 6

#ifndef BJACKHEADER
#define BJACKHEADER

using namespace std;

class Shoe {
	public:
	vector<char> Cards_In_Play;
	int suits[4] = {SPADES, HEARTS, CLUBS, DIAMONDS};
	char* deck_ptr = (char*) malloc(sizeof(char)*((DECKS_USED*52)+1)); //used for construction and printing
	char* game_ptr = deck_ptr; //used to keep track of where the deck is during the game
	//public:
	void shuffle(); //implemented, but need to account for cards that have been played
	void create_single_deck(char* ptr); //implemented
	void create_shoe(); //implemented
	void assert_deck(); //implemented
	void fixed_shuffle_1();
	void fixed_shuffle_2();
	void fixed_shuffle_3();
	void printdeck(); //implemented
	char deal_card();
	void round_end(); //stuff for when a round ends
	Shoe();
	virtual ~Shoe();
};

#endif
