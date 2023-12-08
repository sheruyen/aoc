#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

int main(){
	std::ifstream In("input.txt");

	int game;
	int result = 0;

	std::unordered_map<std::string, int> cubes; // Repurposed to store the MAX
	cubes["red"] = 0;
	cubes["green"] = 0;
	cubes["blue"] = 0;

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
					cubes[color] = count;
				}
			}
		}
		result += cubes["red"] * cubes["green"] * cubes["blue"];
		cubes["red"] = 0;
		cubes["green"] = 0;
		cubes["blue"] = 0;
	}
	std::cout << result << std::endl;
}
