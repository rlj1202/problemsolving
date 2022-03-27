#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int A[1003];
int B[1003];

vector<int> preA;

int main() {
    int S;
    scanf("%d", &S);
    int M, N;
    scanf("%d %d", &M, &N);
    for (int m = 1; m <= M; m++) {
        scanf("%d", A + m);
    }
    for (int n = 1; n <= N; n++) {
        scanf("%d", B + n);
    }

    for (int m = 1; m <= M; m++) {
        A[m] += A[m - 1];
    }
    for (int n = 1; n <= N; n++) {
        B[n] += B[n - 1];
    }

    int answer = 0;

    for (int m = 1; m <= M; m++) {
        for (int l = 0; l < m; l++) {
            int sum = A[m] - A[l];

            preA.push_back(sum);
            if (sum == S) answer++;

            if (l > 0 && m < M) {
                preA.push_back(A[M] - sum);
                if (A[M] - sum == S) answer++;
            }
        }
    }
    sort(preA.begin(), preA.end());

    for (int n = 1; n <= N; n++) {
        for (int l = 0; l < n; l++) {
            int sum = B[n] - B[l];

            if (sum == S) {
                answer++;
            } else if (sum < S) {
                int remain = S - sum;
         
                int count =
                    upper_bound(preA.begin(), preA.end(), remain)
                    - lower_bound(preA.begin(), preA.end(), remain);
         
                answer += count;
            }

            if (l > 0 && n < N) {
                int invSum = B[N] - sum;

                if (invSum == S) {
                    answer++;
                } else if (invSum < S) {
                    int remain = S - invSum;

                    int count =
                        upper_bound(preA.begin(), preA.end(), remain)
                        - lower_bound(preA.begin(), preA.end(), remain);

                    answer += count;
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
