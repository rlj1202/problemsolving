#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj[1003];

int parent[1003];
int size[1003];

int discovered[1003];
bool finished[1003];
int cur_discovery;
stack<int> s;

vector<int> dag[1003];
int indegrees[1003];
queue<int> q;

int dp[1003][1003];

int scc(int node) {
    discovered[node] = ++cur_discovery;
    s.push(node);

    int lower = discovered[node];

    for (int next : adj[node]) {
        if (!discovered[next]) {
            lower = min(lower, scc(next));
        } else if (!finished[next]) {
            lower = min(lower, discovered[next]);
        }
    }

    if (lower == discovered[node]) {
        while (true) {
            int set = s.top();
            s.pop();

            finished[set] = true;
            parent[set] = node;
            size[node]++;
            if (set == node)
                break;
        }
    }

    return lower;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int n = 1; n <= N; n++) {
        int m;
        scanf("%d", &m);
        adj[m].push_back(n);
    }

    for (int n = 1; n <= N; n++) {
        if (!discovered[n])
            scc(n);
    }

    for (int n = 1; n <= N; n++) {
        int A = parent[n];
        for (int next : adj[n]) {
            int B = parent[next];
            if (A == B)
                continue;

            dag[A].push_back(B);
        }
    }
    for (int n = 1; n <= N; n++) {
        sort(dag[n].begin(), dag[n].end());
        dag[n].resize(unique(dag[n].begin(), dag[n].end()) - dag[n].begin());
    }
    for (int n = 1; n <= N; n++) {
        for (int next : dag[n]) {
            indegrees[next]++;
        }
    }
    for (int n = 1; n <= N; n++) {
        if (indegrees[n] == 0 && size[n])
            q.push(n);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();



        for (int next : dag[cur]) {
            if (--indegrees[next] == 0) {
                q.push(next);
            }
        }
    }

    printf("%d\n", 0);

    return 0;
}