#include <bits/stdc++.h>

using namespace std;

long long n, m = -1;
vector<pair<long long, long long>> v;

int main() {
    freopen("2022/20/20_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long m0;
    while (cin >> n) {
        n *= 811589153;
        m++;
        v.emplace_back(n, m);

        if (n == 0) {
            m0 = m;
        }
    }

    vector<pair<long long, long long>> r = v;
    for (int t = 0; t < 10; t++) {
        for (auto [n, i]: v) {
            long long j = n;
            auto it = std::find(r.begin(), r.end(), make_pair(n, i));
            long long jt = it - r.begin();
            r.erase(it);
            if (j >= 0) jt = (jt + j) % r.size();
            else jt = (jt + j + 1 + 1000000000000LL * r.size()) % r.size() - 1;

            if (jt == -1) jt = r.size() - 1;
            r.emplace(r.begin() + jt, n, i);
        }
    }

    long long i = std::find(r.begin(), r.end(), make_pair(0LL, m0)) - r.begin();
    cout << r[(i + 1000) % r.size()].first + r[(i + 2000) % r.size()].first + r[(i + 3000) % r.size()].first << endl;
    return 0;
}
