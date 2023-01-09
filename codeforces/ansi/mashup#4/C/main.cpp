#include <cstdio>
#include <algorithm>

using namespace std;

int left[100005];
int right[100005];

struct element { int value, index; };
element arr[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) scanf("%d", left + n);
        for (int n = 1; n <= N; n++) scanf("%d", right + N - n + 1);

        for (int n = 1; n <= N; n++) {
            if (left[n] == 2) left[n] = -1;
            if (right[n] == 2) right[n] = -1;
        }
        for (int n = 2; n <= N; n++) {
            left[n] += left[n - 1];
            right[n] += right[n - 1];
        }

        for (int n = 0; n <= N; n++) {
            arr[n] = { right[n], n };
        }
        sort(arr, arr + N + 1, [](const element& a, const element& b) -> bool {
            if (a.value == b.value) return a.index > b.index;
            return a.value < b.value;
        });

        int answer = N*2;

        for (int n = 0; n <= N; n++) {
            element target = { -left[n] };
            element* result = lower_bound(
                arr, arr + N + 1, target,
                [](const element& a, const element& b) -> bool {
                    return a.value < b.value;
                });

            if (result == arr + N + 1) continue;

            if (left[n] + result->value == 0) {
                int jars = (N - n) + (N - result->index);

                answer = min(answer, jars);
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}
