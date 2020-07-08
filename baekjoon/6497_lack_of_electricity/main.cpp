#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
    int p, q;
    int length;
};

int parent[200005];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;

    parent[A] = B;

    return true;
}

edge edges[200005];

int main() {
    while (true) {
        int M, N;
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        int sum = 0;

        for (int n = 0; n < N; n++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[n] = {x, y, z};
            sum += z;
        }

        for (int m = 0; m < M; m++) {
            parent[m] = m;
        }
        sort(edges, edges + N, [](edge &a, edge &b) -> bool {
            return a.length < b.length;
        });

        int result = 0;
        for (int n = 0; n < N; n++) {
            edge cur = edges[n];
            if (merge(cur.p, cur.q))
                result += cur.length;
        }

        printf("%d\n", sum - result);
    }

    return 0;
}