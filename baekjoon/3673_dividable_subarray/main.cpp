#include <cstdio>
#include <cstring>

using namespace std;

int arr[50004];
int count[1000006];

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int D, N;
        scanf("%d %d", &D, &N);
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);
            arr[n] += arr[n - 1];
            arr[n] %= D;
        }

        memset(count, 0, sizeof(count));
        count[0]++;
        int result = 0;
        for (int n = 1; n <= N; n++) {
            int remains = arr[n];

            result += count[remains];
            count[remains]++;
        }

        printf("%d\n", result);
    }

    return 0;
}