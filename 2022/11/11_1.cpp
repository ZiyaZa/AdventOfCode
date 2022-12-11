#include <bits/stdc++.h>

using namespace std;

int n, m = -1, b[100], c[100], d[100];
vector<int> res;
string s, a[100];
char op[100];
vector<int> v[100];

int main() {
    freopen("2022/11/11_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        m++;

        cin >> s >> s;
        while (cin >> n) {
            v[m].push_back(n);
            if (cin.peek() != ',') {
                cin.ignore();
                break;
            }
            cin.ignore();
        }

        getline(cin, s);
        regex regex(R"(Operation: new = old (\*|\+) (\d+|old))");
        smatch matches;
        regex_search(s, matches, regex);
        op[m] = matches[1].str()[0];
        a[m] = matches[2].str();

        getline(cin, s);
        regex = (R"(Test: divisible by (\d+))");
        regex_search(s, matches, regex);
        b[m] = stoi(matches[1]);

        getline(cin, s);
        regex = (R"(If true: throw to monkey (\d+))");
        regex_search(s, matches, regex);
        c[m] = stoi(matches[1]);

        getline(cin, s);
        regex = (R"(If false: throw to monkey (\d+))");
        regex_search(s, matches, regex);
        d[m] = stoi(matches[1]);
        getline(cin, s);
    }

    res.resize(m + 1);
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i <= m; i++) {
            for (int w: v[i]) {
                res[i]++;
                if (op[i] == '*') {
                    if (a[i] == "old") {
                        w *= w;
                    } else {
                        w *= stoi(a[i]);
                    }
                } else {
                    if (a[i] == "old") {
                        w += w;
                    } else {
                        w += stoi(a[i]);
                    }
                }
                w /= 3;

                if (w % b[i] == 0) {
                    v[c[i]].push_back(w);
                } else {
                    v[d[i]].push_back(w);
                }
            }
            v[i].clear();
        }
    }

    std::sort(res.begin(), res.end());
    cout << res[m] * res[m - 1] << endl;
    return 0;
}
