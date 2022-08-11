#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

deque<int> arr[300005];

int segtree[300005 * 4];

void update(int node, int l, int r, int i, int delta) {
    if (i < l || r < i) return;
    if (l == i && i == r) {
        segtree[node] += delta;
        return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, delta);
    update(node * 2 + 1, mid + 1, r, i, delta);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int query(int node, int l, int r, int i, int j) {
    if (r < i || j < l) return 0;
    if (i <= l && r <= j) {
        return segtree[node];
    }

    int mid = (l + r) / 2;
    int result =
        query(node * 2, l, mid, i, j)
        + query(node * 2 + 1, mid + 1, r, i, j);

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        memset(segtree, 0, sizeof(segtree));
        for (int n = 1; n <= N; n++) {
            arr[n].clear();
        }
        for (int n = 0; n < N; n++) {
            int value;
            cin >> value;
            arr[value].push_back(n);
        }

        priority_queue<pii> pq;
        for (int n = 1; n <= N; n++) {
            if (arr[n].size() < 2) continue;

            int earn = arr[n].back() - arr[n].front();
            pq.push({ earn, n });
        }

        ll answer = 0;

        while (!pq.empty()) {
            auto [ cur_earn, n ] = pq.top();
            pq.pop();

            answer += cur_earn - (ll) query(1, 0, N - 1, arr[n].front(), arr[n].back());

            update(1, 0, N - 1, arr[n].front(), 1);
            update(1, 0, N - 1, arr[n].back(), 1);

            arr[n].pop_front();
            arr[n].pop_back();
            if (arr[n].size() >= 2) {
                int earn = arr[n].back() - arr[n].front();
                pq.push({ earn, n });
            }
        }

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
    }

    return 0;
}
