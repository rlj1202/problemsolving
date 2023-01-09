#include <cstdio>
#include <cstring>

using namespace std;

int arr[8003];
int sum[8003];
bool cnt[8003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 8e3
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);
        }

        memset(cnt, 0, sizeof(cnt));

        for (int n = 1; n <= N; n++) {
            sum[n] = sum[n - 1] + arr[n];
        }

        for (int r = 2; r <= N; r++) {
            for (int l = 0; l <= r - 2; l++) {
                int value = sum[r] - sum[l];
                if (value <= N) cnt[value] |= true;
            }
        }

        int result = 0;

        for (int n = 1; n <= N; n++) {
            result += cnt[arr[n]];
        }

        printf("%d\n", result);
    }

    return 0;
}
