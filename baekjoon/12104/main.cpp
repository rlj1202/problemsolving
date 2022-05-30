#include <cstdio>
#include <cstring>

using namespace std;

char A[200005];
char B[100005];

int pi[100005];

int main() {
    scanf("%s", A);
    scanf("%s", B);

    int len = strlen(A);
    for (int i = 0; i < len; i++) A[i + len] = A[i];

    {
        int j = 0;
        for (int i = 1; B[i] != 0; i++) {
            while (j && B[i] != B[j]) j = pi[j - 1];
            if (B[i] == B[j]) pi[i] = ++j;
        }
    }

    int result = 0;

    int j = 0;
    for (int i = 0; A[i + 1] != 0; i++) {
        while (j && A[i] != B[j]) j = pi[j - 1];
        if (A[i] == B[j]) {
            if (B[j + 1] == 0) {
                result++;

                j = pi[j];
            } else {
                j++;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}