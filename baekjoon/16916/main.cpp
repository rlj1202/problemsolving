#include <cstdio>

using namespace std;

char S[1000006];
char P[1000006];

int pi[1000006];

void getpi() {
    int j = 0;
    for (int i = 1; P[i] != 0; i++) {
        while (j && P[i] != P[j]) j = pi[j - 1];

        if (P[i] == P[j]) pi[i] = ++j;
    }
}

int main() {
    scanf("%s", S);
    scanf("%s", P);

    getpi();

    bool found = false;

    int j = 0;
    for (int i = 0; S[i] != 0; i++) {
        while (j && S[i] != P[j]) j = pi[j - 1];

        if (S[i] == P[j]) {
            if (P[j + 1] == 0) {
                found = true;
                break;
            } else {
                j++;
            }
        }
    }

    printf("%d\n", (int) found);

    return 0;
}
