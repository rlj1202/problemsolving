#include <cstdio>

using namespace std;

int arr[300005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        bool result = arr[0] < arr[N - 1];

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
