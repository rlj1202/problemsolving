#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[1003];

int g[1003 * 2];
int tg[1003];
int sa[1003];

int main() {
    scanf("%s", S);
    
    int len = strlen(S);

    memset(g, -1, sizeof(g));
    for (int i = 0; i < len; i++) {
        sa[i] = i;
        g[i] = S[i] - 'a';
    }

    int t = 1;
    while (t < len) {
        auto cmp = [&](int a, int b) -> bool {
            if (g[a] == g[b]) {
                return g[a + t] < g[b + t];
            }
            return g[a] < g[b];
        };

        sort(sa, sa + len, cmp);

        tg[0] = 0;
        for (int i = 1; i < len; i++) {
            if (cmp(sa[i - 1], sa[i])) {
                tg[sa[i]] = tg[sa[i - 1]] + 1;
            } else {
                tg[sa[i]] = tg[sa[i - 1]];
            }
        }
        for (int i = 0; i < len; i++) {
            g[i] = tg[i];
        }

        t <<= 1;
    }

    for (int i = 0; i < len; i++) {
        printf("%s\n", S + sa[i]);
    }

    return 0;
}