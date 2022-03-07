#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N[3];
        for (int i = 0; i < 3; i++) scanf("%d", N + i);

        for (int i = 0; N[0] && i < N[0] + 1; i++) {
            printf("0");
        }
        for (int i = 0; N[2] && i < N[2] + 1; i++) {
            printf("1");
        }

        bool toggle = N[2] > 0;
        if (!N[0] && !N[2]) {
            printf("0");
        }
        for (int i = N[0] && N[2]; N[1] && i < N[1]; i++) {
            toggle = !toggle;
            printf("%d", toggle);
        }

        printf("\n");
    }

    return 0;
}
