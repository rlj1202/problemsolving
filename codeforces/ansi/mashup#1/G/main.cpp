#include <cstdio>

using namespace std;

int arr[502];
int types[502];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }
        for (int n = 0; n < N; n++) {
            scanf("%d", types + n);
        }

        bool sorted = true;
        for (int n = 0; n < N - 1; n++) {
            if (arr[n] > arr[n + 1]) {
                sorted = false;
                break;
            }
        }

        bool saturated = true;
        int firstType = types[0];
        for (int n = 1; n < N; n++) {
            if (firstType != types[n]) {
                saturated = false;
                break;
            }
        }

        bool result;

        if (saturated) {
            result = sorted;
        } else {
            result = true;
        }

        printf("%s\n", result ? "Yes" : "No");
    }

    return 0;
}
