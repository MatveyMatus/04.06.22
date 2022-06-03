#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct Point{
	int x;
	int y;
};

int main()
{
	double R;
	int monument_X, monument_Y;
	
	std::ifstream Value("input.txt");
	Value >> monument_X >> monument_Y >> R;

	int quantity;
	Value >> quantity;

	std::vector<Point> people;
	for (int i = 0; i < quantity; ++i) {
		int x, y;
		Value >> x >> y;
		x -= monument_X;
		y -= monument_Y;
		
		if (std::sqrt(x * x + y * y) <= R) {
			people.push_back(Point{x,y});
		}
	}
	Value.close();

	int result = 0;
	for (Point people1 : people) {
		int n = 0;
		int left = 0;
		int right = 0;
		for (Point people2 : people) {
			int p = people1.x * people2.y - people2.x * people1.y;
			if (p < 0) {
				left++;
			}
			else if (p > 0) {
				right++;
			}
			else {
				n++;
			}
		}
		result = std::max({ result, n + left, n + right });
	}
	std::ofstream res("output");
	res << result;
	res.close();
}

