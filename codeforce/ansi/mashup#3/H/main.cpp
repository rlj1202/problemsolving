#include <cstdio>

using namespace std;

char A[100005];
char B[100005];

int result[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 1e5
        scanf("%d", &N);
        scanf("%s %s", A, B);

        int K = 0;

        int l = 0;
        int r = N;
        bool flipped = false;
        bool inversed = false;
        for (int n = 0; n < N; n++) {
            char cur = A[flipped ? r - 1 : l];
            if (inversed) cur = '0' + !(cur - '0');

            if (B[N - n - 1] == cur) {
                result[K++] = 1;
            }

            result[K++] = r - l;
            if (flipped) r--;
            else l++;

            flipped = !flipped;
            inversed = !inversed;
        }

        printf("%d ", K);
        for (int k = 0; k < K; k++) printf("%d ", result[k]);
        printf("\n");
    }

    return 0;
}
