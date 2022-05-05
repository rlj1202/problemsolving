#include <cstdio>
#include <algorithm>

using namespace std;

double max_score[102];

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            int I;
            double S;
            scanf("%d %lf", &I, &S);

            max_score[I] = max(max_score[I], S);
        }
    }

    sort(max_score + 1, max_score + N + 1);

    double answer = 0.0;

    for (int k = 1; k <= K; k++) {
        answer += max_score[N - k + 1];
    }

    printf("%.1f\n", answer);

    return 0;
}
