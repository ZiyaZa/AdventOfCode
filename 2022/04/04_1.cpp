#include <bits/stdc++.h>

using namespace std;

char a, b;
int ans, n, m = -1;
string s;
unordered_map<char, int> mp;

int main() {
    freopen("2022/04/04_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        m++;
        n = s.length();

        int f1 = s.find('-');
        int f2 = s.find(',', f1 + 1);
        int f3 = s.find('-', f2 + 1);

        int l1 = stoi(s.substr(0, f1));
        int r1 = stoi(s.substr(f1 + 1, f2));

        int l2 = stoi(s.substr(f2 + 1, f3));
        int r2 = stoi(s.substr(f3 + 1));

        if (l1 <= l2 && r2 <= r1) ans++;
        else if (l2 <= l1 && r1 <= r2) ans++;
    }

    cout << ans << endl;
    return 0;
}
