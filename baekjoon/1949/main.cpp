#include <bits/stdc++.h>

using namespace std;

int arr[10004];

vector<int> adj[10004];

int dp[10004][2];

int dfs(int node, int parent, bool parent_selected) {
    if (dp[node][parent_selected] != -1) {
        return dp[node][parent_selected];
    }

    int result = 0;

    // if parent_selected
    //     cur node must not be selected
    //
    //     1) children might be selected
    //     2) children might not be selected
    // else
    //     1) cur node can be selected and children are not
    //     2) cur node can not be selected and children must be selected

    if (parent_selected) {
        for (int next : adj[node]) {
            if (next == parent) continue;

            result += dfs(next, node, false);
        }
    } else {
        int a = 0;
        int b = arr[node];

        for (int next : adj[node]) {
            if (next == parent) continue;

            a += dfs(next, node, false);
            b += dfs(next, node, true);
        }

        result = max(a, b);
    }
    
    return dp[node][parent_selected] = result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }
    for (int n = 0; n < N - 1; n++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    int answer = dfs(1, -1, false);

    cout << answer << '\n';

    return 0;
}
