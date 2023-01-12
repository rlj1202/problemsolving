#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string str;
        cin >> N >> str;

        string answer;

        while (!str.empty()) {
            char cur = str.back();
            str.pop_back();

            int index = 0;

            if (cur == '0') {
                index += str.back() - '0';
                str.pop_back();
                index += (str.back() - '0') * 10;
                str.pop_back();
            } else {
                index = cur - '0';
            }

            index--;

            answer.push_back('a' + index);
        }

        reverse(answer.begin(), answer.end());

        cout << answer << '\n';
    }

    return 0;
}
