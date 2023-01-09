#include <cstdio>

using namespace std;

int perm[8][8] = {
    {}, // 0
    {}, // 1
    {}, // 2
    {}, // 3
    {2, 4, 1, 3}, // 4
    {2, 5, 3, 1, 4},
    {2, 6, 4, 1, 3, 5},
    {2, 4, 7, 5, 1, 3, 6},
};

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        if (N < 4) {
            printf("-1\n");
            continue;
        }

        int remains = N;
        int offset = 0;

        while (remains) {
            if (remains <= 7) {
                for (int i = 0; i < remains; i++) {
                    printf("%d ", perm[remains][i] + offset);
                }
                offset += remains;
                remains = 0;
            } else {
                for (int i = 0; i < 4; i++) {
                    printf("%d ", perm[4][i] + offset);
                }
                offset += 4;
                remains -= 4;
            }
        }
        printf("\n");
    }

    return 0;
}
