#include <iostream>
#include <ctime>
#include <string>
using namespace std;


const int PILE_MAX = 50;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);

bool PowerOfTwo(int n) {
	while (n != 1)
		{

		if (n == 0) {
			return false;
		}
		if (n % 2 != 0 && n != 1)
			return false;
		n = n / 2;
	}

	return true;

}



void computer_play(int& pile, bool smart) {
	cout << "There are " << pile << " marbles left in the pile." << endl;
	for (int i = 0; i < pile; i++) {
		cout << MARBLE << endl;
	}
	cout << "Computer plays:" << endl;
	if (smart == true) {
		cout << "The computer will play smart." << endl;
		if (PowerOfTwo(pile+1)) {
			int randSub = rand() % ((pile / 2) % pile) + 1;
			pile = pile - randSub;
			cout << "The computer took " << randSub << " marbles." << endl;
		}
		else {
			int counter;
			counter = 0;
			while (PowerOfTwo(pile + 1) == false) {
				pile = pile - 1;
				counter = counter + 1;
			}
			cout << "The computer took " << counter << " marbles." << endl;
		}
		
	}
	else {
		cout << "The computer will not play smart." << endl;
		int randSub = rand() % ((pile / 2) % pile) + 1;
		pile = pile - randSub;
		cout << "The computer took " << randSub << " marbles." << endl;
	}
	if (pile == 1) {
		cout << "You took the last marble. You lose." << endl;
	}
}

void player_play(int& pile) {
	int playerTakes;
	cout << "There are " << pile << " marbles left in the pile." << endl;

	for (int i = 0; i < pile; i++) {
		cout << MARBLE << endl;
	}
	cout << "Your play... you may take 1-" << pile / 2 << " marbles.";
	cin >> playerTakes;
	cin.ignore(256, '\n');
	while (cin.fail()) {

		if (cin.fail()) {
			cin.clear();
			string FailedInput;

			getline(cin, FailedInput);
			cout << "Not a valid input." << endl;

		}
		cout << "Your play... you may take 1-" << pile / 2 << " marbles.";
		cin >> playerTakes;
		cin.ignore(256, '\n');
	}

	while (playerTakes > pile / 2 || playerTakes < 1) {
			cout << "You picked too many or not enough." << endl;
			cout << "There are " << pile << " marbles left in the pile." << endl;

			for (int i = 0; i < pile; i++) {
				cout << MARBLE << endl;
			}
			cout << "Your play... you may take 1-" << pile / 2 << " marbles.";
			cin >> playerTakes;
			cin.ignore(256, '\n');
			while (cin.fail()) {

				if (cin.fail()) {
					cin.clear();
					string FailedInput;

					getline(cin, FailedInput);
					cout << "Not a valid input." << endl;

				}
				cout << "Your play... you may take 1-" << pile / 2 << " marbles.";
				cin >> playerTakes;
				cin.ignore(256, '\n');
			}
	}
	pile = pile - playerTakes;

	if (pile == 1) {
		cout << "The computer took the last marble. You win!" << endl;
	}
}


int main(){
	srand((unsigned int)time(NULL));
	int pile = rand() % 41 + 10; //returns a number between 1 and 50
	int turnOrder = rand() % 2;
	bool smart = rand() %	2;


		cout << "*****************************************************" << endl;
		cout << "*                   The game of Nim                 *" << endl;
		cout << "*    Players alternate taking at least one but at   *" << endl;
		cout << "*    most half of the marbles in the pile.          *" << endl;
		cout << "*    The player who takes the last marble loses.    *" << endl;
		cout << "*    It is written by Adrian Treadwell              *" << endl;
		cout << "*    I hope you beat the computer:)                 *" << endl;
		cout << "*    No matter what, have a great day.              *" << endl;
		cout << "*****************************************************" << endl;


	
	if (turnOrder == 0) {
		cout << "The computer will play first." << endl;
		while (1 == 1) {
			computer_play(pile, smart);
			if (pile == 1) {
				break;
			}
			player_play(pile);
			if (pile == 1) {
				break;
			}
		}
	}
	else {
		cout << "You will play first." << endl;
		while (1 == 1) {
			player_play(pile);
			if (pile == 1) {
				break;
			}
			computer_play(pile, smart);
			if (pile == 1) {
				break;
			}

		}

	}





	
}

