#include <cstdio>
#include <algorithm>

using namespace std;

int A[2003];
int B[2003];

int A_max[2003];

int main() {
    // 2e3
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        // 2e3
        scanf("%d", A + n);
    }
    for (int n = 0; n < N; n++) {
        // 2e3
        scanf("%d", B + n);
    }

    for (int n = N - 1; n >= 0; n--) {
        A_max[n] = max(A_max[n + 1], A[n]);
    }

    int a = 0;
    int b = 0;

    int result = 0;

    while (a < N && b < N) {
        if (A[a] > B[b]) {
            result += B[b++];
        } else {
            a++;
            
            if (B[b] >= A_max[a]) {
                b++;
            } else {
            }
        }
    }

    printf("%d\n", result);

    return 0;
}