#include <bits/stdc++.h>

using namespace std;

int ans, n, hi, hj, ti, tj;
string s;
map<pair<int, int>, int> mp;

void fix() {
    if (-1 <= ti - hi && ti - hi <= 1 && -1 <= tj - hj && tj - hj <= 1) return;

    if (ti == hi) {
        if (tj < hj) {
            tj++;
        } else {
            tj--;
        }
        return;
    }

    if (tj == hj) {
        if (ti < hi) {
            ti++;
        } else {
            ti--;
        }
        return;
    }

    if (ti < hi && tj < hj) ti++, tj++;
    else if (ti > hi && tj < hj) ti--, tj++;
    else if (ti > hi && tj > hj) ti--, tj--;
    else ti++, tj--;
}

int main() {
    freopen("2022/09/09_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            if (s[0] == 'U') {
                hi++;
            } else if (s[0] == 'D') {
                hi--;
            } else if (s[0] == 'L') {
                hj--;
            } else {
                hj++;
            }

            fix();

            if (!mp[{ti, tj}]) {
                mp[{ti, tj}] = 1;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
