#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int parent[4003];
char str[4003];

vector<int> adj[4003];

int counts[4003][2];

int dfs(int node) {
    int result = 0;

    for (int child : adj[node]) {
        result += dfs(child);

        counts[node][0] += counts[child][0];
        counts[node][1] += counts[child][1];
    }

    bool color = str[node] == 'W';
    counts[node][color]++;

    if (counts[node][0] == counts[node][1]) {
        result++;
    }

    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        for (int n = 1; n <= N; n++) adj[n].clear();
        memset(counts, 0, sizeof(counts));

        for (int n = 2; n <= N; n++) {
            scanf("%d", parent + n);

            adj[parent[n]].push_back(n);
        }
        scanf("%s", str + 1);

        printf("%d\n", dfs(1));
    }

    return 0;
}
