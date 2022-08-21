#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[100005];
int visited_num;
int visited[100005];

vector<pii> edges;

int dfs(int node, int parent) {
    visited[node] = ++visited_num;
    int low = visited[node];

    for (int next : adj[node]) {
        if (next == parent) continue;

        if (!visited[next]) {
            int prev = dfs(next, node);

            if (prev > visited[node]) {
                edges.push_back({ node, next });
            }

            low = min(low, prev);
        } else {
            low = min(low, visited[next]);
        }
    }

    cout << "node: " << node << ", parent: " << parent << ", low: " << low << '\n';

    return low;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    dfs(1, -1);

    cout << edges.size() << '\n';
    for (pii edge : edges) {
        cout << edge.first << ' ' << edge.second << '\n';
    }

    return 0;
}
