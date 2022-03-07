#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
    int from;
    int to;
    int cost;
};

vector<edge> adj[502];
int min_dist[502];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M, W;
        scanf("%d %d %d", &N, &M, &W);
        for (int n = 1; n <= N; n++) adj[n].clear();
        for (int m = 0; m < M; m++) {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);

            adj[s].push_back({s, e, t});
            adj[e].push_back({e, s, t});
        }
        for (int w = 0; w < W; w++) {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);

            adj[s].push_back({s, e, -t});
        }

        memset(min_dist, 0x3f, sizeof(min_dist));
        min_dist[1] = 0;

        bool neg_cycle = false;

        for (int k = 0; k < N; k++) {
            for (int i = 1; i <= N; i++) {
                for (edge e : adj[i]) {
                    int new_dist = min_dist[e.from] + e.cost;
                    if (min_dist[e.to] > new_dist) {
                        min_dist[e.to] = new_dist;

                        if (k == N - 1) {
                            neg_cycle = true;
                        }
                    }
                }
            }
        }

        bool result = neg_cycle;
        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
