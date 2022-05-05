#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int from, to;
    long long weight;
};

vector<edge> edges;
long long mindist[502];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);

        edges.push_back({a, b, c});
    }

    memset(mindist, 0x3f, sizeof(mindist));

    mindist[1] = 0;

    for (int n = 1; n <= N - 1; n++) {
        for (edge& e : edges) {
            if (mindist[e.from] == INF) continue;

            mindist[e.to] = min(mindist[e.to], mindist[e.from] + e.weight);
        }
    }

    bool negCycle = false;

    for (edge& e : edges) {
        if (mindist[e.from] == INF) continue;

        if (mindist[e.to] > mindist[e.from] + e.weight) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        printf("-1\n");
    } else {
        for (int n = 2; n <= N; n++) {
            printf("%lld\n", mindist[n] == INF ? -1 : mindist[n]);
        }
    }

    return 0;
}
