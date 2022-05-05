#include <cstdio>

using namespace std;

char S[200005];
char K[200005];

int pi[200005];

int main() {
    scanf("%s", S);
    scanf("%s", K);

    {
        int j = 0;
        for (int i = 0; S[i] != 0; i++) {
            char c = S[i];
            bool digit = '0' <= c && c <= '9';

            if (!digit) {
                S[j++] = c;
            }
        }
        S[j] = '\0';
    }

    {
        int j = 0;
        for (int i = 1; K[i] != 0; i++) {
            while (j && K[i] != K[j]) j = pi[j - 1];

            if (K[i] == K[j]) pi[i] = ++j;
        }
    }

    bool found = false;

    {
        int j = 0;
        for (int i = 0; S[i] != 0; i++) {
            while (j && S[i] != K[j]) j = pi[j - 1];

            if (S[i] == K[j]) {
                if (K[j + 1] == 0) {
                    found = true;
                    break;
                } else {
                    j++;
                }
            }
        }
    }

    printf("%d\n", (int) found);

    return 0;
}
