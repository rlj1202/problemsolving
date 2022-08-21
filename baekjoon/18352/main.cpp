#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[300005];
int mindist[300005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    for (int m = 0; m < M; m++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
    }

    memset(mindist, 0x3f, sizeof(mindist));

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    mindist[X] = 0;
    pq.push({ mindist[X], X });

    while (!pq.empty()) {
        pii cur = pq.top(); pq.pop();

        if (mindist[cur.second] < cur.first) continue;

        for (int next : adj[cur.second]) {
            int newdist = mindist[cur.second] + 1;

            if (mindist[next] > newdist) {
                mindist[next] = newdist;
                pq.push({ mindist[next], next });
            }
        }
    }

    int cnt = 0;
    for (int n = 1; n <= N; n++) {
        if (mindist[n] != K) continue;
        cout << n << '\n';
        cnt++;
    }
    if (!cnt) cout << "-1\n";

    return 0;
}
