#include <cstdio>

using namespace std;

int arr[200005];

int main() {
    int N; // 2e5
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }
    int Q; // 2e5
    scanf("%d", &Q);
    while (Q--) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            int p, x;
            scanf("%d %d", &p, &x);

        } else {
            int x;
            scanf("%d", &x);

        }
    }

    for (int n = 0; n < N; n++) {
        printf("%d ", 0);
    }
    printf("\n");

    return 0;
}
