#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int R, C;
        scanf("%d %d", &R, &C);

        printf("Case #%d:\n", t);

        for (int r = 0; r < R * 2 + 1; r++) {
            for (int c = 0; c < C * 2 + 1; c++) {
                if (c < 2 && r < 2) {
                    printf(".");
                } else {
                    printf("%c", "+-|."[c % 2 + (r % 2) * 2]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
