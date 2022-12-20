#include <bits/stdc++.h>

using namespace std;

int n, m = -1;
vector<pair<int, int>> v;

int main() {
    freopen("2022/20/20_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m0;
    while (cin >> n) {
        m++;
        v.emplace_back(n, m);

        if (n == 0) {
            m0 = m;
        }
    }

    vector<pair<int, int>> r = v;
    for (auto [n, i]: v) {
        int j = n;
        auto it = std::find(r.begin(), r.end(), make_pair(n, i));
        int jt = it - r.begin();
        r.erase(it);
        while (j > 0) {
            j--;
            jt++;
            if (jt >= r.size()) {
                jt -= r.size();
            }
        }
        while (j < 0) {
            j++;
            jt--;
            if (jt <= 0) {
                jt += r.size();
            }
        }
        r.emplace(r.begin() + jt, n, i);
    }

    int i = std::find(r.begin(), r.end(), make_pair(0, m0)) - r.begin();
    cout << r[(i + 1000) % r.size()].first + r[(i + 2000) % r.size()].first + r[(i + 3000) % r.size()].first << endl;
    return 0;
}
