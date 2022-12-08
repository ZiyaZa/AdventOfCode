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

    int mx;
    for (int i = 0; i < m; i++) {
        mx = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                v[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        mx = -1;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                v[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        mx = -1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                v[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        mx = -1;
        for (int i = m - 1; i >= 0; i--) {
            if (a[i][j] > mx) {
                mx = a[i][j];
                v[i][j] = 1;
            }
            ans += v[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
