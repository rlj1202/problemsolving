#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int E, W;

int arr[102][102];
int sum[102];
int offset[102][102];

int dfs(int l, int r, int depth) {
    if (r - l == 1) return 0;

    int prefix = 0;
    for (int w = 0; w < W; w++) {
        offset[depth][w] = 0x3f3f3f3f;

        for (int i = l; i < r; i++) {
            offset[depth][w] = min(offset[depth][w], arr[i][w]);
        }

        prefix += offset[depth][w];
    }

    int result = 0x3f3f3f3f;

    for (int m = l + 1; m < r; m++) {
        int cost = sum[m - 1] + sum[m] - prefix - prefix;

        cost += dfs(l, m, depth + 1);
        cost += dfs(m, r, depth + 1);

        result = min(result, cost);
    }

    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &E, &W);
        for (int e = 0; e < E; e++) {
            sum[e] = 0;

            for (int w = 0; w < W; w++) {
                scanf("%d", arr[e] + w); // 100

                sum[e] += arr[e][w];
            }
        }

        int result = dfs(0, E, 0) + sum[0] + sum[E - 1];

        printf("Case #%d: %d\n", t, result);
    }

    return 0;
}
