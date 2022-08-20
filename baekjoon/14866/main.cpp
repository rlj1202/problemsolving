#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> adj[300005];
int depth[300005];
int fulls[300005]; // 서브트리에 완전히 포함된 back edge의 갯수
int subs[300005]; // 서브트리에 반만 포함된 back edge의 갯수
int absolutes[300005]; // 서브트리의 직속 부모(?)로 향하는 back edge의 갯수

vector<int> tree_edges[300005];

void dfs(int node, int parent) {
    for (int next : adj[node]) {
        if (next == parent) continue;

        if (depth[next] && depth[node] > depth[next]) {
            // back edge
            fulls[next]++;
            subs[node]++;
        } else if (!depth[next]) {
            // tree edge
            tree_edges[node].push_back(next);

            depth[next] = depth[node] + 1;

            int prev = fulls[node];
            dfs(next, node);
            absolutes[next] = fulls[node] - prev;

            fulls[node] += fulls[next];
            subs[node] += subs[next];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    depth[1] = 1;
    dfs(1, -1);

    ll answer = 0;

    for (int n = 1; n <= N; n++) {
        bool decyclic = true;

        for (int next : tree_edges[n]) {
            // 1. n을 제거해도 back edge가 남아있는 경우
            // 2. n을 제거했을 때 n 위로 올라가는 back edge가 2개 이상인 경우
            if (fulls[next] || subs[next] - absolutes[next] > 1) {
                decyclic = false;
                break;
            }
        }
        // 3. n의 서브트리가 아닌 다른 곳에 back edge가 존재하는 경우
        // 트리의 간선 갯수는 N - 1이다.
        // 따라서 M - (N - 1) 는 tree edge가 아닌 간선의 갯수 즉,
        // 전체 back edge의 갯수이다.
        // 그런데 전체 back edge의 갯수에서 n의 서브트리에 속한 back edge의
        // 갯수를 빼도 back edge가 남아있다는 것은 다른 곳에 back edge가 존재한다는 뜻이 된다.
        if (M - (N - 1) > subs[n]) {
            decyclic = false;
        }

        if (decyclic) answer += n;
    }

    cout << answer << '\n';

    return 0;
}
