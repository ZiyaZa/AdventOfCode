#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int, int, int> key_tt;

struct key_hash : public unary_function<key_tt, size_t> {
    size_t operator()(const key_tt& k) const {
        return (get<0>(k) << 15) + (get<4>(k) << 10) + (get<5>(k) << 5) + (get<6>(k)) +
               (get<1>(k) << 24) + (1uLL * get<2>(k) << 33) + (1uLL * get<3>(k) << 42);
    }
};

int ans;
vector<thread> th;
string s;
unordered_map<key_tt, int, key_hash> mp[35];

int sim(int mpi, int a1, int b1, int c1, int c2, int d1, int d2,
        int m = 24,
        int cura = 0, int curb = 0, int curc = 0,
        int da = 1, int db = 0, int dc = 0) {
    if (m == 0) {
        return 0;
    }

    key_tt key = {m, cura, curb, curc, da, db, dc};
    if (mp[mpi].contains(key)) {
        return mp[mpi][key];
    }

    cura += da;
    curb += db;
    curc += dc;

    if (cura - da >= d1 && curc - dc >= d2) {
        return mp[mpi][key] = m - 1 + sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - d1, curb, curc - d2, da, db, dc);
    }

    int res = 0;
    if (cura - da >= c1 && curb - db >= c2) {
        res = max(res, sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - c1, curb - c2, curc, da, db, dc + 1));
    }
    if (cura - da >= b1) {
        res = max(res, sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - b1, curb, curc, da, db + 1, dc));
    }
    if (cura - da >= a1) {
        res = max(res, sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - a1, curb, curc, da + 1, db, dc));
    }
    res = max(res, sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura, curb, curc, da, db, dc));

    return mp[mpi][key] = res;
}

void simStart(int mpi, int a1, int b1, int c1, int c2, int d1, int d2) {
    int res = sim(mpi, a1, b1, c1, c2, d1, d2);
    mp[mpi].clear();
    ans += mpi * res;

    ostringstream str;
    str << "Finished " << mpi << ". Current ans = " << ans << endl;
    cout << str.str();
}

int main() {
    freopen("2022/19/19_input.txt", "r", stdin);

    while (getline(cin, s)) {
        regex regex(
                R"(Blueprint (\d+): Each ore robot costs (\d+) ore\. Each clay robot costs (\d+) ore\. Each obsidian robot costs (\d+) ore and (\d+) clay\. Each geode robot costs (\d+) ore and (\d+) obsidian\.)");
        smatch matches;
        regex_search(s, matches, regex);

        int a = stoi(matches[1]);
        int b = stoi(matches[2]);
        int c = stoi(matches[3]);
        int d = stoi(matches[4]);
        int e = stoi(matches[5]);
        int f = stoi(matches[6]);
        int g = stoi(matches[7]);

        th.emplace_back(simStart, a, b, c, d, e, f, g);
    }

    for (auto& thr: th) {
        thr.join();
    }

    cout << ans << endl;
    return 0;
}
