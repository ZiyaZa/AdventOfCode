#include <bits/stdc++.h>

using namespace std;

int m;
string s[210], p;

int main() {
    freopen("2022/22/22_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s[m])) {
        if (s[m].empty()) {
            break;
        }
        m++;
    }
    cin >> p;

    int stj = 0;
    while (s[0][stj] != '.') stj++;

    int curi = 0, curj = stj;
    int diri = 0, dirj = 1, dir = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'L') {
            if (diri == 0 && dirj == 1) {
                diri = -1;
                dirj = 0;
                dir = 3;
            } else if (diri == -1 && dirj == 0) {
                diri = 0;
                dirj = -1;
                dir = 2;
            } else if (diri == 0 && dirj == -1) {
                diri = 1;
                dirj = 0;
                dir = 1;
            } else {
                diri = 0;
                dirj = 1;
                dir = 0;
            }
            continue;
        }
        if (p[i] == 'R') {
            if (diri == 0 && dirj == 1) {
                diri = 1;
                dirj = 0;
                dir = 1;
            } else if (diri == 1 && dirj == 0) {
                diri = 0;
                dirj = -1;
                dir = 2;
            } else if (diri == 0 && dirj == -1) {
                diri = -1;
                dirj = 0;
                dir = 3;
            } else {
                diri = 0;
                dirj = 1;
                dir = 0;
            }
            continue;
        }

        string num;
        while (i < p.length() && isdigit(p[i])) {
            num += p[i];
            i++;
        }
        i--;
        int a = stoi(num);

        while (a > 0) {
            a--;
            int newi = curi + diri;
            int newj = curj + dirj;
            if (newi < 0 || newi >= m || newj < 0 || newj >= s[newi].length() || s[newi][newj] == ' ') {
                do {
                    newi -= diri;
                    newj -= dirj;
                } while (newi >= 0 && newi < m && newj >= 0 && newj < s[newi].length() && s[newi][newj] != ' ');
                newi += diri;
                newj += dirj;
            }

            if (s[newi][newj] == '#') {
                break;
            }
            curi = newi;
            curj = newj;
        }
    }

    cout << (curi + 1) * 1000 + (curj + 1) * 4 + dir << endl;
    return 0;
}
