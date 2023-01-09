#include <cstdio>
#include <algorithm>

using namespace std;

int favors[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, X;
        scanf("%d %d", &N, &X);

        for (int n = 0; n < N; n++) {
            scanf("%d", favors + n);
        }

        sort(favors, favors + N);

        int maxFavor = favors[N - 1];
        int hops = X / maxFavor;
        int remains = X - hops * maxFavor;

        if (remains) {
            if (binary_search(favors, favors + N, remains)) {
                hops++;
                remains = 0;
            } else {
                if (hops) {
                    hops += 1;
                    remains = 0;
                } else {
                    hops += 2;
                    remains = 0;
                }
            }
        }

        printf("%d\n", hops);
    }

    return 0;
}
