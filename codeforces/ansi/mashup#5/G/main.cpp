#include <cstdio>
#include <cstring>

using namespace std;

int arr[502];
bool backsorted[502];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, X;
        scanf("%d %d", &N, &X);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        memset(backsorted, 0, sizeof(backsorted));
        backsorted[N - 1] = true;
        for (int n = N - 2; n >= 0; n--) {
            if (arr[n] <= arr[n + 1]) {
                backsorted[n] = true;
            } else {
                break;
            }
        }

        int x = X;
        int count = 0;
        for (int n = 0; n < N; n++) {
            if (x < arr[n]) {
                if (backsorted[n]) {
                    break;
                }

                int tmp = arr[n];
                arr[n] = x;
                x = tmp;

                count++;
            }
        }

        bool sorted = true;
        for (int n = 1; n < N; n++) {
            if (arr[n - 1] > arr[n]) {
                sorted = false;
                break;
            }
        }

        printf("%d\n", sorted ? count : -1);
    }

    return 0;
}
