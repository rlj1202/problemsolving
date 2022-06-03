#include <cstdio>
#include <cstring>

using namespace std;

char S[1000006];

int pi[1000006];

int main() {
    scanf("%s", S);

    int len = strlen(S);

    {
        int j = 0;
        for (int i = 1; i < len; i++) {
            while (j && S[i] != S[j]) j = pi[j - 1];
            if (S[i] == S[j]) pi[i] = ++j;
        }
    }

    int l = 0;
    int r = 0;

    for (int i = 1; i < len - 1; i++) {
        if (pi[i] <= r - l) continue;

        int j = pi[len - 1];
        while (j && pi[i] < j) j = pi[j - 1];

        if (pi[i] == j) {
            if (r - l < pi[i]) {
                l = i + 1 - pi[i];
                r = i + 1;
            }
        }
    }

    if (r - l > 0) {
        S[r] = '\0';
        printf("%s\n", S + l);
    } else {
        printf("-1\n");
    }

    return 0;
}
