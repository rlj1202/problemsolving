#include <cstdio>

using namespace std;

char str[100005];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", str);

    int chickens = 0;
    for (int n = 0; n < N; n++) {
        if (str[n] == 'C') {
            chickens++;
        }
    }
    int blocks = N - chickens + 1;
    int result = N / blocks;

    printf("%d\n", result);

    return 0;
}