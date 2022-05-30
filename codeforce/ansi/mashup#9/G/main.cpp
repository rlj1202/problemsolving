#include <cstdio>

using namespace std;

char str[200005];

int pairs[26][26];
int sum[26];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int pos = 0;

    for (int i = 0; i < K; i++) {
        str[pos++] = 'a' + i;

        for (int j = i + 1; j < K; j++) {
            str[pos++] = 'a' + i;
            str[pos++] = 'a' + j;
        }
    }

    for (int n = 0; n < N; n++) {
        printf("%c", str[n % pos]);
    }
    printf("\n");

    return 0;
}
