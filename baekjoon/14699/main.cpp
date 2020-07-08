#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int heights[5003];
vector<int> adj[5003];
int indegrees[5003];

queue<int> q;
int count[5003];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 1; n <= N; n++) {
        scanf("%d", heights + n);
    }
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int n = 1; n <= N; n++) {
        for (int next : adj[n]) {
            if (heights[n] < heights[next]) indegrees[n]++;
        }
    }
    for (int n = 1; n <= N; n++) {
        if (!indegrees[n]) {
            q.push(n);
            count[n] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (heights[cur] <= heights[next]) continue;

            count[next] = max(count[next], count[cur] + 1);
            if (--indegrees[next] == 0)
                q.push(next);
        }
    }

    for (int n = 1; n <= N; n++) {
        printf("%d\n", count[n]);
    }

    return 0;
}