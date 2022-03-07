#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
    int id;
    int node;
};

vector<edge> adj[100005];
int numbers[100005];

int main() {
    int N; // 2, 1e5
    scanf("%d", &N);
    for (int n = 0; n < N - 1; n++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back({n, v});
        adj[v].push_back({n, u});
    }

    int maxNode = 0;
    int maxDegree = 0;

    for (int n = 1; n <= N; n++) {
        if (maxDegree < adj[n].size()) {
            maxDegree = adj[n].size();
            maxNode = n;
        }
    }

    memset(numbers, -1, sizeof(numbers));

    int cur = 0;
    for (edge e : adj[maxNode]) {
        numbers[e.id] = cur++;
    }
    for (int n = 1; n <= N; n++) {
        for (edge e : adj[n]) {
            if (numbers[e.id] == -1) numbers[e.id] = cur++;
        }
    }

    for (int n = 0; n < N - 1; n++) {
        printf("%d\n", numbers[n]);
    }

    return 0;
}
