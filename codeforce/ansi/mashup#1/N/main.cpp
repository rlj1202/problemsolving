#include <cstdio>

using namespace std;

int arr[1000006];
int answer[1000006];

int main() {
    int N, S; // 1e6
    scanf("%d %d", &N, &S);

    bool possible = false;
    int K;
    
    if (2*N <= S) {
        possible = true;
        K = 1;

        for (int n = 0; n < N; n++) {
            answer[n] = 2;
        }
        answer[N - 1] = S - 2*(N - 1);
    }

    printf("%s\n", possible ? "YES" : "NO");
    if (possible) {
        for (int n = 0; n < N; n++) {
            printf("%d ", answer[n]);
        }
        printf("\n");
        printf("%d\n", K);
    }

    return 0;
}
