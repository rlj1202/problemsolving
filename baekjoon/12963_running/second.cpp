#include <cstdio>
#include <cstring>

using namespace std;

struct edge {
    int p, q;
    long long weight;
};

const long long MOD = 1e9 + 7;

int N, M;
edge edges[2003];

int parent[2003];

long long result;

int find(int a) {
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b, long long weight) {
    int A = find(a);
    int B = find(b);

    if (A == B)
        return false;

    if ((A == find(0) && B == find(N - 1)) ||
        (A == find(N - 1) && B == find(0))) {
        result += weight;
        result %= MOD;
    } else {
        parent[A] = B;
    }

    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    long long pow = 1;
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[m] = {a, b, pow};

        pow *= 3;
        pow %= MOD;
    }

    memset(parent, -1, sizeof(parent));
    for (int m = 0; m < M; m++) {
        edge cur = edges[M - m - 1];

        merge(cur.p, cur.q, cur.weight);
    }

    printf("%lld\n", result);

    return 0;
}