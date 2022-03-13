#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int T; // 1e4
    scanf("%d", &T);

    while (T--) {
        int N; // 1e5
        scanf("%d", &N);

        arr.clear();
        for (int n = 0; n < N; n++) {
            int value;
            scanf("%d", &value);

            if (value == -1 && arr.size() && arr.back() == -1) continue;
            arr.push_back(value);
        }

        int maxval = 0;
        int minval = 0x3f3f3f3f;
        int maxdiff = 0;

        for (int i = 0; i < arr.size(); i++) {
            int cur = arr[i];

            if (cur == -1) {
                if (i - 1 >= 0) {
                    maxval = max(maxval, arr[i - 1]);
                    minval = min(minval, arr[i - 1]);
                }
                if (i + 1 < arr.size()) {
                    maxval = max(maxval, arr[i + 1]);
                    minval = min(minval, arr[i + 1]);
                }
            } else {
                if (i - 1 >= 0 && arr[i - 1] != -1) {
                    maxdiff = max(maxdiff, abs(arr[i] - arr[i - 1]));
                }
            }
        }

        long long K = ((long long) minval + (long long) maxval + 1) / 2;
        long long M = K - minval;

        printf("%lld %lld\n", max(M, (long long) maxdiff), K);
    }

    return 0;
}
