#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[1000006];

int g[1000006];
int tg[1000006];
int sa[1000006];

int order[1000006];
int lcp[1000006];

int main() {
    scanf("%s", S);
    int len = strlen(S);

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

    long long result = 0;

    for (int i = 0; i < len; i++) {
        result += (len - sa[i]) - lcp[i];
    }

    printf("%lld\n", result);

    return 0;
}