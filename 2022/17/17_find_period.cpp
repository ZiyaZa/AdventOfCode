#include <bits/stdc++.h>

using namespace std;

int ans[110000], a[10000010][10], f[5][5][5];
string s;

int check_collision(int i, int j, int sh) {
    if (i < 0 || j < 0) return 1;

    for (int x = i; x < i + 5; x++) {
        for (int y = j; y < j + 5; y++) {
            if (!f[sh][x - i][y - j]) continue;
            if (y >= 7 || a[x][y]) return 1;
        }
    }
    return 0;
}

#define NN 50

struct conf {
    int i;
    int sh;
    int j;
    int a1[NN][10];
    int a2[NN][10];

    bool operator<(const conf& other) const {
        if (sh != other.sh) return sh < other.sh;
        if (j != other.j) return j < other.j;
        for (int i = 0; i < NN; i++) {
            for (int j = 0; j < 10; j++) {
                if (a1[i][j] != other.a1[i][j]) return a1[i][j] < other.a1[i][j];
            }
        }
        for (int i = 0; i < NN; i++) {
            for (int j = 0; j < 10; j++) {
                if (a2[i][j] != other.a2[i][j]) return a2[i][j] < other.a2[i][j];
            }
        }
        return false;
    }
};

set<conf> confs;

int main() {
    freopen("2022/17/17_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    f[0][0][0] = 1;
    f[0][0][1] = 1;
    f[0][0][2] = 1;
    f[0][0][3] = 1;

    f[1][0][1] = 1;
    f[1][1][0] = 1;
    f[1][1][1] = 1;
    f[1][1][2] = 1;
    f[1][2][1] = 1;

    f[2][0][0] = 1;
    f[2][0][1] = 1;
    f[2][0][2] = 1;
    f[2][1][2] = 1;
    f[2][2][2] = 1;

    f[3][0][0] = 1;
    f[3][1][0] = 1;
    f[3][2][0] = 1;
    f[3][3][0] = 1;

    f[4][0][0] = 1;
    f[4][0][1] = 1;
    f[4][1][0] = 1;
    f[4][1][1] = 1;

    getline(cin, s);
    int j = 0;
    int mxi = -1;
    for (int i = 0;; i++) {
        int sh = i % 5;
        int curi = mxi + 4;
        int curj = 2;

        conf c;
        c.sh = sh;
        c.j = j;
        c.i = i;
        for (int i = mxi; i > mxi - NN && i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                c.a1[mxi - i][j] = a[i][j];
            }
        }

        while (true) {
            int oldj = curj;
            if (s[j] == '<') curj--;
            else curj++;
            if (check_collision(curi, curj, sh)) {
                curj = oldj;
            }
            j = (j + 1) % s.length();

            curi--;
            if (check_collision(curi, curj, sh)) {
                curi++;
                for (int x = curi; x < curi + 5; x++) {
                    for (int y = curj; y < curj + 5; y++) {
                        if (!f[sh][x - curi][y - curj]) continue;
                        a[x][y] = sh + 1;
                        mxi = max(mxi, x);
                    }
                }
                break;
            }
        }
        ans[i] = mxi + 1;

        for (int i = mxi; i > mxi - NN && i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                c.a2[mxi - i][j] = a[i][j];
            }
        }

        auto it = confs.find(c);
        if (it != confs.end()) {
            cout << "repeat_start = " << i << endl;
            cout << "repeat_period = " << i - it->i << endl;
            cout << "ans_diff = " << ans[i] - ans[it->i] << endl;
            exit(0);
        } else {
            confs.insert(c);
        }
    }
}
