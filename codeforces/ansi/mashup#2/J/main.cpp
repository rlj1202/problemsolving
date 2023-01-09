#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[200005];
int P[200005];
long long cnt[26];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;// 2e5, 2e5
        scanf("%d %d", &N, &M);
        scanf("%s", str);
        for (int m = 0; m < M; m++) scanf("%d", P + m);

        sort(P, P + M);
        int pi = 0;

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < N; i++) {
            while (i == P[pi] && pi < M) pi++;
            cnt[str[i] - 'a'] += (long long) (M - pi + 1);
        }

        for (int i = 0; i < 26; i++) printf("%lld ", cnt[i]);
        printf("\n");
    }

    return 0;
}
