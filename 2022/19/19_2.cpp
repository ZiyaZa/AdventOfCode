#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int, int, int> key_tt;

struct key_hash : public unary_function<key_tt, size_t> {
    size_t operator()(const key_tt& k) const {
        return (get<0>(k) << 18) + (get<4>(k) << 12) + (get<5>(k) << 6) + (get<6>(k)) +
               (get<1>(k) << 28) + (1uLL * get<2>(k) << 38) + (1uLL * get<3>(k) << 48);
    }
};

int ans = 1;
vector<thread> th;
string s;
unordered_map<key_tt, int, key_hash> mp[35];
shared_mutex mp_mutex[35];

int sim(int mpi, int a1, int b1, int c1, int c2, int d1, int d2,
        int m = 32,
        int cura = 0, int curb = 0, int curc = 0,
        int da = 1, int db = 0, int dc = 0) {
    if (m == 0) {
        return 0;
    }

    key_tt key = {m, cura, curb, curc, da, db, dc};
    {
        shared_lock<shared_mutex> lock(mp_mutex[mpi]);
        if (mp[mpi].contains(key)) {
            return mp[mpi][key];
        }
    }

    cura += da;
    curb += db;
    curc += dc;

    int res = 0;
    if (cura - da >= d1 && curc - dc >= d2) {
        res = m - 1 + sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - d1, curb, curc - d2, da, db, dc);
    } else {
        int ress[4];
        ress[0] = ress[1] = ress[2] = ress[3] = -1;
        if (m > 26) {
            vector<thread> t;
            if (cura - da >= c1 && curb - db >= c2) {
                t.emplace_back([&]() {
                    ress[0] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - c1, curb - c2, curc, da, db, dc + 1);
                });
            }
            if (cura - da >= b1) {
                t.emplace_back([&]() {
                    ress[1] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - b1, curb, curc, da, db + 1, dc);
                });
            }
            if (cura - da >= a1) {
                t.emplace_back([&]() {
                    ress[2] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - a1, curb, curc, da + 1, db, dc);
                });
            }
            t.emplace_back([&]() {
                ress[3] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura, curb, curc, da, db, dc);
            });

            for (auto& thr: t) {
                thr.join();
            }
        }

        if (cura - da >= c1 && curb - db >= c2) {
            if (ress[0] == -1)
                ress[0] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - c1, curb - c2, curc, da, db, dc + 1);
            res = max(res, ress[0]);
        }
        if (cura - da >= b1) {
            if (ress[1] == -1) ress[1] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - b1, curb, curc, da, db + 1, dc);
            res = max(res, ress[1]);
        }
        if (cura - da >= a1) {
            if (ress[2] == -1) ress[2] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura - a1, curb, curc, da + 1, db, dc);
            res = max(res, ress[2]);
        }
        if (ress[3] == -1) ress[3] = sim(mpi, a1, b1, c1, c2, d1, d2, m - 1, cura, curb, curc, da, db, dc);
        res = max(res, ress[3]);
    }

    unique_lock<shared_mutex> lock(mp_mutex[mpi]);
    return mp[mpi][key] = res;
}

void simStart(int mpi, int a1, int b1, int c1, int c2, int d1, int d2) {
    int res = sim(mpi, a1, b1, c1, c2, d1, d2);
    mp[mpi].clear();
    ans *= res;

    ostringstream str;
    str << "Finished " << mpi << ". Current ans = " << ans << endl;
    cout << str.str();
}

int main() {
    freopen("2022/19/19_2_input.txt", "r", stdin);

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

    for (int i = 0; i < th.size(); i++) {
        th[i].join();
    }

    cout << ans << endl;
    return 0;
}
