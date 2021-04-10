#include <cstdio>

using namespace std;

bool grid[12][12];

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                char c;
                scanf(" %c", &c);

                grid[n][m] = c == '.';
            }
        }

        

        printf("%d\n", 0);
    }

    return 0;
}