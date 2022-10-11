#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int n = 0; n < N - 1; n++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << 0 << '\n';

    return 0;
}
