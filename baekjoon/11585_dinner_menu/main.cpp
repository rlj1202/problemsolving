#include <cstdio>

int N;
char S[2000006];
char P[1000006];

int pi[1000006];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf(" %c", P + n);
	for (int n = 0; n < N; n++) scanf(" %c", S + n);

    for (int n = 0; n < N; n++) S[n + N] = S[n];
    
    {
        int j = 0;
        for (int i = 1; P[i] != 0; i++) {
            while (j && P[i] != P[j]) j = pi[j - 1];

            if (P[i] == P[j]) pi[i] = ++j;
        }
    }

    int total = N;
    int count = 0;

    {
        int j = 0;
        for (int i = 0; S[i + 1] != 0; i++) {
            while (j && S[i] != P[j]) j = pi[j - 1];

            if (S[i] == P[j]) {
                if (P[j + 1] == 0) {
                    count++;
                    j = pi[j];
                } else {
                    j++;
                }
            }
        }
    }

    int div = gcd(total, count);
    total /= div;
    count /= div;

	printf("%d/%d\n", count, total);

	return 0;
}
