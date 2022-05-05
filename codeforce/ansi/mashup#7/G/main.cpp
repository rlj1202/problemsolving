#include <cstdio>

using namespace std;

char program[200005];
int sum[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        scanf("%s", program + 1);

        for (int n = 1; n <= N; n++) {
            int delta = program[n] == '+' ? 1 : -1;
            sum[n] = sum[n - 1] + delta;
        }

        for (int m = 0; m < M; m++) {
            int l, r;
            scanf("%d %d", &l, &r);
        }

        for (int m = 0; m < M; m++) {
            printf("%d\n", 0);
        }
    }

    return 0;
}
