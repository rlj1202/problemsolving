#include <cstdio>
#include <algorithm>

using namespace std;

int A[200005];
int B[200005];
int dist[200005];

int main() {
    int N; // 2e5
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int value;
        scanf("%d", &value);
        A[value] = n;
    }
    for (int n = 0; n < N; n++) {
        int value;
        scanf("%d", &value);
        B[value] = n;
    }

    for (int n = 1; n <= N; n++) {
        int value = A[n] - B[n];
        if (value < 0) value += N;
        value %= N;

        dist[value]++;
    }

    int result = 0;

    for (int n = 0; n < N; n++) {
        result = max(result, dist[n]);
    }

    printf("%d\n", result);

    return 0;
}
