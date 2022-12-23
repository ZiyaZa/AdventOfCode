#include <bits/stdc++.h>

using namespace std;

int n, m = -1;
string s;
set<pair<int, int>> st;
map<pair<int, int>, pair<int, int>> mp;
vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> dir;

int main() {
    freopen("2022/23/23_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dir.push_back({{-1, 0},
                   {-1, -1},
                   {-1, 1}});
    dir.push_back({{1, 0},
                   {1, -1},
                   {1, 1}});
    dir.push_back({{0,  -1},
                   {-1, -1},
                   {1,  -1}});
    dir.push_back({{0,  1},
                   {-1, 1},
                   {1,  1}});

    while (getline(cin, s)) {
        m++;
        n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '#') st.insert({m, i});
        }
    }

    for (int r = 0;; r++) {
        int stop = 1;
        mp.clear();
        for (auto [i, j]: st) {
            int mv = 0;
            for (auto [d1, d2, d3]: dir) {
                auto [di1, dj1] = d1;
                auto [di2, dj2] = d2;
                auto [di3, dj3] = d3;

                if (st.contains({i + di1, j + dj1}) ||
                    st.contains({i + di2, j + dj2}) ||
                    st.contains({i + di3, j + dj3})) {
                    mv = 1;
                    break;
                }
            }

            if (mv) {
                int diri = 0;
                while (true) {
                    if (diri >= dir.size()) break;
                    auto [di1, dj1] = get<0>(dir[diri]);
                    auto [di2, dj2] = get<1>(dir[diri]);
                    auto [di3, dj3] = get<2>(dir[diri]);

                    if (!st.contains({i + di1, j + dj1}) &&
                        !st.contains({i + di2, j + dj2}) &&
                        !st.contains({i + di3, j + dj3})) {
                        break;
                    }
                    diri++;
                }

                if (diri < dir.size()) {
                    auto [di, dj] = get<0>(dir[diri]);
                    if (!mp.contains({i + di, j + dj})) {
                        mp[{i + di, j + dj}] = {i, j};
                    } else {
                        mp[{i + di, j + dj}] = {-1000, -1000};
                    }
                }
            }
        }

        for (auto [to, from]: mp) {
            auto [fi, fj] = from;
            auto [ti, tj] = to;
            if (fi == -1000 && fj == -1000) continue;
            st.erase({fi, fj});
            st.insert({ti, tj});
            stop = 0;
        }

        if (stop) {
            cout << r << endl;
            break;
        }

        dir.push_back(dir[0]);
        dir.erase(dir.begin());
    }
    return 0;
}
