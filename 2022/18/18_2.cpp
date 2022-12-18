#include <bits/stdc++.h>

using namespace std;

int ans;
string s;
map<tuple<int, int, int>, int> mp, air;
vector<tuple<int, int, int>> v;
tuple<int, int, int> mn, mx;

void dfs(tuple<int, int, int> v) {
    auto [a, b, c] = v;
    if (a < get<0>(mn) || a > get<0>(mx) || b < get<1>(mn) || b > get<1>(mx) || c < get<2>(mn) || c > get<2>(mx))
        return;
    if (air[v] || mp[v]) return;
    air[v] = 1;

    dfs({a - 1, b, c});
    dfs({a, b - 1, c});
    dfs({a, b, c - 1});
    dfs({a + 1, b, c});
    dfs({a, b + 1, c});
    dfs({a, b, c + 1});
}

int main() {
    freopen("2022/18/18_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        regex regex(R"((\d+),(\d+),(\d+))");
        smatch matches;
        regex_search(s, matches, regex);

        int a = stoi(matches[1]);
        int b = stoi(matches[2]);
        int c = stoi(matches[3]);

        mp[{a, b, c}] = 1;
        v.emplace_back(a, b, c);

        mn = {min(get<0>(mn), a - 1), min(get<1>(mn), b - 1), min(get<2>(mn), c - 1)};
        mx = {max(get<0>(mx), a + 1), max(get<1>(mx), b + 1), max(get<2>(mx), c + 1)};
    }

    dfs(mn);

    for (auto [a, b, c]: v) {
        ans += air[{a - 1, b, c}];
        ans += air[{a, b - 1, c}];
        ans += air[{a, b, c - 1}];
        ans += air[{a + 1, b, c}];
        ans += air[{a, b + 1, c}];
        ans += air[{a, b, c + 1}];
    }

    cout << ans << endl;
    return 0;
}
