#include <bits/stdc++.h>

using namespace std;

int ans, sum;
string s;

int main() {
    freopen("2022/01/01_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        if (s.empty()) {
            ans = max(ans, sum);
            sum = 0;
            continue;
        }

        sum += stoi(s);
    }

    cout << ans << endl;
    return 0;
}
