#include <fstream>
#include <iostream>
#include <unordered_map>
#include <utility>

int main() {
	std::ifstream In("input.txt");

	std::string directions;
	std::getline(In, directions);

	std::string line;
	std::getline(In, line); // skip empty line

	std::unordered_map<	std::string,
						std::pair<std::string, std::string> >	maze;
	int steps = 0;
	
	while (std::getline(In, line)) {
		maze[line.substr(0, 3)] = std::make_pair(line.substr(7, 3), line.substr(12, 3));
	}
	std::string currentNode = "AAA";
	for (int i = 0; currentNode != "ZZZ"; i = (i + 1) % directions.length()) {
		if (directions[i] == 'L') {
			currentNode = maze[currentNode].first;
		} else {
			currentNode = maze[currentNode].second;
		}
		steps++;
	}
	std::cout << steps << std::endl;
}
