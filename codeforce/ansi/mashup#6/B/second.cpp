#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[2003];
bool used[2003];

pair<int, int> pairs[1003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N*2; n++) {
            scanf("%d", arr + n);
        }
        sort(arr, arr + N*2);

        bool success = false;

        for (int n = 0; n < N*2 - 1; n++) {
            int r = N*2 - 1;
            int pidx = 0;

            int x = arr[n] + arr[r];

            memset(used, 0, sizeof(used));

            bool valid = true;

            while (r >= 0) {
                if (used[r]) {
                    r--;
                    continue;
                }

                int remain = x - arr[r];
                int lower = lower_bound(arr, arr + r, remain) - arr;
                int upper = upper_bound(arr, arr + r, remain) - arr;

                if (lower == upper) {
                    valid = false;
                    break;
                }

                int idx;
                for (idx = lower; idx < upper; idx++) {
                    if (!used[idx]) {
                        break;
                    }
                }
                if (idx == upper) {
                    valid = false;
                    break;
                }

                used[r] = true;
                used[idx] = true;

                pairs[pidx++] = { arr[idx], arr[r] };

                x = arr[r];
            }

            if (valid) {
                success = true;
                break;
            }
        }

        printf("%s\n", success ? "YES" : "NO");
        if (success) {
            printf("%d\n", pairs[0].first + pairs[0].second);
            for (int n = 0; n < N; n++) {
                printf("%d %d\n", pairs[n].first, pairs[n].second);
            }
        }
    }

    return 0;
}
