#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

int solve(int card, const int(&wins)[209]) {
	if (wins[card] == 0) return 0;
	int sum = wins[card];
	for (int i = 1; i <= wins[card]; i++) {
		if (card + i > 208) break;
		sum += solve(card + i, wins); // 😎
	}
	return sum;
}

int main(){
	std::ifstream In("input.txt");

	int allCards[209][35]; // 10 winning numbers + 25 playing numbers
	int allWins[209];
	int cardsWon;
	int total = 0;

	std::string line, delim;
	for (int card = 0; std::getline(In, line); card++){
		std::istringstream lineStream(line.substr(10));
		for(int i = 0; i < 10; i++) {
			lineStream >> allCards[card][i];
		}
		lineStream >> delim; // skip the delimeter
		for(int i = 10; i < 35; i++) {
			lineStream >> allCards[card][i];
			for (int j = 0; j < 10; j++) {
				if (allCards[card][i] == allCards[card][j]) {
					cardsWon++;
				}
			}
		}
		allWins[card] = cardsWon;
		cardsWon = 0;
	}
	for (int card = 0; card < 209; card++){
		total += solve(card, allWins);
	}
	std::cout << total + 209 << std::endl; // add the initial set of cards
}
