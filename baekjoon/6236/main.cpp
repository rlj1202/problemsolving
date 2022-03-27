#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    int maxVal = 0;
    for (int n = 0; n < N; n++) {
        maxVal = max(maxVal, arr[n]);
    }

    int l = maxVal;
    int r = 0x3f3f3f3f;
    int mid = (l + r) / 2;

    while (l < r) {
        int count = 0;

        int cur = 0;
        for (int n = 0; n < N; n++) {
            if (cur < arr[n]) {
                cur = mid;
                count++;
            }

            cur -= arr[n];
        }

        if (count <= M) {
            r = mid;
        } else {
            l = mid + 1;
        }

        mid = (l + r) / 2;
    }

    printf("%d\n", mid);

    return 0;
}
