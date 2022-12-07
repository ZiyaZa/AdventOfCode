#include <bits/stdc++.h>

using namespace std;

int ans = 100000010, n, m = -1;
string s;
unordered_map<string, int> sz;
unordered_map<string, vector<string>> tree;
unordered_map<string, int> res;
vector<string> cur;

void solve(string p) {
    for (auto cf: tree[p]) {
        solve(p + cf + '/');
        res[p] += res[p + cf + '/'];
    }
}

void solve2(string p) {
    for (auto cf: tree[p]) {
        solve2(p + cf + '/');
    }

    if (30000000 + res["//"] - res[p] <= 70000000) {
        ans = min(ans, res[p]);
    }
}

int main() {
    freopen("2022/07/07_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int state = 0;
    while (getline(cin, s)) {
        n = s.length();

        string path = "";
        for (auto c: cur) {
            path += c + "/";
        }

        if (s[0] == '$') {
            if (s[2] == 'c') {
                // cd
                string f = s.substr(5);
                if (f == "/") {
                    cur.clear();
                    cur.emplace_back("/");
                } else if (f == "..") {
                    cur.pop_back();
                } else {
                    if (std::find(tree[path].begin(), tree[path].end(), f) ==
                        tree[path].end()) {
                        tree[path].push_back(f);
                    }
                    cur.push_back(f);
                }
            }
            continue;
        }

        if (isdigit(s[0])) {
            regex regex(R"((\d+) ([a-z\.]+))");
            smatch matches;
            regex_search(s, matches, regex);

            int a = stoi(matches[1]);
            string b = matches[2];
            sz[b] = a;
            res[path] += a;
            continue;
        }
    }

    solve("//");

    solve2("//");

    cout << ans << endl;
    return 0;
}
