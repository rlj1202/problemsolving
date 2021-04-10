#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];

int symbols[4];

int main() {
    // 1e5
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        // 1 or 2 or 3
        scanf("%d", arr + n);
        symbols[arr[n]]++;
    }

    int result = 0x3f3f3f3f;

    for (int u = 1; u <= 3; u++) {
        for (int v = 1; v <= 3; v++) {
            if (u == v) continue;

            for (int w = 1; w <= 3; w++) {
                if (u == w || v == w) continue;

                int swaps = 0;

                int order[4] = { 0, u, v, w };

                int pairs[4][4] = {0, };

                int cur = 0;
                for (int i = 1; i <= 3; i++) {
                    for (int j = 0; j < symbols[order[i]]; j++) {
                        if (arr[cur] != order[i]) {
                            pairs[arr[cur]][order[i]]++;
                        }

                        cur++;
                    }
                }

                for (int i = 2; i <= 3; i++) {
                    for (int j = 1; j < i; j++) {
                        if (i == j) continue;

                        int min_pairs = min(pairs[i][j], pairs[j][i]);
                        swaps += min_pairs;

                        pairs[i][j] -= min_pairs;
                        pairs[j][i] -= min_pairs;
                    }
                }
                swaps += max(pairs[1][2], pairs[1][3]) * 2;

                result = min(result, swaps);
            }
        }
    }

    printf("%d\n", result);

    return 0;
}