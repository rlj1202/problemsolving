#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct edge {
    int dest;

    long long cap;
    long long flow;

    int inv;
};

const long long MOD = 1e9 + 7;

vector<edge> adj[2003];

int tags[2003];
int curTag;

edge *stack[2003];
int stacki;

bool dfs(int node, int dest) {
    tags[node] = curTag;

    if (node == dest)
        return true;

    for (edge &e : adj[node]) {
        if (tags[e.dest] == curTag)
            continue;
        if (e.cap - e.flow == 0)
            continue;

        stack[stacki++] = &e;
        if (dfs(e.dest, dest))
            return true;
        stacki--;
    }

    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    long long pow = 1;
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back({b, pow, 0, (int)adj[b].size()});
        adj[b].push_back({a, pow, 0, (int)adj[a].size() - 1});
        pow *= 3;
        pow %= MOD;
    }

    long long result = 0;

    while (true) {
        curTag++;
        stacki = 0;

        if (dfs(0, N - 1)) {
            long long minCap = MOD;
            for (int i = 0; i < stacki; i++) {
                minCap = min(minCap, stack[i]->cap - stack[i]->flow);
            }
            result += minCap;
            result %= MOD;

            for (int i = 0; i < stacki; i++) {
                stack[i]->flow += minCap;
                adj[stack[i]->dest][stack[i]->inv].flow -= minCap;
            }
        } else {
            break;
        }
    }

    printf("%lld\n", result);

    return 0;
}