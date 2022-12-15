#include <bits/stdc++.h>

using namespace std;

int sx, sy, bx, by;
vector<pair<int, int>> v[4000010];
set<int> v2[4000010];

int main() {
    freopen("2022/15/15_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> sx >> sy >> bx >> by) {
        int d = abs(sx - bx) + abs(sy - by);
        for (int i = 0; i <= 4000000; i++) {
            int l = d - abs(i - sy);
            if (l >= 0) v[i].emplace_back(sx - l, sx + l);
            if (by == i) v2[i].insert(bx);
        }
    }

    for (int k = 0; k <= 4000000; k++) {
        sort(v[k].begin(), v[k].end());
        int r = v[k][0].second;
        for (auto& i: v[k]) {
            if (i.first <= r) {
                r = max(r, i.second);
            } else {
                if (r + 1 >= 0 && r + 1 <= 4000000) {
                    cout << 1LL * (r + 1) * 4000000 + k << endl;
                    exit(0);
                }
                r = i.second;
            }
        }
    }

    return 0;
}
