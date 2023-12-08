#include <iostream>

int main() {
			  // Input
	const int	 time		=		 46689866;
	const size_t distance	= 358105418071080;
	int ways = 0;

	int i = time;
	for (int wait = 1; wait <= 42069420; wait++) {
		size_t prod = (size_t)--i * (size_t)wait;
		if (prod > distance) {
			ways = time - wait*2 + 1;
			break;
		}
	}
	std::cout << ways << std::endl;
}
