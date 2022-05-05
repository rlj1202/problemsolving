#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long factors[100005];
vector<int> adj[100005];

long long dfs(int cur, long long *sum) {
    long long child_min = 0x3f3f3f3f;
    long long child_sum = 0;

    for (int i = 0; i < adj[cur].size(); i++) {
        int child = adj[cur][i];
        long long child_result = dfs(child, sum);
        child_sum += child_result;
        child_min = min(child_min, child_result);
    }

    if (adj[cur].size()) *sum += child_sum - child_min;

    return adj[cur].size() > 0 ? max(factors[cur], child_min) : factors[cur];
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            scanf("%lld", factors + n);
        }
        for (int n = 0; n <= N; n++) {
            adj[n].clear();
        }
        for (int n = 1; n <= N; n++) {
            int parent;
            scanf("%d", &parent);
            adj[parent].push_back(n);
        }

        long long sum = 0;
        for (int child : adj[0]) {
            sum += dfs(child, &sum);
        }

        printf("Case #%d: %lld\n", t, sum);
    }

    return 0;
}
