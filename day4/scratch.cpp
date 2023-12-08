#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

int main(){
	std::ifstream In("input.txt");

	int result = 0;
	int points = 0;
	int win[10];
	int cardNum;
	std::string line, delim;

	while(std::getline(In, line)) {
		std::istringstream lineStream(line.substr(10));
		for(int i = 0; i < 10; i++) {
			lineStream >> win[i];
		}
		lineStream >> delim; // skip the delimeter
		for(int i = 0; i < 25; i++) {
			lineStream >> cardNum;
			auto iter = std::find(std::begin(win), std::end(win), cardNum);
			if(iter!= std::end(win)) { // if number is among the winning numbers
				points == 0 ? points = 1 : points *= 2;
			}
		}
		result += points;
		points = 0;
	}
	std::cout << result << std::endl;
}
