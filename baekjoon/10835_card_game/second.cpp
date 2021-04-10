#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

int A[2003];
int B[2003];

int dp[2003][2003];

int get(int a, int b) {
    if (dp[a][b] == -1) {
        dp[a][b] = -2; // impossible

        if (a)
            dp[a][b] = max(dp[a][b], get(a - 1, b));
        if (a && b)
            dp[a][b] = max(dp[a][b], get(a - 1, b - 1));
        if (b && A[a] > B[b - 1] && get(a, b - 1) != -2)
            dp[a][b] = max(dp[a][b], get(a, b - 1) + B[b - 1]);
    }

    return dp[a][b];
}

int main() {
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", A + n);
    }
    for (int n = 0; n < N; n++) {
        scanf("%d", B + n);
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    int result = 0;
    for (int b = 0; b <= N; b++) {
        result = max(result, get(N, b));
    }

    printf("%d\n", result);
    
    return 0;
}