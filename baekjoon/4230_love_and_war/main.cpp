#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

int visited[102];
int visited_cur;
int group[102];
int group_cur;

bool results[102];

stack<int> s;
stack<int> dag;

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

            dag.push(popped);

            group[popped] = group_cur;

            if (popped == node) break;
        }
    }

    return lower;
}

int main() {
    int N, M;
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        vector<int> adj[102];

        for (int m = 0; m < M; m++) {
            int i, j;
            char a, b;
            scanf("%d%c %d%c", &i, &a, &j, &b);

            // (h, w) = false
            // (w, h) = true

            if (a == 'w') {
                i += N;
            }
            if (b == 'w') {
                j += N;
            }

            int ni = (i + N) % (N*2);
            int nj = (j + N) % (N*2);

            //    (i_a * j_b)!
            // => (i_a! + j_b!)
            // => i_a -> j_b!
            //    j_b -> i_a!
            //
            // h! = w

            adj[i].push_back(nj);
            adj[j].push_back(ni);
        }

        adj[N].push_back(0);

        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        visited_cur = group_cur = 0;

        for (int n = 0; n < N*2; n++) {
            if (!visited[n]) dfs(adj, n);
        }

        bool possible = true;

        for (int n = 0; n < N; n++) {
            if (group[n] == group[n + N]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            memset(results, 0, sizeof(results));

            while (!dag.empty()) {
                int cur = dag.top();
                dag.pop();

                int ncur = (cur + N) % (N*2);

                if (results[cur] == false) {
                    results[ncur] = true;
                }
            }

            for (int n = 1; n < N; n++) {
                printf("%d%c ", n, "hw"[results[n]]);
            }
            printf("\n");
        } else {
            printf("bad luck\n");
        }
    }

    return 0;
}