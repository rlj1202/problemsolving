#include <cstdio>
#include <cmath>

using namespace std;

char str[1000006];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", str);

        int sheeps = 0;
        for (int n = 0; n < N; n++) {
            if (str[n] == '*') {
                sheeps++;
            }
        }

        int l = 0;
        int r = N - sheeps;
        int m1 = (l*2 + r) / 3;
        int m2 = (l + r*2 + 2) / 3;

        while (r - l > 0) {
            long long left = 0;
            int i = 0;
            for (int n = 0; n < N; n++) {
                if (str[n] == '*') {
                    left += abs(m1 + i - n);
                    i++;
                }
            }
            long long right = 0;
            i = 0;
            for (int n = 0; n < N; n++) {
                if (str[n] == '*') {
                    right += abs(m2 + i - n);
                    i++;
                }
            }

            if (left < right) {
                r = m2 - 1;
            } else {
                l = m1 + 1;
            }

            m1 = (l*2 + r) / 3;
            m2 = (l + r*2 + 2) / 3;
        }

        long long result = 0;
        int i = 0;
        for (int n = 0; n < N; n++) {
            if (str[n] == '*') {
                result += abs(m1 + i - n);
                i++;
            }
        }

        printf("%lld\n", result);
    }

    return 0;
}
