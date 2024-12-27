#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int adj[22][22];

int main() {
    scanf("%d", &N);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            scanf("%d", &adj[r][c]);
        }
    }

    int answer = 0x3f3f3f3f;

    for (int i = 0; i < (1 << N); i++) {
        int tmp = i;
        int cnt = 0;

        while (tmp) {
            cnt += tmp & 1;
            tmp >>= 1;
        }

        if (cnt != N / 2) {
            continue;
        }

        int sum[] = {0, 0};
        for (int a = 0; a < N; a++) {
            for (int b = a + 1; b < N; b++) {
                if (((i >> a) & 1) != ((i >> b) & 1)) {
                    continue;
                }

                sum[(i >> a) & 1] += adj[a][b] + adj[b][a];
            }
        }

        answer = min(answer, abs(sum[0] - sum[1]));
    }

    printf("%d\n", answer);

    return 0;
}
