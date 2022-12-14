#include <bits/stdc++.h>

using namespace std;

int ans, g[1010][1010];
string s, st;

int main() {
    freopen("2022/14/14_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        stringstream ss(s);
        int a, b, x = -1, y;
        char c;
        while (ss >> a >> c >> b) {
            if (x == -1) {
                x = a;
                y = b;
            } else {
                for (; x != a; x < a ? x++ : x--) {
                    g[x][y] = 1;
                }
                for (; y != b; y < b ? y++ : y--) {
                    g[x][y] = 1;
                }
                g[x][y] = 1;
            }
            ss >> st;
        }
    }

    while (true) {
        int x = 500, y = 0;
        if (g[x][y] != 0) {
            break;
        }

        g[x][y] = 2;
        while (true) {
            if (y > 600) break;
            if (g[x][y + 1] == 0) {
                g[x][y + 1] = 2;
                g[x][y] = 0;
                y++;
            } else if (g[x - 1][y + 1] == 0) {
                g[x - 1][y + 1] = 2;
                g[x][y] = 0;
                x--;
                y++;
            } else if (g[x + 1][y + 1] == 0) {
                g[x + 1][y + 1] = 2;
                g[x][y] = 0;
                x++;
                y++;
            } else break;
        }
        if (y > 600) {
            break;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}
