#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

void event_number(int& events, int& first_half_events, int& second_half_events) {
	//PURPOSE: Generate the number of events total, and the number of events in the first half of the game
	//INPUTS: Passed in by reference is the total events integer and the integer storing the events in the first half
	//OUTPUTS: Nothing is returned or printed to console, but events, first_half_events and second_half_events is modified
	srand(unsigned(time(0)));
	events = rand() % 20 + 1; //events randomly set to 1-20
	first_half_events = events - (rand() % events + 1); //first half events are set to a random amount of total events
	second_half_events = events - first_half_events;
}

void event_assigner(int events, int& a_score, int& b_score, int& a_shots_on_goal, int& a_shots_off_goal, int& a_blocked_shots, int& a_fouls, int& a_yellow_cards,
	int& a_red_cards, int& b_shots_on_goal, int& b_shots_off_goal, int& b_blocked_shots, int& b_fouls, int& b_yellow_cards, int& b_red_cards) {
	//PURPOSE: Assign each generated event to an actual event with goals, fouls, etc.
	//INPUTS: The amount of events that the simulator needs to calculate
	//OUTPUTS: Nothing is returned, but each event is printed to console as it happens. Each stat for both teams is also modified in this function
	srand(unsigned(time(0)));
	int event_type;
	int shot_event;
	int card;
	for (int i = 0; i < events; i++) { 
		event_type = rand() % 6 + 1; //randomizes the type of event to the range [1,6], inclusive
		if (event_type == 1) {
			//Team A goal check
			std::cout << "Team A takes an incredible shot on net!\n";
			Sleep(1000);
			shot_event = rand() % 4; //randomized the shot_event to the range [0,3], inclusive
			switch (shot_event) { //Switch statement that runs through each possibility after a shot is taken
			case 0:
				std::cout << "GOALLLLLLL!!!!!\n";
				Sleep(1000);
				a_score++; //a's score is incremented along with their shots on goal
				a_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) { //50% chance to be blocked by goalie or last defender, respectively 
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					b_blocked_shots++; //b blocked the shot, so b_blocked_shots is incremented, but since a shot on net, a_shots_on_goal is incremented as well
					a_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					b_blocked_shots++;
					a_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				a_shots_off_goal++;
				Sleep(1000);
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				b_blocked_shots++;
				a_shots_on_goal++;
				Sleep(1000);
				break;
			default:
				break;
			}
		}
		if (event_type == 2) {
			//Team B goal check
			std::cout << "Team B shoots a rocket towards the net!\n";
			Sleep(1000);
			shot_event = rand() % 4;
			switch (shot_event) {
			case 0:
				std::cout << "GOOOOOOALLLLLLLLLLLLLLLLL\n";
				Sleep(1000);
				b_score++;
				b_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) {
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				Sleep(1000);
				b_shots_off_goal++;
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				Sleep(1000);
				break;
				b_shots_on_goal++;
				a_blocked_shots++;
			default:
				break;
			}
		}
		if (event_type == 3) {
			//Team B foul check
			std::cout << "Looks like team B fouled team A.\n";
			b_fouls++;
			Sleep(1000);
			card = rand() % 3; //card variable determines what type of card the player with recieve. It is randomized to the range [0,2], inclusive
			if (card == 0) {
				std::cout << "No card appears to be given to team B\n";
				Sleep(1000);
			}
			if (card == 1) {
				std::cout << "Woah! That's a yellow card for team B\n";
				Sleep(1000);
				b_yellow_cards++;
			}
			if (card == 2) {
				std::cout << "Oh no... that's heartbreaking. A red card for team B\n";
				Sleep(1000);
				b_red_cards++;
			}
			Sleep(2000);
			std::cout << "And that's a free kick for team A!\n";
			Sleep(1000);
			//Team A goal check
			std::cout << "Team A takes an incredible shot on net!\n";
			Sleep(1000);
			shot_event = rand() % 4;
			switch (shot_event) {
			case 0:
				std::cout << "GOALLLLLLL!!!!!\n";
				Sleep(1000);
				a_score++;
				a_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) {
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					b_blocked_shots++;
					a_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					b_blocked_shots++;
					a_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				a_shots_off_goal++;
				Sleep(1000);
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				b_blocked_shots++;
				a_shots_on_goal++;
				Sleep(1000);
				break;
			default:
				break;
			}

		}
		if (event_type == 4) {
			//Team A foul check
			std::cout << "Looks like team A fouled team B.\n";
			a_fouls++;
			Sleep(1000);
			card = rand() % 3;
			if (card == 0) {
				std::cout << "No card appears to be given to team A\n";
				Sleep(1000);
			
			}
			if (card == 1) {
				std::cout << "Woah! That's a yellow card for team A\n";
				Sleep(1000);
				a_yellow_cards++;
			}
			if (card == 2) {
				std::cout << "Oh no... that's heartbreaking. A red card for team A\n";
				Sleep(1000);
				a_red_cards++;
			}
			Sleep(2000);
			std::cout << "And that's a free kick for team B!\n";
			Sleep(1000);
			//Team B goal check
			std::cout << "Team B shoots a rocket towards the net!\n";
			Sleep(1000);
			shot_event = rand() % 4;
			switch (shot_event) {
			case 0:
				std::cout << "GOOOOOOALLLLLLLLLLLLLLLLL\n";
				Sleep(1000);
				b_score++;
				b_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) {
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				Sleep(1000);
				b_shots_off_goal++;
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				Sleep(1000);
				break;
				b_shots_on_goal++;
				a_blocked_shots++;
			default:
				break;
			}
		}
		if (event_type == 5) {
			//Team B foul check
			std::cout << "Looks like team B fouled team A too close to the goal!\n";
			b_fouls++;
			Sleep(1000);
			card = rand() % 3;
			if (card == 0) {
				std::cout << "No card appears to be given to team B\n";
				Sleep(1000);
			}
			if (card == 1) {
				std::cout << "Woah! That's a yellow card for team B\n";
				Sleep(1000);
				b_yellow_cards++;
			}
			if (card == 2) {
				std::cout << "Oh no... that's heartbreaking. A red card for team B\n";
				Sleep(1000);
				b_red_cards++;
			}
			Sleep(3000);
			std::cout << "Looks like a penalty kick for team A\n";
			Sleep(1000);
			//Team A goal check
			std::cout << "Team A takes an incredible shot on net!\n";
			Sleep(1000);
			shot_event = rand() % 4;
			switch (shot_event) {
			case 0:
				std::cout << "GOALLLLLLL!!!!!\n";
				Sleep(1000);
				a_score++;
				a_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) {
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					b_blocked_shots++;
					a_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					b_blocked_shots++;
					a_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				a_shots_off_goal++;
				Sleep(1000);
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				b_blocked_shots++;
				a_shots_on_goal++;
				Sleep(1000);
				break;
			default:
				break;
			}


		}
		if (event_type == 6) {
			//Team A foul check
			std::cout << "Looks like team A fouled team B too close to the net!\n";
			a_fouls++;
			Sleep(1000);
			card = rand() % 3;
			if (card == 0) {
				std::cout << "No card appears to be given to team A\n";
				Sleep(1000);

			}
			if (card == 1) {
				std::cout << "Woah! That's a yellow card for team A\n";
				Sleep(1000);
				a_yellow_cards++;
			}
			if (card == 2) {
				std::cout << "Oh no... that's heartbreaking. A red card for team A\n";
				Sleep(1000);
				a_red_cards++;
			}
			Sleep(2000);
			std::cout << "And that's a penalty kick for team B!\n";
			Sleep(1000);
			//Team B goal check
			std::cout << "Team B shoots a rocket towards the net!\n";
			Sleep(1000);
			shot_event = rand() % 4;
			switch (shot_event) {
			case 0:
				std::cout << "GOOOOOOALLLLLLLLLLLLLLLLL\n";
				Sleep(1000);
				b_score++;
				b_shots_on_goal++;
				break;
			case 1:
				if (rand() % 2 == 0) {
					std::cout << "WOW! What an amazing block by the goalie!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				else {
					std::cout << "WOW! What an amazing block by the last defender!\n";
					Sleep(1000);
					a_blocked_shots++;
					b_shots_on_goal++;
				}
				break;
			case 2:
				std::cout << "And... a complete miss.\n";
				Sleep(1000);
				b_shots_off_goal++;
				break;
			case 3:
				std::cout << "Excellent block by play number " << rand() % 100 << "\n";
				Sleep(1000);
				break;
				b_shots_on_goal++;
				a_blocked_shots++;
			default:
				break;
			}
		}
	}

}

void half_time(int a_score, int b_score, int a_shots_on_goal, int a_shots_off_goal, int a_blocked_shots, int a_fouls, int a_yellow_cards, 
	int a_red_cards, int b_shots_on_goal, int b_shots_off_goal, int b_blocked_shots, int b_fouls, int b_yellow_cards, int b_red_cards) {
	//PURPOSE: Output all the calculated stats from the event_assigner at halftime
	//INPUTS: All the stats for team A and B
	//OUTPUTS: Print all the stats for team A and B to console

	std::cout << "\n\nHALFTIME!!\n\n";
	Sleep(2000);
	std::cout << "A's Current Score is: " << a_score << "		" << "B's Current Score is: " << b_score << "\n";
	Sleep(1000);
	std::cout << "A's shots on goal: " << a_shots_on_goal << "		" << "B's shots on goal: " << b_shots_on_goal << "\n";
	Sleep(1000);
	std::cout << "A's shots off goal: " << a_shots_off_goal << "		" << "B's shots off goal: " << b_shots_off_goal << "\n";
	Sleep(1000);
	std::cout << "A's blocked shots: " << a_blocked_shots << "		" << "B's blocked shots: " << b_blocked_shots << "\n";
	Sleep(1000);
	std::cout << "A's fouls: " << a_fouls << "			" << "B's fouls: " << b_fouls << "\n";
	Sleep(1000);
	std::cout << "A's yellow cards: " << a_yellow_cards << "		" << "B's yellow cards: " << b_yellow_cards << "\n";
	Sleep(1000);
	std::cout << "A's red cards: " << a_red_cards << "		" << "B's red cards: " << b_red_cards << "\n";
	Sleep(4000);
	std::cout << "Halftime is over! Resume play!\n\n";
}

void game_over(int a_score, int b_score, int a_shots_on_goal, int a_shots_off_goal, int a_blocked_shots, int a_fouls, int a_yellow_cards,
	int a_red_cards, int b_shots_on_goal, int b_shots_off_goal, int b_blocked_shots, int b_fouls, int b_yellow_cards, int b_red_cards) {
	//PURPOSE: Output all the calculated stats from the event_assigner at the end of the game
	//INPUTS: All the stats for team A and B
	//OUTPUTS: Print all the stats for team A and B to console
	
	std::cout << "\n\nGAME OVER!\n\n";
	
	std::cout << "A's final score is: " << a_score << "		" << "B's final score is: " << b_score << "\n";
	Sleep(1000);

	if (a_score > b_score)
		std::cout << "TEAM A HAS WON THE SOCCER GAME!\n\n";
	else if (a_score < b_score)
		std::cout << "TEAM B HAS WON THE SOCCER GAME!\n\n";
	else
		std::cout << "TIE GAME!\n\n";
	Sleep(1000);
	std::cout << "A's shots on goal: " << a_shots_on_goal << "		" << "B's shots on goal: " << b_shots_on_goal << "\n";
	Sleep(1000);
	std::cout << "A's shots off goal: " << a_shots_off_goal << "		" << "B's shots off goal: " << b_shots_off_goal << "\n";
	Sleep(1000);
	std::cout << "A's blocked shots: " << a_blocked_shots << "		" << "B's blocked shots: " << b_blocked_shots << "\n";
	Sleep(1000);
	std::cout << "A's fouls: " << a_fouls << "			" << "B's fouls: " << b_fouls << "\n";
	Sleep(1000);
	std::cout << "A's yellow cards: " << a_yellow_cards << "		" << "B's yellow cards: " << b_yellow_cards << "\n";
	Sleep(1000);
	std::cout << "A's red cards: " << a_red_cards << "		" << "B's red cards: " << b_red_cards << "\n";
	Sleep(4000);

	std::cout << "Good game, all!\n";
}
int main() {
	int events;
	int first_half_events;
	int second_half_events;
	int a_score = 0;
	int b_score = 0;
	int a_shots_on_goal = 0;
	int a_shots_off_goal = 0;
	int a_blocked_shots = 0;
	int a_fouls = 0;
	int a_yellow_cards = 0;
	int a_red_cards = 0;
	int b_shots_on_goal = 0;
	int b_shots_off_goal = 0;
	int b_blocked_shots = 0;
	int b_fouls = 0;
	int b_yellow_cards = 0;
	int b_red_cards = 0;

	std::cout << "GAME START!\n\n";
	Sleep(4000);
	event_number(events, first_half_events, second_half_events);
	event_assigner(first_half_events, a_score, b_score, a_shots_on_goal, a_shots_off_goal, a_blocked_shots, a_fouls, a_yellow_cards, 
		a_red_cards, b_shots_on_goal, b_shots_off_goal, b_blocked_shots, b_fouls, b_yellow_cards, b_red_cards);
	half_time(a_score, b_score, a_shots_on_goal, a_shots_off_goal, a_blocked_shots, 
		a_fouls, a_yellow_cards, a_red_cards, b_shots_on_goal, b_shots_off_goal, b_blocked_shots, b_fouls, b_yellow_cards, b_red_cards);
	event_assigner(second_half_events, a_score, b_score, a_shots_on_goal, a_shots_off_goal, a_blocked_shots, a_fouls, a_yellow_cards, 
		a_red_cards, b_shots_on_goal, b_shots_off_goal, b_blocked_shots, b_fouls, b_yellow_cards, b_red_cards);
	game_over(a_score, b_score, a_shots_on_goal, a_shots_off_goal, a_blocked_shots,
		a_fouls, a_yellow_cards, a_red_cards, b_shots_on_goal, b_shots_off_goal, b_blocked_shots, b_fouls, b_yellow_cards, b_red_cards);
}
