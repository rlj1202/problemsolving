#include <bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        long long value;
        cin >> value;
        pq.push(value);
    }

    for (int m = 0; m < M; m++) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    long long result = 0;
    while (!pq.empty()) {
        result += pq.top(); pq.pop();
    }

    cout << result << "\n";

    return 0;
}
