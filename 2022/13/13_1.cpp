#include <bits/stdc++.h>

using namespace std;

int ans, m = -1;
string s1, s2;

bool isList(string s) {
    if (s[0] != '[') return false;

    int x = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '[') x++;
        if (s[i] == ']') x--;
        if (x == 0) return false;
    }
    return true;
}

int compare(string x, string y) {
    cout << x << " " << y << endl;
    if (x.empty() && y.empty()) {
        return 0;
    }
    if (x.empty()) {
        return 1;
    }
    if (y.empty()) {
        return -1;
    }
    if (!isList(x) && isList(y)) {
        x = '[' + x + ']';
    }
    if (isList(x) && !isList(y)) {
        y = '[' + y + ']';
    }

    if (isList(x) && isList(y)) {
        for (int i = 1, j = 1; i < x.size() - 1 || j < y.size() - 1; i++, j++) {
            string a, b;
            int k = 0;
            while (i < x.size() - 1 && (k > 0 || x[i] != ',')) {
                if (x[i] == '[') k++;
                if (x[i] == ']') k--;
                a += x[i];
                i++;
            }
            k = 0;
            while (j < y.size() - 1 && (k > 0 || y[j] != ',')) {
                if (y[j] == '[') k++;
                if (y[j] == ']') k--;
                b += y[j];
                j++;
            }
            int res = compare(a, b);
            if (res != 0) return res;
        }
        return 0;
    }

    int a = stoi(x);
    int b = stoi(y);
    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
}

int main() {
    freopen("2022/13/13_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s1)) {
        getline(cin, s2);
        m++;

        if (compare(s1, s2) == 1) ans += m + 1;
        getline(cin, s1);
    }

    cout << ans << endl;
    return 0;
}
