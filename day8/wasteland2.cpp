#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
	std::ifstream In("test.txt");

	std::string directions;
	std::getline(In, directions);

	std::string line;
	std::getline(In, line); // skip empty line

	std::unordered_map<	std::string,
						std::pair<std::string, std::string> >	maze;
	std::vector<std::string>	routes;
	int steps = 0;
	bool found = true;
	
	while (std::getline(In, line)) {
		maze[line.substr(0, 3)] = std::make_pair(line.substr(7, 3), line.substr(12, 3));
		if(line[2] == 'A') {
			routes.push_back(line.substr(0, 3));
		}
	}
	for (int i = 0; true; i = (i + 1) % directions.length()) {
		for (auto& node: routes) { // Make a step
			if (directions[i] == 'L') {
				node = maze[node].first;
			} else {
				node = maze[node].second;
			}
			if (node[2] != 'Z' && found) {
				found = false;
			}
		}
		steps++;

		if (found) {
			break;
		}
		found = true;
		std::cout << steps << std::endl;
	}
	std::cout << steps << std::endl;
}
