#include <bits/stdc++.h>

using namespace std;

int ans, n, m = -1, v = 1, c, d, nx = 20;
string s;

int main() {
    freopen("2022/10/10_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        m++;
        if (s[0] == 'a') d = 2;
        else d = 1;
        if (c + d >= nx) {
            ans += nx * v;
            nx += 40;
        }

        if (s[0] == 'a') {
            cin >> n;
            v += n;
        }
        c += d;
    }

    cout << ans << endl;
    return 0;
}
