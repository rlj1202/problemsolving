#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while (true) {
        string line;
        getline(cin, line);
        if (line == ".") break;

        stack<char> s;
        bool valid = true;
        for (int i = 0; line[i]; i++) {
            char c = line[i];

            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    valid = false;
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    valid = false;
                    break;
                }
            }
        }

        if (!s.empty()) valid = false;

        cout << (valid ? "yes" : "no") << '\n';
    }

    cout << '\n';

    return 0;
}
