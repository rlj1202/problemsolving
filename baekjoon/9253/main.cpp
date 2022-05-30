#include <cstdio>

using namespace std;

char A[200005];
char B[200005];
char C[200005];

int pi[200005];

bool search(char *str, char *key) {
    int j = 0;
    for (int i = 0; str[i] != 0; i++) {
        while (j && str[i] != key[j]) j = pi[j - 1];
        if (str[i] == key[j]) {
            if (key[j + 1] == 0) {
                return true;

                j = pi[j];
            } else {
                j++;
            }
        }
    }

    return false;
}

int main() {
    scanf("%s %s %s", A, B, C);

    {
        int j = 0;
        for (int i = 1; C[i] != 0; i++) {
            while (j && C[i] != C[j]) j = pi[j - 1];
            if (C[i] == C[j]) pi[i] = ++j;
        }
    }

    printf("%s\n", search(A, C) && search(B, C) ? "YES" : "NO");

    return 0;
}
