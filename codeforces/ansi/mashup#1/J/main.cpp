#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005]; // permutation
int stack[100005];
int top;

int main() {
    int T; // 2e4
    scanf("%d", &T);

    while (T--) {
        int N; // 1e5
        scanf("%d", &N);

        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        top = 0;

        for (int n = 0; n < N; n++) {
            if (top >= 2) {
                int a = stack[top - 2];
                int b = stack[top - 1];

                if (abs(a - b) + abs(b - arr[n]) == abs(a - arr[n])) {
                    top--;
                }
            }

            stack[top++] = arr[n];
        }

        printf("%d\n", top);
        for (int i = 0; i < top; i++) printf("%d ", stack[i]);
        printf("\n");
    }

    return 0;
}
