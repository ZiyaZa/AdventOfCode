#include <bits/stdc++.h>

using namespace std;

int ans, n, m = -1;
string s;
unordered_map<char, int> mp;
vector<char> st[100];

int main() {
    freopen("2022/05/05_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int state = 0;
    while (getline(cin, s)) {
        if (s[1] == '1') {
            state = 1;
            continue;
        }
        m++;
        n = s.length();

        if (!state) {
            for (int i = 0; 4 * i + 1 < n; i++) {
                if (s[4 * i + 1] != ' ') {
                    st[i].insert(st[i].end(), s[4 * i + 1]);
                }
            }
            continue;
        }

        regex regex(R"(move (\d+) from (\d+) to (\d+))");
        smatch matches;
        regex_search(s, matches, regex);

        int a = stoi(matches[1]);
        int b = stoi(matches[2]) - 1;
        int c = stoi(matches[3]) - 1;

        reverse(st[b].begin(), st[b].begin() + a);
        st[c].insert(st[c].begin(), st[b].begin(), st[b].begin() + a);
        st[b].erase(st[b].begin(), st[b].begin() + a);
    }

    for (int i = 0; i < 10; i++) {
        if (!st[i].empty()) cout << st[i][0];
        else cout << ' ';
    }
    cout << endl;
    return 0;
}
