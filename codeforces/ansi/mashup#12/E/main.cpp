#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int digits[42];

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    for (int n = 0; n < N; n++) {
        int value;
        scanf("%d", &value);

        int i = 0;
        while (value > 1) {
            i++;
            value >>= 1;
        }

        digits[i]++;
    }

    while (Q--) {
        int value;
        scanf("%d", &value);

        int remains[42];
        memset(remains, 0, sizeof(remains));

        int i = 0;
        while (value) {
            remains[i] = value % 2;

            value >>= 1;
            i++;
        }

        for (int i = 42 - 1; i >= 0; i--) {
            if (digits[i] < remains[i] && i) {
                remains[i - 1] += (remains[i] - digits[i]) * 2;
                remains[i] = digits[i];
            }
        }

        int result = 0;
        bool valid = true;

        for (int i = 0; i < 42; i++) {
            if (digits[i] >= remains[i]) {
                result += remains[i];
            } else {
                valid = false;
                break;
            }
        }

        printf("%d\n", valid ? result : -1);
    }

    return 0;
}
