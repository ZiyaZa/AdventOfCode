#include <bits/stdc++.h>

using namespace std;

int n, m = 0;
string s[110];
int isBl[10010][210][210];
vector<vector<tuple<int, int, int>>> all;
vector<pair<int, int>> dir;

void sim(int t) {
    if (t < all.size()) return;

    all.emplace_back();
    for (auto [i, j, d]: all[t - 1]) {
        int ni = i + dir[d].first;
        int nj = j + dir[d].second;

        if (ni == 0) ni = m - 2;
        if (ni == m - 1) ni = 1;
        if (nj == 0) nj = n - 2;
        if (nj == n - 1) nj = 1;

        isBl[t][ni][nj] = 1;
        all[t].emplace_back(ni, nj, d);
    }
}

int bfs(int sti, int stj, int fi, int fj, int t = 1) {
    set<pair<int, int>> q;
    q.emplace(sti, stj);

    for (;; t++) {
        sim(t);

        set<pair<int, int>> nq;
        for (auto [i, j]: q) {
            for (auto [di, dj]: dir) {
                int ni = i + di;
                int nj = j + dj;
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || s[ni][nj] == '#' || isBl[t][ni][nj])
                    continue;

                if (ni == fi && nj == fj) {
                    return t;
                }

                nq.emplace(ni, nj);
            }
        }

        q = nq;
    }
}

int main() {
    freopen("2022/24/24_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    all.emplace_back();
    while (getline(cin, s[m])) {
        n = s[m].length();
        for (int i = 0; i < n; i++) {
            if (s[m][i] == '>') {
                isBl[0][m][i] = 1;
                all[0].emplace_back(m, i, 0);
            } else if (s[m][i] == 'v') {
                isBl[0][m][i] = 1;
                all[0].emplace_back(m, i, 1);
            } else if (s[m][i] == '<') {
                isBl[0][m][i] = 1;
                all[0].emplace_back(m, i, 2);
            } else if (s[m][i] == '^') {
                isBl[0][m][i] = 1;
                all[0].emplace_back(m, i, 3);
            }
        }
        m++;
    }

    dir.emplace_back(0, 1);
    dir.emplace_back(1, 0);
    dir.emplace_back(0, -1);
    dir.emplace_back(-1, 0);
    dir.emplace_back(0, 0);

    int a1 = bfs(0, 1, m - 1, n - 2);
    int a2 = bfs(m - 1, n - 2, 0, 1, a1 + 1);
    cout << bfs(0, 1, m - 1, n - 2, a2 + 1) << endl;
    return 0;
}
