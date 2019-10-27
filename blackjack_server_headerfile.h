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
	vector<char> Cards_In_Play;
	char* deck_ptr = (char*) malloc(sizeof(char)*((DECKS_USED*4*13)));
	public:
	void shuffle();
	void create_deck();
	void fixed_shuffle_1();
	void fixed_shuffle_2();
	void fixed_shuffle_3();
	void printdeck();
	char deal_card();
	Shoe();
	virtual ~Shoe();
};

#endif
