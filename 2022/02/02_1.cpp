#include <bits/stdc++.h>

using namespace std;

char a, b;
int ans;
string s;

int main() {
    freopen("2022/02/02_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> a >> b) {
        ans += b - 'X' + 1;
        if ((b == 'X' && a == 'C') || (b == 'Y' && a == 'A') || (b == 'Z' && a == 'B')) ans += 6;
        else if (a - 'A' == b - 'X') ans += 3;
    }

    cout << ans << endl;
    return 0;
}
