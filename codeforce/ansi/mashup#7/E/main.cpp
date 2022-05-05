#include <cstdio>

using namespace std;

char str[200005];

int result[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", str);

        bool possible = true;

        if (str[0] == '0' || str[N - 1] == '0') possible = false;

        int ones = 0;
        for (int n = 0; n < N; n++) {
            int digit = str[n] - '0';
            if (digit == 1) ones++;
        }

        if (ones % 2 == 1) {
            possible = false;
        }

        ones /= 2;
        bool open = true;

        for (int n = 0; n < N; n++) {
            int digit = str[n] - '0';

            if (digit == 1) {
                if (ones) {
                    result[n] = 0;
                    ones--;
                } else {
                    result[n] = 1;
                }
            } else {
                result[n] = !open;
                open = !open;
            }
        }

        printf("%s\n", possible ? "YES" : "NO");
        if (possible) {
            for (int n = 0; n < N; n++) {
                printf("%c", "()"[result[n]]);
            }
            printf("\n");
            for (int n = 0; n < N; n++) {
                printf("%c", "()"[result[n] ^ !(str[n] - '0')]);
            }
            printf("\n");
        }
    }

    return 0;
}
