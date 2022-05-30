#include <cstdio>
#include <cstring>

using namespace std;

char S[500005];
long long K;

int pi[500005];

int main() {
    scanf("%s", S);
    scanf("%lld", &K);

    long long len = strlen(S);

    {
        int j = 0;
        for (int i = 1; S[i] != 0; i++) {
            while (j && S[i] != S[j]) j = pi[j - 1];
            if (S[i] == S[j]) pi[i] = ++j;
        }
    }

    printf("%lld\n", len * K - (long long) pi[len - 1] * (K - 1));

    return 0;
}
