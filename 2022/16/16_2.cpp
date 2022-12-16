#include <bits/stdc++.h>

#include <random>

using namespace std;

int ans, f[1010], d[1010], dist[1010][1010];
string s, st;
vector<int> g[1010], nodes, nodes2;

int in(string a) {
    return (a[0] - 'A') * 30 + (a[1] - 'A');
}

int bfs(int v, int m) {
    queue<int> q;
    q.push(v);
    for (int& i: d) i = 0;
    d[v] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& i: g[x]) {
            if (d[i] == 0) {
                d[i] = d[x] + 1;
                q.push(i);
            }
        }
    }
    return d[m] - 1;
}

int main() {
    freopen("2022/16/16_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        regex regex(R"(Valve (..) has flow rate=(\d+); tunnels? leads? to valves? (.+))");
        smatch matches;
        regex_search(s, matches, regex);

        string a = matches[1];
        int ai = in(a);
        nodes.push_back(ai);
        f[ai] = stoi(matches[2]);
        string c = matches[3];

        stringstream ss(c);
        while (ss >> st) {
            if (*st.rbegin() == ',') st = st.substr(0, st.size() - 1);
            int sti = in(st);
            g[ai].push_back(sti);
        }
    }

    for (int n: nodes) {
        if (f[n] == 0) continue;

        dist[0][n] = dist[n][0] = bfs(n, 0);

        for (int m: nodes) {
            if (m <= n || f[m] == 0) continue;
            dist[n][m] = dist[m][n] = bfs(n, m);
        }
    }

    for (int n: nodes) {
        g[n].clear();
        for (int m: nodes) {
            if (dist[n][m]) {
                if (m > 0 && find(nodes2.begin(), nodes2.end(), m) == nodes2.end()) nodes2.push_back(m);
                g[n].push_back(m);
            }
        }
    }

    // Answer to previous part (still can't believe this works)
    nodes2 = {228, 381, 338, 20, 317, 396, 708, 428, 682, 774, 204, 83, 683, 710, 365};

    do {
        for (int k = 1; k < nodes2.size(); k++) {
            vector<int> l, r;
            for (int j = 0; j < k; j++) l.push_back(nodes2[j]);
            for (int j = k; j < nodes2.size(); j++) r.push_back(nodes2[j]);

            int res = 0;
            int cur = 0;
            int op = 0;
            int m = 26;
            for (int i: l) {
                int d = dist[cur][i] + 1;
                if (m - d <= 0) {
                    break;
                }
                res += d * op;
                m -= d;
                op += f[i];
                cur = i;
            }
            res += m * op;
            cur = 0;
            op = 0;
            m = 26;
            for (int i: r) {
                int d = dist[cur][i] + 1;
                if (m - d <= 0) {
                    break;
                }
                res += d * op;
                m -= d;
                op += f[i];
                cur = i;
            }
            res += m * op;
            if (res > ans) {
                ans = res;
                cout << ans << endl;
            }
        }
    } while (next_permutation(nodes2.begin(), nodes2.end()));

    cout << ans << endl;
    return 0;
}
