#include <bits/stdc++.h>

using namespace std;

int ans;
string s;
map<tuple<int, int, int>, int> mp;
vector<tuple<int, int, int>> v;

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
    }

    for (auto [a, b, c]: v) {
        ans += (1 - mp[{a - 1, b, c}]) + (1 - mp[{a, b - 1, c}]) + (1 - mp[{a, b, c - 1}]) +
               (1 - mp[{a + 1, b, c}]) + (1 - mp[{a, b + 1, c}]) + (1 - mp[{a, b, c + 1}]);
    }

    cout << ans << endl;
    return 0;
}
