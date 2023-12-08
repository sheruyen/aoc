#include <iostream>

int main() {
	// Puzzle inputs
	int time[4]     =	{ 46,   68,   98,   66};
	int distance[4] =	{358, 1054, 1807, 1080};

	int ways = 0, result = 1;
	
	for(int i = 0; i < 4; i++) {
		const int half = time[i] / 2;
		for (int wait = 1; wait <= half; wait++) {
			if (wait * --time[i] > distance[i]) {
				ways = (half + 1 - wait) * 2 - 1;
				break;
			}
		}
		result *= ways;
		ways = 0;
	}
	std::cout << result << std::endl;
}
