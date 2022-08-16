#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

deque<pii> jewels;
vector<int> bags;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    jewels.resize(N);
    bags.resize(K);
    for (int n = 0; n < N; n++) {
        int M, V;
        cin >> M >> V;
        jewels[n] = { M, V };
    }
    for (int k = 0; k < K; k++) {
        int C;
        cin >> C;
        bags[k] = C;
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    ll result = 0;

    priority_queue<pii> pq;

    for (int bag : bags) {
        while (!jewels.empty() && jewels.front().first <= bag) {
            pii &jewel = jewels.front();
            pq.push({ jewel.second, jewel.first });
            jewels.pop_front();
        }

        if (!pq.empty()) {
            pii jewel = pq.top();
            pq.pop();

            result += jewel.first;
        }
    }

    cout << result << '\n';

    return 0;
}
