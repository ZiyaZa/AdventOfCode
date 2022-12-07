#include <bits/stdc++.h>

using namespace std;

char a, b;
int ans, n, m = -1;
string s;
unordered_map<char, int> f[3];

int main() {
    freopen("2022/03/03_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        m++;
        f[m % 3].clear();

        n = s.length();
        for (int i = 0; i < n; i++) {
            f[m % 3][s[i]] = 1;
        }

        if (m % 3 == 2) {
            for (int i = 0; i < n; i++) {
                if (f[0][s[i]] && f[1][s[i]]) {
                    ans += (s[i] >= 'A' && s[i] <= 'Z' ? s[i] - 'A' + 27 : s[i] - 'a' + 1);
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
