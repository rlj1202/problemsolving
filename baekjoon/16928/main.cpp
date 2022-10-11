#include <bits/stdc++.h>

using namespace std;

vector<int> adj[102];
int visited[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int m = 0; m < M; m++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    deque<int> q;
    q.push_front(1);
    visited[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        // snakes and ladders
        for (int next : adj[cur]) {
            q.push_front(next);

            if (visited[next] == 0 || visited[next] > visited[cur]) {
                visited[next] = visited[cur];
            }
        }

        if (adj[cur].size()) continue;

        // roll the dice
        for (int d = 1; d <= 6; d++) {
            int next = cur + d;
            if (next > 100) continue;

            if (visited[next] == 0 || visited[cur] + 1 < visited[next]) {
                q.push_back(next);
                visited[next] = visited[cur] + 1;
            }
        }
    }

    cout << visited[100] - 1 << '\n';

    return 0;
}
