#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 500;
const int MAX_V = MAX_N * 2 + 2;

vector<int> adj[MAX_V];

int visited[MAX_V];
int visited_flag;
int conn[MAX_V];

bool dfs(int cur) {
    if (visited[cur] == visited_flag) return false;
    visited[cur] = visited_flag;

    for (int next : adj[cur]) {
        if (!conn[next]) {
            conn[next] = cur;
            return true;
        } else {
            if (dfs(conn[next])) {
                conn[next] = cur;
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int k = 0; k < K; k++) {
        int r, c;
        scanf("%d %d", &r, &c);

        adj[r].push_back(c + MAX_N);
        adj[c + MAX_N].push_back(r);
    }

    for (int n = 1; n <= N; n++) {
        visited_flag++;
        dfs(n);
    }

    int result = 0;

    for (int n = 1; n <= N; n++) {
        if (conn[n + MAX_N]) result++;
    }

    printf("%d\n", result);

    return 0;
}