#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2003];
vector<pair<int, int>> adj[2003];

bool used[2003];

pair<int, int> pairs[1003];

bool dfs(int idx, int remainPairs) {
    if (remainPairs == 0) {
        return true;
    }

    for (pair<int, int> &p : adj[idx]) {
        if (used[p.first] || used[p.second]) continue;

        used[p.first] = true;
        used[p.second] = true;
        pairs[remainPairs - 1] = p;

        bool result = dfs(p.second, remainPairs - 1);
        if (result) return true;

        used[p.first] = false;
        used[p.second] = false;
    }

    return false;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < 2*N; n++) {
            scanf("%d", arr + n);
        }

        sort(arr, arr + 2*N);

        for (int i = 0; i < 2*N; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < 2*N; i++) {
            for (int j = i + 1; j < 2*N; j++) {
                int sum = arr[i] + arr[j];
                int sumIdx = lower_bound(arr, arr + 2*N, sum) - arr;

                if (sumIdx == 2*N) continue;
                if (sum != arr[sumIdx]) continue;

                adj[sumIdx].push_back({i, j});
            }
        }

        memset(used, 0, sizeof(used));

        bool result = false;

        used[2*N - 1] = true;
        for (pair<int, int>& p : adj[2*N - 1]) {
            used[p.first] = true;
            used[p.second] = true;

            pairs[N - 2] = p;
            result = dfs(p.second, N - 2);
            if (result) break;

            used[p.first] = false;
            used[p.second] = false;
        }

        printf("%s\n", result ? "YES" : "NO");
        if (result) {
            int unused;
            for (int n = 0; n < 2*N; n++) {
                if (!used[n]) {
                    unused = n;
                    break;
                }
            }

            printf("%d\n", arr[2*N - 1] + arr[unused]);
            printf("%d %d\n", arr[2*N - 1], arr[unused]);
            for (int n = N - 2; n >= 0; n--) {
                printf("%d %d\n", arr[pairs[n].first], arr[pairs[n].second]);
            }
        }
    }

    return 0;
}
