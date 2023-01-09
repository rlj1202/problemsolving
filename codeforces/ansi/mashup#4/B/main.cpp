#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        int delta = abs(A - B);

        int result = 0;

        long long sum = 0;
        long long n = 0;
        while (true) {
            sum += n;

            if ((sum + delta) % 2 == 0 && delta <= (sum + delta) / 2) {
                result = n;
                break;
            }

            n++;
        }

        printf("%d\n", result);
    }

    return 0;
}
