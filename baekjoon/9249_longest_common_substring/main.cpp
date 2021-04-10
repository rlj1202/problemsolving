#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[200005];

int g[200005];
int tg[200005];
int sa[200005];

int order[200005];
int lcp[200005];

int main() {
    scanf("%s", S);
    int alen = strlen(S);
    S[alen] = 'z' + 1;
    scanf("%s", S + alen + 1);
    int blen = strlen(S + alen + 1);
    int len = alen + blen + 1;

    for (int i = 0; i < len; i++) {
        sa[i] = i;
        g[i] = S[i] - 'a' + 1;
    }

    int t = 1;
    while (t < len) {
        auto cmp = [&](int a, int b) -> bool {
            if (g[a] == g[b]) return g[a + t] < g[b + t];
            return g[a] < g[b];
        };

        sort(sa, sa + len, cmp);

        tg[sa[0]] = 1;
        for (int i = 1; i < len; i++) {
            tg[sa[i]] = tg[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }

        for (int i = 0; i < len; i++) {
            g[i] = tg[i];
        }

        t <<= 1;
    }

    for (int i = 0; i < len; i++) {
        order[sa[i]] = i;
    }

    int cur = 0;
    for (int i = 0; i < len; i++) {
        int k = order[i];

        if (k) {
            int j = sa[k - 1];

            while (S[i + cur] == S[j + cur]) cur++;

            lcp[k] = cur;

            if (cur) cur--;
        }
    }

    int max_len = 0;
    int index = 0;

    for (int i = 1; i < len; i++) {
        if ((sa[i - 1] > alen && sa[i] < alen) ||
            (sa[i - 1] < alen && sa[i] > alen)) {
            if (max_len < lcp[i]) {
                max_len = lcp[i];
                index = sa[i];
            }
        }
    }

    S[index + max_len] = 0;
    printf("%d\n", max_len);
    printf("%s\n", S + index);

    return 0;
}