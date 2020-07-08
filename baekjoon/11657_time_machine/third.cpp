#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int p, q;
    long long weight;
};

edge edges[6003];

long long distances[502];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[m] = {a, b, c};
    }

    memset(distances, 0x3f, sizeof(distances));
    distances[1] = 0;

    for (int n = 1; n <= N; n++) {
        for (int m = 0; m < M; m++) {
            edge cur = edges[m];
            if (distances[cur.p] == INF)
                continue;

            long long newDist = distances[cur.p] + cur.weight;
            if (distances[cur.q] > newDist) {
                distances[cur.q] = newDist;

                if (n == N) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    for (int n = 2; n <= N; n++) {
        printf("%ld\n", distances[n] == INF ? -1 : distances[n]);
    }

    return 0;
}