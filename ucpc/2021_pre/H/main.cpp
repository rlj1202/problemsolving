#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
    int time;
    int counts;
};

vector<pair<int, int>> adj[100005];

int dp[100005][21];

int main() {
    int N, M, K, S, T;
    scanf("%d %d %d %d %d", &N, &M, &K, &S, &T);

    for (int m = 0; m < M; m++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);

        adj[a].push_back({b, t});
        adj[b].push_back({a, 0});
    }


    printf("%d\n", 0);

    return 0;
}
