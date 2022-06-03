#include <functional>
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    int N, s;
    std::ifstream inp("input.txt");
    inp >> N >> s;

    std::vector<std::vector<bool>> friends(N + 1, std::vector<bool>(N + 1));

    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            int t;
            inp >> t;
            if (t == 1) {
                friends[i][j] = t;
            }                    
        }
    }
    inp.close();

    int result = 0;
    std::vector<bool> visit(N + 1, false);
    std::function<void(int)> vis = [&](int cur) {
        if (visit[cur]) {
            return 0;
        }
        visit[cur] = true;
        result++;
        for (int p = 1; p < N + 1; ++p) {
            if (friends[cur][p]) {
                vis(p);
            }
        }
    };

    vis(s);

    std::ofstream res("output.txt");
    res << result - 1;
    res.close();
}
