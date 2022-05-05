#include <cstdio>

using namespace std;

int arr[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        bool valid = true;

        if (N > 1) {
            int prev = arr[N - 1];
            for (int n = 0; n < N; n++) {
                if (prev < arr[n]) {
                    if (arr[n] - prev != 1) {
                        valid = false;
                        break;
                    }
                }
         
                prev = arr[n];
            }
        }

        int ones = 0;
        for (int n = 0; n < N; n++) {
            if (arr[n] == 1) {
                ones++;
            }
        }

        if (ones != 1) {
            valid = false;
        }

        printf("%s\n", valid ? "YES" : "NO");
    }

    return 0;
}
