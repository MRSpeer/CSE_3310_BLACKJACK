#include "blackjack_server_headerfile.h"
#include <stdio.h>


	void Shoe::shuffle() {
		char tempcard;
		int randindex;
		int cards_played = Cards_In_Play.size();
		for (int i = 0; i < (DECKS_USED*52); i++) {
			tempcard = deck_ptr[i];
			randindex = rand() % (DECKS_USED*52);
			assert(randindex < (DECKS_USED*52)); // less than 312 in our case
			//printf("%3d %3d %2x %2x......",i,randindex,deck_ptr[i],deck_ptr[randindex]);
			deck_ptr[i] = deck_ptr[randindex];
			deck_ptr[randindex] = tempcard;
			//printf("%2x %2x\n",deck_ptr[i],deck_ptr[randindex]);
		}
		printdeck();
		for (int i = 0; i < cards_played; i++) {
			for (int j = 0; j < (DECKS_USED*52); j++) {
				if ((Cards_In_Play[i] == deck_ptr[j]) && (i < j)) {
					//i < j adds protection against duplicate cards currently out
					printf("%d %x\n",j,deck_ptr[j]);
					tempcard = deck_ptr[i];
					deck_ptr[i] = deck_ptr[j];
					deck_ptr[j] = tempcard;
					break;
				}
			}
		}
		game_ptr = deck_ptr + cards_played;
		printf("Top of deck: %x\n",*game_ptr);
	}
	//Need to add to UML diagram
	void Shoe::create_single_deck(char* ptr) {
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 14; j++) {
				*ptr = (suits[i] | j);
				ptr++;
			}
		}
	}
	//Need to add to UML diagram
	void Shoe::create_shoe() {
		deck_ptr[DECKS_USED*52] = 0; //used to check for shuffling
		char* temp = deck_ptr;
		for (int i = 0; i < DECKS_USED; i++) {
			create_single_deck(deck_ptr);
			deck_ptr = deck_ptr+52;
		}
		deck_ptr = temp;
	}
	//Need to add to UML diagram
	//asserts that the deck has DECKS_USED of each card after shuffling
	void Shoe::assert_deck() {
		int check = 0;
		char* comp_deck = (char*) malloc (sizeof(char)*52);
		create_single_deck(comp_deck);
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < DECKS_USED*52; j++) {
				if (comp_deck[i] == deck_ptr[j]) check++;
			}
			if (check != DECKS_USED) printf("%x is not in the deck %d times\n",comp_deck[i],DECKS_USED);
			check = 0;
		}
		free(comp_deck);
		comp_deck = NULL;
	}
	void Shoe::fixed_shuffle_1() {
	}
	void Shoe::fixed_shuffle_2() {
	}
	void Shoe::fixed_shuffle_3() {
	}
	char Shoe::deal_card() {
		char card = *game_ptr;
		printf("%x ||",card);
		Cards_In_Play.push_back(card);
		for (unsigned int i = 0; i < Cards_In_Play.size(); i++) {
			printf("%x ",Cards_In_Play[i]);
		}
		printf("\n");
		game_ptr++;
		if (*game_ptr == 0) shuffle();
		return card;
	}
	//May need to add to UML diagram, it's really just for testing purposes right now
	//but may be used to show fixed shuffles
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
	//Need to add to UML, clears vector of cards in play
	void Shoe::round_end() {
		Cards_In_Play.clear();
	}
	Shoe::Shoe() {};
	Shoe::~Shoe() {};

//temp main
int main() {
	/*Shoe test;
	test.create_shoe();
	printf("\n\n\n");
	test.shuffle();
	//test.printdeck();
	test.assert_deck();
	test.deal_card();
	test.deal_card();
	test.deal_card();
	printf("\n");
	test.printdeck();
	printf("\n");
	test.Cards_In_Play.push_back(0x2a);
	test.shuffle();
	test.printdeck();*/
	return 0;
}
