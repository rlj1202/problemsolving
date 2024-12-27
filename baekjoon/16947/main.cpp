#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[3003];
int visited[3003];
bool in_cycle[3003];
int lens[3003];

int cycle(int prev, int node) {
    visited[node] = visited[prev] + 1;

    int min_v = visited[node] + 1;

    for (int next : adj[node]) {
        if (next == prev)
            continue;

        if (visited[next]) {
            min_v = min(min_v, visited[next]);
            continue;
        }

        min_v = min(min_v, cycle(node, next));
    }

    if (visited[node] >= min_v) {
        in_cycle[node] = true;
    }

    return min_v;
}

void dist(int prev, int node, int len) {
    visited[node] = true;
    lens[node] = len;

    for (int next : adj[node]) {
        if (next == prev)
            continue;
        if (visited[next])
            continue;

        dist(node, next, in_cycle[next] ? 0 : len + 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cycle(0, 1);

    int pivot;
    for (int n = 1; n <= N; n++) {
        if (in_cycle[n]) {
            pivot = n;
            break;
        }
    }

    memset(visited, 0, sizeof(visited));
    dist(0, pivot, 0);

    for (int n = 1; n <= N; n++) {
        printf("%d ", lens[n]);
    }
    printf("\n");

    return 0;
}
