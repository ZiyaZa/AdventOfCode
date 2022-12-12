#include <bits/stdc++.h>

using namespace std;

int ans = 1000, n, m = -1, a[100][100], sti, stj, fi, fj, u[100][100];
string s;

void dfs(int i, int j, int d = 0) {
    if (u[i][j] != -1 && u[i][j] <= d) return;
    u[i][j] = d;

    if (i == fi && j == fj) {
        ans = min(ans, d);
        return;
    }

    if (i + 1 < n && a[i + 1][j] <= a[i][j] + 1) dfs(i + 1, j, d + 1);
    if (i - 1 >= 0 && a[i - 1][j] <= a[i][j] + 1) dfs(i - 1, j, d + 1);
    if (j + 1 < n && a[i][j + 1] <= a[i][j] + 1) dfs(i, j + 1, d + 1);
    if (j - 1 >= 0 && a[i][j - 1] <= a[i][j] + 1) dfs(i, j - 1, d + 1);
}

int main() {
    freopen("2022/12/12_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        m++;
        n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'S') {
                sti = m;
                stj = i;
                s[i] = 'a';
            } else if (s[i] == 'E') {
                fi = m;
                fj = i;
                s[i] = 'z';
            }
            a[m][i] = s[i] - 'a';
            u[m][i] = -1;
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = -1;
        }
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
