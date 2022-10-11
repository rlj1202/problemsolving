#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int mat[1003][1003];
vector<int> adj[1003];

bool check[1003];
bool color[1003];
int odd, even;

vector<int> diffs;

bool dp[1003][5003];

bool dfs(int cur) {
    check[cur] = true;

    if (color[cur] == false) odd++;
    else even++;

    for (int next : adj[cur]) {
        if (check[next]) {
            if (color[cur] == color[next]) {
                return false;
            }
        } else {
            color[next] = !color[cur];
            if (dfs(next) == false) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    fill(&mat[1][1], &mat[N + 1][0], 1);

    // Read input and make a complementary graph
    for (int m = 0; m < M; m++) {
        int u, v;
        cin >> u >> v;

        mat[u][v] = mat[v][u] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (!mat[i][j]) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    // Check given complementary graph is a bipartite graph
    // Note that the graph can be a non-connected graph
    for (int i = 1; i <= N; i++) {
        if (check[i]) continue;

        odd = even = 0;

        if (dfs(i) == false) {
            cout << -1 << '\n';
            return 0;
        }

        diffs.push_back(even - odd);
    }

    // Using knapsack DP
    int base = 2000;

    // dp[i-th item][sum] = whether possible;
    dp[0][base + 0] = true;

    for (int i = 0; i < diffs.size(); i++) {
        for (int j = -N; j <= N; j++) {
            if (dp[i][base + j]) {
                dp[i + 1][base + j + diffs[i]] = true;
                dp[i + 1][base + j - diffs[i]] = true;
            }
        }
    }

    // Acquire minimum difference
    int answer = INF;

    for (int i = -N; i <= N; i++) {
        if (dp[diffs.size()][base + i]) {
            answer = min(answer, abs(i));
        }
    }

    // Print the answer
    cout << answer << '\n';

    return 0;
}
