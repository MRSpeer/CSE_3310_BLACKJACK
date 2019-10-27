#include "blackjack_server_headerfile.h"
#include <stdio.h>


	void Shoe::shuffle() {
		char tempcard;
		int randindex;
		for (int i = 0; i < (DECKS_USED*4*13); i++) {
			tempcard = deck_ptr[i];
			randindex = rand() % (DECKS_USED*4*13);
			assert(randindex < 312);
			printf("%3d %3d %2x %2x......",i,randindex,deck_ptr[i],deck_ptr[randindex]);
			deck_ptr[i] = deck_ptr[randindex];
			deck_ptr[randindex] = tempcard;
			printf("%2x %2x\n",deck_ptr[i],deck_ptr[randindex]);
		}
		return;
	}
	//Need to add to UML diagram
	// i%4 = 0, ACE, i%4 = 1 CLUBS, i%4 = 2 DIAMONDS i%4 = 3 HEARTS
	void Shoe::create_deck() {
		char* temp = deck_ptr;
		for (int i = 0; i < DECKS_USED; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 1; k <14; k++) {
					if (j == 0) *deck_ptr = (SPADES | k);
					if (j == 1) *deck_ptr = (HEARTS | k);
					if (j == 2) *deck_ptr = (CLUBS | k);
					if (j == 3) *deck_ptr = (DIAMONDS | k);
					deck_ptr++;
				}
			}
		}
		deck_ptr = temp;
	}
	void AssertDeck() {
		
	}
	void Shoe::fixed_shuffle_1() {
	}
	void Shoe::fixed_shuffle_2() {
	}
	void Shoe::fixed_shuffle_3() {
	}
	char Shoe::deal_card() {
		char card = *deck_ptr;
		deck_ptr++;
		if (*deck_ptr == 0) shuffle();
		return card;
	}
	void Shoe::printdeck() {
		char* temp = deck_ptr;
		for (int i = 0; i < DECKS_USED; i++) {
			for (int j = 0; j < 52; j++) {
				printf("%x ",*deck_ptr);
				deck_ptr++;
			}
		printf("\n");
		}
		deck_ptr = temp;
	}
	Shoe::Shoe() {};
	Shoe::~Shoe() {};

//temp main
int main() {
	Shoe test;
	test.create_deck();
	test.printdeck();
	printf("\n\n\n");
	test.shuffle();
	test.printdeck();
	return 0;
}
