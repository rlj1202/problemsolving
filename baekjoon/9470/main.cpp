#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int K, M, P;
        cin >> K >> M >> P;

        vector<int> indegree(M + 1, 0);
        vector<int> strahler(M + 1, 0);
        vector<int> prev_max(M + 1, 0);
        vector<vector<int>> adj(M + 1);

        for (int p = 0; p < P; p++) {
            // A -> B
            int A, B;
            cin >> A >> B;

            adj[A].push_back(B);

            indegree[B]++;
        }

        queue<int> q;

        for (int m = 1; m <= M; m++) {
            if (indegree[m] == 0) {
                strahler[m] = 1;
                q.push(m);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]) {
                if (prev_max[next] < strahler[cur]) {
                    prev_max[next] = strahler[cur];
                    strahler[next] = strahler[cur];
                } else if (prev_max[next] == strahler[cur]) {
                    strahler[next] = strahler[cur] + 1;
                }

                if ((--indegree[next]) == 0) {
                    q.push(next);
                }
            }
        }

        cout << K << ' ' << strahler[M] << '\n';
    }

    return 0;
}
