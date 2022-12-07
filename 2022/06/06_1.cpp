#include <bits/stdc++.h>

using namespace std;

int ans, n, m = -1;
string s;
unordered_map<char, int> mp;
vector<char> st[100];

int main() {
    freopen("2022/06/06_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> s;
    for (int i = 3; i < s.length(); i++) {
        mp.clear();
        int ok = 1;
        for (int j = i; j > i - 4; j--) {
            if (mp[s[j]]) {
                ok = 0;
                break;
            }
            mp[s[j]] = 1;
        }

        if (ok) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
