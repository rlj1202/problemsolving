#include <cstdio>

using namespace std;

int arr[1 << 19];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int L, R;
        scanf("%d %d", &L, &R);
        int range = R - L + 1;
        for (int i = 0; i < range; i++) {
            scanf("%d", arr + i);
        }

        int sum = 0;
        for (int i = 0; i < range; i++) {
            sum = sum ^ arr[i];
        }
        for (int i = L + 1; i <= R; i++) {
            sum = sum ^ i;
        }
        printf("\t%d\n", sum);

        printf("%d\n", 0);
    }

    return 0;
}
