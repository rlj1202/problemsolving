#include <cstdio>
#include <algorithm>

using namespace std;

int A[100005];
int B[100005];
int indices[100005];

int main() {
    int T; // 100
    scanf("%d", &T);

    while (T--) {
        int N, M; // 1e5, 1e5
        scanf("%d %d", &N, &M);
        for (int n = 0; n < N; n++) {
            scanf("%d", A + n);
            indices[A[n]] = n;
        }
        for (int m = 0; m < M; m++) {
            scanf("%d", B + m);
        }

        int sorted = 0;
        long long result = 0;
        for (int m = 0; m < M; m++) {
            int cur = B[m];

            if (indices[cur] < sorted) {
                result++;
            } else {
                result += (indices[cur] - m) * 2 + 1;
                sorted = indices[cur] + 1;
            }
        }

        printf("%lld\n", result);
    }

    return 0;
}
