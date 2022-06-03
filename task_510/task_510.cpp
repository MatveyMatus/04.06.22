#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int N;
    std::ifstream Value("input.txt");
    std::ofstream result("output.txt");

    Value >> N;
    Value.close();

    if (N % 2 == 1) {
        result << 0;
        return 0;
    }

    std::vector<int> Arr(N+1);
    Arr[0] = 1;

    for (int i = 2; i < N + 1; ++i) {
        Arr[i] = Arr[i - 2] * 3;
        for (int j = i - 4; j + 1 > 0; j -= 2) {
            Arr[i] += Arr[j] * 2;
        }
    }

    result << Arr[N];
    result.close();
}

