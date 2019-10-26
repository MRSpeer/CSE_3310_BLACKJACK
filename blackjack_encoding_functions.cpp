#include "blackjack_encoding_headerfile.h"
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <gtkmm.h>

// 0 - set username/funds, 1 = place bets, 2 = gameplay, 3 = savecards, 4 = continuance

void P_Package::set_Gameplay(bool Gameplay_ans) //player pressed hit or stand
{
	player_state = 2;
	gameplay = Gameplay_ans;
	//send_package
}

void P_Package::set_Stand()
{
	player_state = 2;
	stand = true;
	//send_package
}

void P_Package::set_Save_Card()
{
	player_state = 3;
	saveCards = true;
	//send_package
}

void P_Package::set_Continue(bool Cont_ans)
{
	player_state = 4;
	cont = Cont_ans;
	//send_package
}

void P_Package::set_User(string name, float fund_Val)
{
	player_state = 0;
	username = name;
	funds = fund_Val;
	//send_package
}

void P_Package::set_Bet(int bet_Val)
{
	player_state = 1;
	bet = bet_Val;
	//send_package
}

