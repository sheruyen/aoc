#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream In("input.txt");
	char a = 0;
	char b = 0;
	int sum = 0;
	std::string line;

	while (std::getline(In, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (a == 0) { // if first not found yet
				if (line[i] >= '0' && line[i] <= '9') {
					a = line[i];
				}
			}
			if (b == 0) { // if last not found yet
				if (line[line.length() - 1 - i] >= '0' && line[line.length() - 1 - i] <= '9') {
					b = line[line.length() - 1 - i];
				}
			}
			if (a!= 0 && b!= 0) { // both were found
				sum += (a - '0')*10 + (b - '0');
				break;
			}
		}
		a = 0;
		b = 0;
	}
	std::cout << sum << std::endl;
}

/*

1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

*/
