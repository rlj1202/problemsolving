#include <cstdio>

using namespace std;

int arr[100005];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
        arr[n] += arr[n - 1];
    }
    int M;
    scanf("%d", &M);
    while (M--) {
        int i, j;
        scanf("%d %d", &i, &j);

        printf("%d\n", arr[j] - arr[i - 1]);
    }

    return 0;
}