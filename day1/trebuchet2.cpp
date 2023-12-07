#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

std::pair<size_t, size_t> findOccurenceBounds(const std::string& line, const std::string& word) {
    size_t leftmostIndex = line.find(word);
	size_t rightmostIndex = 0; 

	if (leftmostIndex == std::string::npos) {		// if the word is not found in the line
		return std::pair<size_t, size_t>(420, 0);
	} else {										// if the word is found in the line
		rightmostIndex = leftmostIndex + word.length();
		size_t i = rightmostIndex;

		while (i != std::string::npos) {
			i = line.find(word, rightmostIndex);
			if (i != std::string::npos) {			// if the word is found more than once
				rightmostIndex += word.length();
			}
		}
		return std::pair<size_t, size_t>(leftmostIndex, rightmostIndex);
	}
}
int main() {
	std::ifstream In("input.txt");
	char a = 0, b = 0, atemp = 0, btemp = 0;
	int sum = 0;

	std::string line;

	const std::vector<std::string> words = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	std::pair<size_t, size_t> occurenceBoundsRecord = std::pair<size_t, size_t>(420, 0);

	while (std::getline(In, line)) {
		for(int i = 0; i < 9; i++) {
			auto occurenceBounds = findOccurenceBounds(line, words[i]);
			if (occurenceBounds.first < occurenceBoundsRecord.first) {
				occurenceBoundsRecord.first = occurenceBounds.first;
				atemp = i + 1 + '0';
			}
			if (occurenceBounds.second > occurenceBoundsRecord.second) {
				occurenceBoundsRecord.second = occurenceBounds.second;
				btemp = i + 1 + '0';
			}
		}
		int lastIndex = line.length() - 1;
		for (int i = 0; i < line.length(); i++) {
			if (a == 0) {							// if first not found yet
				if (line[i] >= '1' && line[i] <= '9') {
					if (i < occurenceBoundsRecord.first) {
						a = line[i];
					} else {
						a = atemp;
					}
				}
			}
			if (b == 0) {							// if last not found yet
				if (line[lastIndex - i] >= '1' && line[lastIndex - i] <= '9') {
					if (lastIndex - i >= occurenceBoundsRecord.second) {
						b = line[lastIndex - i];
					} else {
						b = btemp;
					}
				}
			}
			if (a!= 0 && b!= 0) {					// both were found
				break;
			}
		}
		if (a == 0 && b == 0) {
			a = atemp;
			b = btemp;
		}
		sum += (a - '0')*10 + (b - '0');

		std::cout << line << std::endl;
		std::cout << a << b << std::endl;
		std::cout << sum << std::endl;
	
		a = 0;
		b = 0;
		occurenceBoundsRecord = std::pair<size_t, size_t>(420, 0);
	}
	std::cout << sum << std::endl;
}

