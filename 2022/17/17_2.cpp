#include <bits/stdc++.h>

using namespace std;

int ans[110000], a[1000010][10], f[5][5][5];
string s;

int check_collision(int i, int j, int sh) {
    if (i < 0 || j < 0) return 1;

    for (int x = i; x < i + 5; x++) {
        for (int y = j; y < j + 5; y++) {
            if (!f[sh][x - i][y - j]) continue;
            if (y >= 7 || a[x][y]) return 1;
        }
    }
    return 0;
}

int main() {
    freopen("2022/17/17_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    f[0][0][0] = 1;
    f[0][0][1] = 1;
    f[0][0][2] = 1;
    f[0][0][3] = 1;

    f[1][0][1] = 1;
    f[1][1][0] = 1;
    f[1][1][1] = 1;
    f[1][1][2] = 1;
    f[1][2][1] = 1;

    f[2][0][0] = 1;
    f[2][0][1] = 1;
    f[2][0][2] = 1;
    f[2][1][2] = 1;
    f[2][2][2] = 1;

    f[3][0][0] = 1;
    f[3][1][0] = 1;
    f[3][2][0] = 1;
    f[3][3][0] = 1;

    f[4][0][0] = 1;
    f[4][0][1] = 1;
    f[4][1][0] = 1;
    f[4][1][1] = 1;

    getline(cin, s);
    int j = 0;
    int mxi = -1;
    // 2043 comes from 17_find_period.cpp
    for (int i = 0; i < 2043; i++) {
        int sh = i % 5;
        int curi = mxi + 4;
        int curj = 2;

        while (true) {
            int oldj = curj;
            if (s[j] == '<') curj--;
            else curj++;
            if (check_collision(curi, curj, sh)) {
                curj = oldj;
            }
            j = (j + 1) % s.length();

            curi--;
            if (check_collision(curi, curj, sh)) {
                curi++;
                for (int x = curi; x < curi + 5; x++) {
                    for (int y = curj; y < curj + 5; y++) {
                        if (!f[sh][x - curi][y - curj]) continue;
                        a[x][y] = sh + 1;
                        mxi = max(mxi, x);
                    }
                }
                break;
            }
        }
        ans[i] = mxi + 1;
    }

    long long k = 999999999999;
    long long res = 0;
    while (true) {
        // These magic values come from 17_find_period.cpp
        if (k > 2042) {
            res += 2582;
            k -= 1705;
        } else {
            res += ans[k];
            break;
        }
    }

    cout << res << endl;
    return 0;
}
