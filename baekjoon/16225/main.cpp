#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> problems;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    problems.resize(N);
    for (int n = 0; n < N; n++) {
        cin >> problems[n].first;
    }
    for (int n = 0; n < N; n++) {
        cin >> problems[n].second;
    }

    sort(problems.begin(), problems.end());

    cout << 0 << '\n';

    return 0;
}
