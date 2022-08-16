#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<pii> lectures;

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        int s, t;
        cin >> s >> t;

        lectures.push_back({ s, t });
    }

    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int n = 0; n < N; n++) {
        auto &[s, t] = lectures[n];

        if (!pq.empty() && pq.top() <= s) {
            pq.pop();
        }

        pq.push(t);
    }

    cout << pq.size() << '\n';

    return 0;
}
