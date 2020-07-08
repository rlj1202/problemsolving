#include <cstdio>
#include <algorithm>

using namespace std;

int lengths[1000006];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", lengths + n);
    }
    sort(lengths, lengths + N);

    int l = 0;
    int r = 1e9;
    int mid = (l + r) / 2;

    while (l < r) {
        int pieces = 0;
        for (int n = 0; n < N; n++) {
            pieces += lengths[n] / mid;
        }

        if (pieces >= M) {
            l = mid;
        } else {
            r = mid - 1;
        }

        mid = (l + r + 1) / 2;
    }

    printf("%d\n", mid);

    return 0;
}