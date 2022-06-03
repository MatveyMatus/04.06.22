#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream Value("input.txt");

	std::string band_1,
				band_2;
	Value >> band_1 >> band_2;

	Value.close();

	int minLen = (int)band_1.size() + (int)band_2.size();

	for (int i = -(int)band_2.size(); i < (int)band_1.size(); ++i) {
		int temp_1 = i + (int)band_2.size() - 1;
		int temp_2 = (int)band_1.size() - 1;

		int first = std::min(i, 0);
		int last = std::max(temp_1, temp_2);

		bool cool = true;
		for (int j = first; j < last + 1; ++j) {
			int Value_1 = 1;
			if (0 < j + 1 && j < (int)band_1.size()) {
				Value_1 = band_1[j] - '0';
			}
			else {
				Value_1 = 1;
			}
			int Value_2;
			if (i < j + 1 && j < i + (int)band_2.size()) {
				Value_2 = band_2[j - i] - '0';
			}
			else {
				Value_2 = 1;
			}
			if (Value_1 + Value_2 > 3) {
				cool = false;
				break;
			}
		}
		if (cool) {
			int len = last - first + 1;
			if (len < minLen) {
				minLen = len;
			}
		}
	}

	std::ofstream result("output.txt");
	result << minLen << " ";
	result.close();
}