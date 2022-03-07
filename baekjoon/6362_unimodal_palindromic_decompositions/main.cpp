#include <cstdio>

using namespace std;

long long dp[302][302];
bool visited[302][302];

long long calc(int n, int i) {
    if (!visited[n][i]) {
        visited[n][i] = true;

        if (n > i)
            dp[n][i] += calc(n - i, i);
        if (n > 2 && i > 2)
            dp[n][i] += calc(n - 2, i - 2);
    }

    return dp[n][i];
}

int main() {
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    visited[1][1] = true;
    visited[2][1] = true;
    visited[2][2] = true;

    while (true) {
        int N;
        scanf("%d", &N);
        if (!N) break;

        long long result = 0;
        for (int i = 1; i <= N; i++) {
            result += calc(N, i);
        }

        printf("%d %lld\n", N, result);
    }

    return 0;
}
