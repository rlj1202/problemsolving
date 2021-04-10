#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[200005];

int g[200005 * 2];
int tg[200005];
int sa[200005];

int order[200005];
int lcp[200005];

int main() {
    int L;
    scanf("%d %s", &L, S);

    for (int i = 0; i < L; i++) {
        sa[i] = i;
        g[i] = S[i] - 'a' + 1;
    }

    int t = 1;
    while (t < L) {
        auto cmp = [&](int a, int b) -> bool {
            if (g[a] == g[b]) return g[a + t] < g[b + t];
            return g[a] < g[b];
        };

        sort(sa, sa + L, cmp);

        tg[0] = 1;
        for (int i = 1; i < L; i++) {
            if (cmp(sa[i - 1], sa[i])) {
                tg[sa[i]] = tg[sa[i - 1]] + 1;
            } else {
                tg[sa[i]] = tg[sa[i - 1]];
            }
        }
        for (int i = 0; i < L; i++) g[i] = tg[i];

        t <<= 1;
    }

    for (int i = 0; i < L; i++) order[sa[i]] = i;

    int cur = 0;
    for (int i = 0; i < L; i++) {
        int k = order[i];

        if (k) {
            int j = sa[k - 1];

            while (S[i + cur] == S[j + cur])
                cur++;

            lcp[k] = cur;

            if (cur) cur--;
        }
    }

    int result = 0;
    for (int i = 0; i < L; i++) {
        result = max(result, lcp[i]);
    }

    printf("%d\n", result);

    return 0;
}