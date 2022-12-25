#include <bits/stdc++.h>

using namespace std;

long long sum;
string in;

long long toInt(const string& s) {
    long long n = s.length();
    long long res = 0;
    for (long long i = n - 1, k = 1; i >= 0; i--, k *= 5) {
        if (s[i] == '=') res -= 2 * k;
        else if (s[i] == '-') res -= k;
        else if (s[i] == '1') res += k;
        else if (s[i] == '2') res += 2 * k;
    }
    return res;
}

string toSNAFU(long long x) {
    string res;
    while (x > 0) {
        int k = x % 5;
        if (k == 0) res += '0';
        else if (k == 1) res += '1', x--;
        else if (k == 2) res += '2', x -= 2;
        else if (k == 3) res += '=', x += 2;
        else if (k == 4) res += '-', x++;

        x /= 5;
    }

    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    freopen("2022/25/25_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, in)) {
        sum += toInt(in);
    }

    cout << toSNAFU(sum) << endl;
    return 0;
}
