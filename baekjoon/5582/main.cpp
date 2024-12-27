#include <algorithm>
#include <cstdio>

using namespace std;

char A[4003];
char B[4003];

int main() {
    scanf("%s %s", A, B);

    int answer = 0;

    for (int a = 0; A[a]; a++) {
        for (int b = 0; B[b]; b++) {
            int i;
            for (i = 0; A[a + i] && B[b + i]; i++) {
                if (A[a + i] != B[b + i]) {
                    break;
                }
            }

            answer = max(answer, i);
        }
    }

    printf("%d\n", answer);

    return 0;
}
