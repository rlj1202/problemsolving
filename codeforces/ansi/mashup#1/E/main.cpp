#include <cstdio>

using namespace std;

char arr[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", arr);

        int zeros = 0;
        for (int i = 0; i < N && arr[i] == '0'; i++) {
            zeros++;
        }

        int ones = 0;
        for (int i = N - 1; i >= 0 && arr[i] == '1'; i--) {
            ones++;
        }

        for (int i = 0; i < zeros; i++) printf("0");
        if (zeros + ones < N) printf("0");
        for (int i = 0; i < ones; i++) printf("1");
        printf("\n");
    }

    return 0;
}
