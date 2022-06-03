#include <algorithm>
#include <iostream>
#include <fstream>

int main()
{
    int N;
    std::ifstream inp("input.txt");
    inp >> N;
    int sum = 0;
    int max = 0;

    for (int i = 0; i < N; ++i) {
        int t;
        inp >> t;
        sum += t;
        max = std::max(max, t);
    }

    std::ofstream res("output.txt");
    res << std::min(sum / 2, sum - max);
    res.close();
    inp.close();
}
