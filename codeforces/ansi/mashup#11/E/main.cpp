#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int arr[200005];

vector<int> adj[200005];

int res[200005];

int result[200005];
bool finished[200005];

void calcRes(int node, int parent) {
    int result = arr[node] ? 1 : -1;

    for (int child : adj[node]) {
        if (child == parent) continue;

        calcRes(child, node);

        if (res[child] >= 0) {
            result += res[child];
        }
    }

    res[node] = result;
}

void setResult(int node, int parent, int value) {
    result[node] = max(value, 0) + res[node];

    for (int child : adj[node]) {
        if (child == parent) continue;

        setResult(child, node, result[node] - max(res[child], 0));
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }
    for (int n = 0; n < N - 1; n++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calcRes(1, -1);
    setResult(1, -1, 0);

    for (int n = 1; n <= N; n++) {
        printf("%d ", result[n]);
    }
    printf("\n");

    return 0;
}
