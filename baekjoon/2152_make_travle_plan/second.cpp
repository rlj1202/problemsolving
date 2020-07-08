#include <algorithm>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> adj[10004];

int visited[10004];
int finished[10004];
int cur_visit;
int cur_finish;

vector<int> dag[10004];
int dag_cities[10004];
int indegrees[10004];

stack<int> s;

queue<int> q;
bool checked[10004];
int max_cities[10004];

int dfs(int node) {
    visited[node] = ++cur_visit;
    int lower = visited[node];

    s.push(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            lower = min(lower, dfs(next));
        } else if (!finished[next]) {
            lower = min(lower, visited[next]);
        }
    }

    if (visited[node] == lower) {
        cur_finish++;

        while (true) {
            int element = s.top();
            s.pop();

            finished[element] = cur_finish;

            if (element == node)
                break;
        }
    }

    return lower;
}

int main() {
    int N, M, S, T;
    scanf("%d %d %d %d", &N, &M, &S, &T);
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }

    for (int n = 1; n <= N; n++) {
        if (!visited[n])
            dfs(n);
    }

    for (int n = 1; n <= N; n++) {
        int A = finished[n];

        dag_cities[A]++;

        for (int next : adj[n]) {
            int B = finished[next];
            if (A == B) continue;

            dag[A].push_back(B);
        }
    }
    for (int d = 1; d <= cur_finish; d++) {
        sort(dag[d].begin(), dag[d].end());
        dag[d].erase(unique(dag[d].begin(), dag[d].end()), dag[d].end());
    }

    int s = finished[S];
    int t = finished[T];

    q.push(s);
    checked[s] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : dag[cur]) {
            indegrees[next]++;
            if (checked[next]) continue;
            q.push(next);
            checked[next] = true;
        }
    }

    max_cities[s] = dag_cities[s];
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : dag[cur]) {
            max_cities[next] =
                max(max_cities[next], max_cities[cur] + dag_cities[next]);
            if (--indegrees[next] == 0)
                q.push(next);
        }
    }

    printf("%d\n", max_cities[t]);

    return 0;
}