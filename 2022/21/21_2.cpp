#include <bits/stdc++.h>

using namespace std;

string s;
unordered_map<string, string> mp;
unordered_map<string, tuple<string, string, char>> mp2;

string solve(const string& c) {
    if (c == "humn") {
        return c;
    }
    if (mp.contains(c)) {
        return mp[c];
    }

    string ls = solve(get<0>(mp2[c]));
    string rs = solve(get<1>(mp2[c]));
    if (ls.find("humn") != string::npos || rs.find("humn") != string::npos) {
        return mp[c] = "(" + ls + ") " + get<2>(mp2[c]) + " (" + rs + ")";
    }

    long long l = stoll(ls);
    long long r = stoll(rs);
    if (get<2>(mp2[c]) == '+') {
        return mp[c] = to_string((l + r));
    }
    if (get<2>(mp2[c]) == '-') {
        return mp[c] = to_string((l - r));
    }
    if (get<2>(mp2[c]) == '*') {
        return mp[c] = to_string((l * r));
    }
    return mp[c] = to_string((l / r));
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
            mp[a] = matches[2];
        } else {
            string b = matches[3];
            string op = matches[4];
            string c = matches[5];
            mp2[a] = {b, c, op[0]};
        }
    }
    get<2>(mp2["root"]) = '=';

    string ans = solve("root");
    regex regex(R"(humn)");
    ans = regex_replace(ans, regex, "x");
    cout << "Go to https://www.mathpapa.com/equation-solver/ and enter:" << endl << ans << endl;
    return 0;
}
