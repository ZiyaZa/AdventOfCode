#include <bits/stdc++.h>

using namespace std;

int ans, sx, sy, bx, by;
vector<pair<int, int>> v;
set<int> v2;

int main() {
    freopen("2022/15/15_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> sx >> sy >> bx >> by) {
        int d = abs(sx - bx) + abs(sy - by);
        int l = d - abs(2000000 - sy);
        if (l >= 0) v.emplace_back(sx - l, sx + l);
        if (by == 2000000) v2.insert(bx);
    }

    sort(v.begin(), v.end());

    int l = v[0].first, r = v[0].second;
    for (auto& i: v) {
        if (i.first <= r) {
            r = max(r, i.second);
        } else {
            ans += r - l + 1;
            for (auto& j: v2) {
                if (j >= l && j <= r) ans--;
            }
            l = i.first;
            r = i.second;
        }
    }
    ans += r - l + 1;
    for (auto& j: v2) {
        if (j >= l && j <= r) ans--;
    }

    cout << ans << endl;
    return 0;
}
