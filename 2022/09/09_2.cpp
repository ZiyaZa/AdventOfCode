#include <bits/stdc++.h>

using namespace std;

int ans, n, ti[20], tj[20];
string s;
map<pair<int, int>, int> mp;

void fix(int i) {
    if (-1 <= ti[i] - ti[i - 1] && ti[i] - ti[i - 1] <= 1 && -1 <= tj[i] - tj[i - 1] && tj[i] - tj[i - 1] <= 1) return;

    if (ti[i] == ti[i - 1]) {
        if (tj[i] < tj[i - 1]) {
            tj[i]++;
        } else {
            tj[i]--;
        }
        return;
    }

    if (tj[i] == tj[i - 1]) {
        if (ti[i] < ti[i - 1]) {
            ti[i]++;
        } else {
            ti[i]--;
        }
        return;
    }

    if (ti[i] < ti[i - 1] && tj[i] < tj[i - 1]) ti[i]++, tj[i]++;
    else if (ti[i] > ti[i - 1] && tj[i] < tj[i - 1]) ti[i]--, tj[i]++;
    else if (ti[i] > ti[i - 1] && tj[i] > tj[i - 1]) ti[i]--, tj[i]--;
    else ti[i]++, tj[i]--;
}

int main() {
    freopen("2022/09/09_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> s) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            if (s[0] == 'U') {
                ti[0]++;
            } else if (s[0] == 'D') {
                ti[0]--;
            } else if (s[0] == 'L') {
                tj[0]--;
            } else {
                tj[0]++;
            }

            for (int j = 1; j < 10; j++)
                fix(j);

            if (!mp[{ti[9], tj[9]}]) {
                mp[{ti[9], tj[9]}] = 1;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
