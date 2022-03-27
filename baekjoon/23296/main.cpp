#include <cstdio>
#include <vector>

using namespace std;

int targets[100005];
int indegrees[100005];
bool visited[100005];

vector<int> order;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;

    int next = targets[cur];
    order.push_back(next);
    dfs(next);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", targets + n);
        indegrees[targets[n]]++;
    }

    for (int n = 1; n <= N; n++) {
        if (indegrees[n] != 0) continue;

        if (n > 1) order.push_back(n);
        dfs(n);
    }

    for (int n = 1; n <= N; n++) {
        if (visited[n]) continue;

        if (n > 1) order.push_back(n);
        dfs(n);
    }

    printf("%d\n", order.size());
    for (int i = 0; i < order.size(); i++) printf("%d ", order[i]);
    printf("\n");

    return 0;
}
