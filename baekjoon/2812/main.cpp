#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    string str;
    cin >> N >> K;
    cin >> str;

    deque<char> dq;

    int remains = K;

    for (int i = 0; i < str.size(); i++) {
        char cur = str[i];
        while (remains && !dq.empty() && dq.back() < cur) {
            remains--;
            dq.pop_back();
        }

        dq.push_back(cur);
    }

    while (remains && !dq.empty()) {
        remains--;
        dq.pop_back();
    }

    for (char c : dq) {
        cout << c;
    }
    cout << '\n';

    return 0;
}
