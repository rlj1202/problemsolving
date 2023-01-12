#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string str;
    cin >> str;

    string answer;

    int i = 0;
    while (str[i]) {
        if (str[i] == '%') {
            i++;

            char c;
            if (str.compare(i, 2, "20") == 0) {
                c = ' ';
            } else if (str.compare(i, 2, "21") == 0) {
                c = '!';
            } else if (str.compare(i, 2, "24") == 0) {
                c = '$';
            } else if (str.compare(i, 2, "25") == 0) {
                c = '%';
            } else if (str.compare(i, 2, "28") == 0) {
                c = '(';
            } else if (str.compare(i, 2, "29") == 0) {
                c = ')';
            } else if (str.compare(i, 2, "2a") == 0) {
                c = '*';
            }

            answer.push_back(c);
            i += 2;
        } else {
            answer.push_back(str[i++]);
        }
    }

    cout << answer << '\n';

    return 0;
}
