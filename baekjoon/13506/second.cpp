#include <cstdio>
#include <cstring>

using namespace std;

char S[1000006];

int pi[1000006];

int count[1000006];

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

    for (int i = 1; i < len; i++) {
        count[pi[i]]++;
    }

    int maxlen = 0;

    if (count[pi[len - 1]] > 1) {
        maxlen = pi[len - 1];
    } else {
        int j = pi[len - 1];
        j = pi[j - 1];
        if (j) {
            maxlen = j;
        }
    }

    if (maxlen) {
        S[maxlen] = '\0';
        printf("%s\n", S);
    } else {
        printf("-1\n");
    }

    return 0;
}
