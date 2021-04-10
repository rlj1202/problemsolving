#include <cstdio>

using namespace std;

long long counts[300005];

int main() {
    // number of children, number of jewel kinds
    // 1e9, 3e5, M <= N
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        // 1e9
        scanf("%lld", counts + m);
    }

    int l = 1;
    int r = 1e9;
    int mid = (l + r) / 2;

    while (l < r) {
        int children = 0;
        for (int m = 0; m < M; m++) {
            children += counts[m] / mid + ((counts[m] % mid) > 0);
        }

        if (children > N) { // impossible
            l = mid + 1;
        } else { // possible
            r = mid;
        }

        mid = (l + r) / 2;
    }

    printf("%d\n", mid);

    return 0;
}
