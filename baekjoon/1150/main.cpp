#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int dists[100005];

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        cin >> dists[n];
    }

    for (int n = 1; n < N; n++) {
        cout << dists[n] - dists[n - 1] << ' ';
    }
    cout << endl;

    cout << 0 << endl;

    return 0;
}
