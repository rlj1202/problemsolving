#include <cstdio>

using namespace std;

char S[1000006];

int pi[1000006];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", S);

    {
        int j = 0;
        for (int i = 1; i < N; i++) {
            while (j && S[i] != S[j]) j = pi[j - 1];

            if (S[i] == S[j]) pi[i] = ++j;
        }
    }

    for (int i = 0; i < N; i++) {

    }

    printf("%d\n", 0);

    return 0;
}
