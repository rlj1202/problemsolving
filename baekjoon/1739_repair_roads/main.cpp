#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int visited[4003];
int visited_cur;
int group[4003];
int group_cur;

stack<int> s;

int dfs(vector<int> *adj, int node) {
    visited[node] = ++visited_cur;
    int lower = visited[node];

    s.push(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            lower = min(lower, dfs(adj, next));
        } else if (!group[next]) {
            lower = min(lower, visited[next]);
        }
    }

    if (lower == visited[node]) {
        group_cur++;

        while (!s.empty()) {
            int popped = s.top();
            s.pop();

            group[popped] = group_cur;

            if (popped == node) break;
        }
    }

    return lower;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        vector<int> adj[4003];

        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);

        for (int k = 0; k < K; k++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            y1 += N;
            y2 += N;

            if (x1 > x2) {
                y1 += N+M;
                y2 += N+M;
            }
            if (y1 > y2) {
                x1 += N+M;
                x2 += N+M;
            }

            int nx1 = (x1 - 1 + N+M) % (2*(N+M)) + 1;
            int ny1 = (y1 - 1 + N+M) % (2*(N+M)) + 1;
            int nx2 = (x2 - 1 + N+M) % (2*(N+M)) + 1;
            int ny2 = (y2 - 1 + N+M) % (2*(N+M)) + 1;

            if (x1 == x2 && y1 == y2) {
                continue;
            } else if (x1 == x2) {
                // (x + x)

                adj[nx1].push_back(x1);
            } else if (y1 == y2) {
                // (y + y)

                adj[ny1].push_back(y1);
            } else {
                //    x2y1 + x1y2
                // => (x2y1 + x1)(x2y1 + y2) (due to distributive property)
                // => (x1 + x2)(x1 + y1)(x2 + y2)(y1 + y2) (due to same rule)

                adj[nx1].push_back(y1);
                adj[ny1].push_back(x1);

                adj[nx2].push_back(y2);
                adj[ny2].push_back(x2);

                adj[ny1].push_back(y2);
                adj[ny2].push_back(y1);

                adj[nx1].push_back(x2);
                adj[nx2].push_back(x1);
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        visited_cur = 0;
        group_cur = 0;

        for (int i = 1; i <= (N + M)*2; i++) {
            if (!visited[i]) dfs(adj, i);
        }

        bool result = true;

        for (int i = 1; i <= N+M; i++) {
            if (group[i] == group[i + N+M]) {
                result = false;
                break;
            }
        }

        printf("%s\n", result ? "Yes" : "No");
    }

    return 0;
}