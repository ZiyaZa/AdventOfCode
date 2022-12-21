


#include <bits/stdc++.h>

using namespace std;

string s;
unordered_map<string, long long> mp;
unordered_map<string, tuple<string, string, char>> mp2;

long long solve(const string& c) {
    if (mp.contains(c)) {
        return mp[c];
    }

    long long l = solve(get<0>(mp2[c]));
    long long r = solve(get<1>(mp2[c]));
    if (get<2>(mp2[c]) == '+') {
        return mp[c] = l + r;
    } else if (get<2>(mp2[c]) == '-') {
        return mp[c] = l - r;
    } else if (get<2>(mp2[c]) == '*') {
        return mp[c] = l * r;
    } else if (get<2>(mp2[c]) == '/') {
        return mp[c] = l / r;
    }
}

int main() {
    freopen("2022/21/21_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        regex regex(R"((....): (\d+|(....) (\+|-|\*|/) (....)))");
        smatch matches;
        regex_search(s, matches, regex);

        string a = matches[1];
        if (isdigit(matches[2].str()[0])) {
            int b = stoi(matches[2]);
            mp[a] = b;
        } else {
            string b = matches[3];
            string op = matches[4];
            string c = matches[5];
            mp2[a] = {b, c, op[0]};
        }
    }

    cout << solve("root") << endl;
    return 0;
}
