#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<long long, int> pii;

int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
        int N, M, T;
        scanf("%d %d %d", &N, &M, &T);

        int S, G, H;
        scanf("%d %d %d", &S, &G, &H);

        vector<pii> adj[2003];
        vector<int> norms;

        for (int m = 0; m < M; m++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);

            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }

        while (T--) {
            int x;
            scanf("%d", &x);
            norms.push_back(x);
        }
        sort(norms.begin(), norms.end());

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<long long> min_dist(N + 1, 0x3f3f3f3f);
        vector<int> target(N + 1, 0);

        min_dist[S] = 0;
        pq.push({0, S});

        if (S == G) {
            target[S] |= 1;
        }
        if (S == H) {
            target[S] |= 2;
        }

        while (!pq.empty()) {
            pii cur = pq.top();
            pq.pop();

            if (min_dist[cur.second] < cur.first) {
                continue;
            }

            for (pii next : adj[cur.second]) {
                long long next_dist = cur.first + next.first;

                if (min_dist[next.second] >= next_dist) {
                    if (min_dist[next.second] > next_dist) {
                        target[next.second] = target[cur.second];
                    } else {
                        target[next.second] |= target[cur.second];
                    }

                    if (next.second == G) {
                        target[next.second] |= 1;
                    }
                    if (next.second == H) {
                        target[next.second] |= 2;
                    }

                    if (min_dist[next.second] > next_dist) {
                        pq.push({next_dist, next.second});
                    }
                    min_dist[next.second] = next_dist;
                }
            }
        }

        for (int norm : norms) {
            if (target[norm] == 3) {
                printf("%d ", norm);
            }
        }
        printf("\n");
    }

    return 0;
}