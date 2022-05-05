#include <cstdio>
#include <algorithm>

using namespace std;

int arr[52];

int main() {
    int N, M, L;
    scanf("%d %d %d", &N, &M, &L);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }
    sort(arr, arr + N);
    arr[N++] = L;

    int l = 1;
    int r = 1e9;

    while (r - l) {
        int mid = (l + r) / 2;

        int count = 0;
        int prev = 0;
        for (int n = 0; n < N; n++) {
            int delta = arr[n] - prev;

            if (mid < delta) {
                count += (delta + mid - 1) / mid - 1;
            }

            prev = arr[n];
        }

        if (count <= M) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%d\n", l);

    return 0;
}
