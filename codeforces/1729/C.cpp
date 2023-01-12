#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string str;
        cin >> str;

        // l -> c
        // l -> k -> j -> i -> h -> g -> f -> e -> d -> c
        
        // l -> k -> k -> k -> ... -> j -> j -> ...

        int minCost = abs(str.back() - str.front());

        vector<int> indices[26];

        for (int i = 0; str[i]; i++) {
            indices[str[i] - 'a'].push_back(i);
        }

        vector<int> jumps;

        int delta = 1;
        if (str.front() > str.back()) {
            delta = -1;
        }

        for (char cur = str.front();; cur += delta) {
            for (int i : indices[cur - 'a']) {
                jumps.push_back(i);
            }

            if (cur == str.back()) break;
        }

        cout << minCost << ' ' << jumps.size() << '\n';
        for (int i : jumps) {
            cout << (i + 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
