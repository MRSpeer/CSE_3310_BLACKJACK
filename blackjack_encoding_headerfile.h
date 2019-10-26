#ifndef BLACKJACK_ENCODING_HEADERFILE_H
#define BLACKJACK_ENCODING_HEADERFILE_H

#include <gtkmm.h>
#include <string>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Player_Info

class P_Package
{
	private:
	int player_state = 0;
	string username = "";
	float funds = 0.0;
	int bet = 0;
	bool gameplay = false;
	bool saveCards = false;
	bool cont = false;
	
	public:
	void set_Gameplay(bool Gameplay_ans);
	void set_Save_Card();
	void set_Continue(bool Cont_ans);
	void set_User(string name, float fund_Val);
	void set_Bet(int bet_Val);
};

class D_Package
{
	private:
	vector<string> player_Names;
	vector<vector<char>> player_Cards;
	vector<float> player_Funds;
	vector<bool> player_endState;
	vector<char> dealer_cards;
	float dealer_Funds;
	int game_State;
	
	public:
};

#endif