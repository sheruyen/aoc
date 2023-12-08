#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

int main(){
	std::ifstream In("input.txt");

	int game;
	int result = 0;
	bool ok = true;

	std::unordered_map<std::string, int> cubes;
	cubes["red"] = 12;
	cubes["green"] = 13;
	cubes["blue"] = 14;

	std::string line, skip, kon, cubestr;

	while(std::getline(In, line)) {	// Game scope
		std::istringstream lineStream(line);
		lineStream >> skip >> game; // Skip the first word "Game" and read game number
		lineStream >> skip;			// Skip the ':'
		
		while (std::getline(lineStream, kon, ';')){	// kon scope
			std::istringstream konStream(kon);
			while (std::getline(konStream, cubestr, ',')) {	// each cube scope
				std::istringstream cubestrStream(cubestr);
				int count;
				std::string color;
				cubestrStream >> count >> color;
				if (count > cubes[color]) {
					ok = false;
				}
			}
		}
		if (ok) {
			result += game;
		}
		ok = true;
	}
	std::cout << result << std::endl;
}
