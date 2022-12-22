#include <bits/stdc++.h>

using namespace std;

int m;
string s[210], p;
map<tuple<int, int, int>, tuple<int, int, int>> mp;

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

    for (int i = 0; i < m; i++) {
        int j = 0;
        while (s[i][j] == ' ') j++;
        j--;

        if (i < 50) {
            mp[{i, j, 2}] = {149 - i, 0, 0};
        } else if (i < 100) {
            mp[{i, j, 2}] = {100, i - 50, 1};
        } else if (i < 150) {
            mp[{i, j, 2}] = {149 - i, 50, 0};
        } else {
            mp[{i, j, 2}] = {0, i - 100, 1};
        }

        j++;
        while (j < s[i].length() && s[i][j] != ' ') j++;

        if (i < 50) {
            mp[{i, j, 0}] = {149 - i, 99, 2};
        } else if (i < 100) {
            mp[{i, j, 0}] = {49, i + 50, 3};
        } else if (i < 150) {
            mp[{i, j, 0}] = {149 - i, 149, 2};
        } else {
            mp[{i, j, 0}] = {149, i - 100, 3};
        }
    }

    for (int j = 0; j < 150; j++) {
        int i = 0;
        while (s[i][j] == ' ') i++;
        i--;

        if (j < 50) {
            mp[{i, j, 3}] = {50 + j, 50, 0};
        } else if (j < 100) {
            mp[{i, j, 3}] = {100 + j, 0, 0};
        } else {
            mp[{i, j, 3}] = {199, j - 100, 3};
        }

        i++;
        while (i < m && j < s[i].length() && s[i][j] != ' ') i++;

        if (j < 50) {
            mp[{i, j, 1}] = {0, j + 100, 1};
        } else if (j < 100) {
            mp[{i, j, 1}] = {j + 100, 49, 2};
        } else {
            mp[{i, j, 1}] = {j - 50, 99, 2};
        }
    }

    int stj = 0;
    while (s[0][stj] != '.') stj++;

    int curi = 0, curj = stj;
    int dir = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'L') {
            dir = (dir + 3) % 4;
            continue;
        }
        if (p[i] == 'R') {
            dir = (dir + 1) % 4;
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
            int diri, dirj;
            if (dir == 0) {
                diri = 0;
                dirj = 1;
            } else if (dir == 1) {
                diri = 1;
                dirj = 0;
            } else if (dir == 2) {
                diri = 0;
                dirj = -1;
            } else {
                diri = -1;
                dirj = 0;
            }

            a--;
            int newi = curi + diri;
            int newj = curj + dirj;
            int newdir = dir;
            if (newi < 0 || newi >= m || newj < 0 || newj >= s[newi].length() || s[newi][newj] == ' ') {
                auto [x, y, z] = mp[{newi, newj, newdir}];
                newi = x;
                newj = y;
                newdir = z;
            }

            if (s[newi][newj] == '#') {
                break;
            }
            curi = newi;
            curj = newj;
            dir = newdir;
        }
    }

    cout << (curi + 1) * 1000 + (curj + 1) * 4 + dir << endl;
    return 0;
}
