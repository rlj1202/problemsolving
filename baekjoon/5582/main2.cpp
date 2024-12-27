#include <algorithm>
#include <cstdio>

using namespace std;

char A[4003];
char B[4003];

int dp[4003][4003];

int main() {
    scanf("%s %s", A, B);

    int answer = 0;

    for (int a = 0; A[a]; a++) {
        for (int b = 0; B[b]; b++) {
            if (A[a] == B[b]) {
                dp[a + 1][b + 1] = dp[a][b] + 1;
            }

            answer = max(answer, dp[a + 1][b + 1]);
        }
    }

    printf("%d\n", answer);

    return 0;
}
