#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000006];

int main() {
    while (true) {
        int X; // centimeter 1e-2, 20
        if (scanf("%d", &X) == EOF) {
            break;
        }
        X *= 1e7;

        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n); // nanometer 1e-9 
        }
        sort(arr, arr + N);

        bool found = false;
        for (int n = 0; n < N; n++) {
            int remains = X - arr[n];
            int foundIdx = lower_bound(arr + n + 1, arr + N, remains) - arr;

            if (foundIdx == N) continue;

            if (arr[n] + arr[foundIdx] == X) {
                printf("yes %d %d\n", arr[n], arr[foundIdx]);
                found = true;
                break;
            }
        }

        if (!found) printf("danger\n");
    }

    return 0;
}
