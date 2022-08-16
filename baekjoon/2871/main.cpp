#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<char, int> pci;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    string str;
    cin >> N >> str;

    priority_queue<pci, vector<pci>, greater<pci>> letters;

    for (int i = 0; i < str.size(); i++) {
        letters.push({ str[i], i });
    }

    vector<bool> used(N);

    string A;
    string B;
    int back = N - 1;

    for (int i = 0; i < N / 2; i++) {
        while (back >= 0 && used[back]) back--;
        used[back] = true;
        B.push_back(str[back]);

        while (!letters.empty() && used[letters.top().second]) letters.pop();

        auto [ c, index ] = letters.top();

        used[index] = true;
        A.push_back(c);
    }

    bool possible = A < B;

    cout << (possible ? "DA" : "NE") << '\n';
    cout << A << '\n';

    return 0;
}
