#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[200005];
vector<int> new_arr;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }
        sort(arr, arr + N);

        new_arr.clear();

        int prev = arr[0];
        int cnt = 1;
        for (int n = 1; n < N; n++) {
            if (arr[n] == prev) {
                cnt++;
            } else {
                if (cnt >= K) new_arr.push_back(prev);
                prev = arr[n];
                cnt = 1;
            }
        }
        if (cnt >= K) new_arr.push_back(prev);

        if (!new_arr.empty()) {
            int l = 0;
            int r = 0;

            int left = 0;
            int right = 0;
            for (int i = 1; i < new_arr.size(); i++) {
                if (new_arr[i - 1] + 1 == new_arr[i]) {
                    right++;
                } else {
                    if (r - l < right - left) {
                        l = left;
                        r = right;
                    }
                    left = i;
                    right = i;
                }
            }
            if (r - l < right - left) {
                l = left;
                r = right;
            }

            printf("%d %d\n", new_arr[l], new_arr[r]);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
