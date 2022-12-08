#include <bits/stdc++.h>

using namespace std;

int ans, n, m = -1;
string s;
int a[1100][1100], v[1100][1100];

int main() {
    freopen("2022/08/08_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        m++;
        n = s.length();

        for (int i = 0; i < n; i++) {
            a[m][i] = s[i] - '0';
        }
    }
    m++;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int a1 = 0;
            for (int l = i - 1; l >= 0; l--) {
                a1++;
                if (a[l][j] >= a[i][j]) break;
            }
            int a2 = 0;
            for (int l = i + 1; l < m; l++) {
                a2++;
                if (a[l][j] >= a[i][j]) break;
            }
            int a3 = 0;
            for (int l = j + 1; l < n; l++) {
                a3++;
                if (a[i][l] >= a[i][j]) break;
            }
            int a4 = 0;
            for (int l = j - 1; l >= 0; l--) {
                a4++;
                if (a[i][l] >= a[i][j]) break;
            }
            ans = max(ans, a1 * a2 * a3 * a4);
        }
    }

    cout << ans << endl;
    return 0;
}
