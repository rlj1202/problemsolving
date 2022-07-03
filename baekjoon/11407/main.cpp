#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SRC = 0;
const int SINK = 200 + 1;

int cap[202][202];
int flow[202][202];
int costs[202][202];

int mincost[202];
int path[202];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int n = 1; n <= N; n++) {
        int wants;
        cin >> wants;

        cap[SRC][n] = wants;
    }
    for (int m = 1; m <= M; m++) {
        int books;
        cin >> books;

        cap[m + 100][SINK] = books;
    }
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            int max_book;
            cin >> max_book;

            cap[n][m + 100] = max_book;
        }
    }
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            int cost;
            cin >> cost;

            costs[n][m + 100] = cost;
            costs[m + 100][n] = -cost;
        }
    }

    int maxflow = 0;
    int mincost_sum = 0;

    while (true) {
        memset(path, -1, sizeof(path));
        memset(mincost, 0x3f, sizeof(mincost));

        queue<int> q;
        vector<bool> inqueue(202, false);
        mincost[SRC] = 0;
        inqueue[SRC] = true;
        q.push(SRC);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inqueue[cur] = false;

            for (int next = SRC; next <= SINK; next++) {
                int remains = cap[cur][next] - flow[cur][next];
                if (remains <= 0) continue;

                int newcost = mincost[cur] + costs[cur][next];
                if (mincost[next] > newcost) {
                    mincost[next] = newcost;
                    path[next] = cur;
                    if (!inqueue[next]) {
                        inqueue[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        if (path[SINK] == -1) {
            break;
        }

        int minflow = 0x3f3f3f3f;
        for (int cur = SINK; cur != SRC; cur = path[cur]) {
            minflow = min(minflow, cap[path[cur]][cur] - flow[path[cur]][cur]);
        }

        for (int cur = SINK; cur != SRC; cur = path[cur]) {
            flow[path[cur]][cur] += minflow;
            flow[cur][path[cur]] -= minflow;

            mincost_sum += minflow * costs[path[cur]][cur];
        }

        maxflow += minflow;
    }

    cout << maxflow << '\n';
    cout << mincost_sum << '\n';

    return 0;
}
