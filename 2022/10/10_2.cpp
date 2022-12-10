#include <bits/stdc++.h>

using namespace std;

int n, m = -1, v = 1, c, d, nx = 20;
char ans[1100];
string s;

int main() {
    freopen("2022/10/10_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        m++;
        if (s[0] == 'a') d = 2;
        else d = 1;

        for (int i = 0; i < d; i++) {
            if (v - 1 <= c % 40 && c % 40 <= v + 1) ans[c] = '#';
            else ans[c] = '.';
            c++;
        }

        if (s[0] == 'a') {
            cin >> n;
            v += n;
        }
    }

    for (int i = 0; i < 300; i++) {
        cout << ans[i];
        if (i % 40 == 39) {
            cout << endl;
        }
    }
    return 0;
}
