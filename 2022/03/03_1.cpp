#include <bits/stdc++.h>

using namespace std;

char a, b;
int ans, n;
string s;
unordered_map<char, int> f;

int main() {
    freopen("2022/03/03_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        f.clear();
        n = s.length();
        for (int i = 0; i < n / 2; i++) {
            f[s[i]] = 1;
        }

        for (int i = n / 2; i < n; i++) {
            if (f[s[i]]) {
                f[s[i]] = 0;
                ans += (s[i] >= 'A' && s[i] <= 'Z' ? s[i] - 'A' + 27 : s[i] - 'a' + 1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
