#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    // 1000, 1000
    int M, N;
    scanf("%d %d", &M, &N);

    int x = 0, y = 0;
    int dx = 1, dy = 0;

    for (int n = 0; n < N; n++) {
        char cmd[5];
        int arg;
        scanf("%s %d", cmd, &arg);

        if (strcmp(cmd, "MOVE") == 0) {
            x += dx * arg;
            y += dy * arg;
        } else if (strcmp(cmd, "TURN") == 0) {
            if (arg == 0) {
                int tmp = dx;
                dx = -dy;
                dy = tmp;
            } else if (arg == 1) {
                int tmp = dx;
                dx = dy;
                dy = -tmp;
            }
        }

        if (x < 0 || y < 0 || x > M || y > M) {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}