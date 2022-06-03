#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
	int N;
	std::ifstream Value("input.txt");	
	Value >> N;
	Value.close();

	std::ofstream result("output.txt");
	for (int i = 26; 1 < i + 1; --i) {
		int first_part = pow(2,i - 1) - 1;
		if (N == 1) {
			result << (char)('a' + i - 1);
			return 0;
		}
		else if (N < first_part + 2) {
			N--;
		}
		else {
			N -= 1 + first_part;
		}
	}

	result.close();
	return -1;
}
