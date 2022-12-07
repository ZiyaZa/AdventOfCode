#include <bits/stdc++.h>

using namespace std;

int sum;
set<int> ans;
string s;

int main() {
    freopen("2022/01/01_input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (getline(cin, s)) {
        if (s.empty()) {
            ans.insert(sum);
            sum = 0;
            continue;
        }

        sum += stoi(s);
    }

    auto it = ans.rbegin();
    cout << *(it++) + *(it++) + *(it++) << endl;
    return 0;
}
