#include <cstdio>

using namespace std;

int grid[52][52];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N,&M);

        for (int n = 1; n <= N; n++) {
            for (int m = 1; m <= M; m++) {
                scanf("%d", &grid[n][m]);
            }
        }

        

        printf("%d\n", 0);
    }

    return 0;
}