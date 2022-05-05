#include <cstdio>

using namespace std;

long long delta[100005];
long long accum[100005];

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    for (int n = 0; n < N; n++) {
        int k;
        scanf("%d", &k);

        for (int i = 0; i < k; i++) {
            int s, e;
            scanf("%d %d", &s, &e);

            delta[s]++;
            delta[e]--;
        }
    }

    long long maxtime = 0;
    int starttime = 0;
    int endtime = 0;

    long long opens = 0;
    long long sum = 0;
    for (int t = 0; t < 100005; t++) {
        opens += delta[t];
        sum += opens;

        accum[t] = sum;

        int r = t;
        int l = t - T;

        if (l < 0) {
            continue;
        }

        long long time = accum[r - 1];
        if (l - 1 >= 0) time -= accum[l - 1];

        if (maxtime < time) {
            maxtime = time;
            starttime = l;
            endtime = r;
        }
    }

    printf("%d %d\n", starttime, endtime);

    return 0;
}
