#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[400005];
int degree[400005];

int q[400005];
int l, r;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        memset(degree, 0, sizeof(degree));
        l = r = 0;
        for (int n = 1; n <= N; n++) adj[n].clear();

        for (int n = 0; n < N - 1; n++) {
            int u, v;
            scanf("%d %d", &u, &v);

            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        for (int n = 1; n <= N; n++) {
            if (degree[n] <= 1) {
                q[r++] = n;
            }
        }

        int result = 0;

        for (int k = 0; k < K; k++) {
            if (r - l == 0) break;

            result += r - l;

            int cur_r = r;
            while (cur_r - l > 0) {
                int cur = q[l++];

                for (int next : adj[cur]) {
                    if (--degree[next] == 1) {
                        q[r++] = next;
                    }
                }
            }
        }

        printf("%d\n", N - result);
    }

    return 0;
}
