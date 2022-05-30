#include <cstdio>

using namespace std;

char str[1000006];

int pi[1000006];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", str);

    {
        int j = 0;
        for (int i = 1; i < N; i++) {
            while (j && str[i] != str[j]) j = pi[j - 1];
            if (str[i] == str[j]) pi[i] = ++j;
        }
    }

    printf("%d\n", 0);

    return 0;
}
