#include <bits/stdc++.h>

using namespace std;

struct element {
    int pay, day;

    bool operator<(const element &o) const {
        return day < o.day;
    }
};

vector<element> elements;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int pay, day;
        cin >> pay >> day;

        elements.push_back({ pay, day });
    }

    sort(elements.begin(), elements.end());

    for (element &cur : elements) {
        pq.push(cur.pay);

        if ((int) pq.size() > cur.day) {
            pq.pop();
        }
    }

    int sum = 0;

    while (!pq.empty()) {
        sum += pq.top(); pq.pop();
    }

    cout << sum << '\n';

    return 0;
}
