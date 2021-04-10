#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[5003];

int min_index[400005 + 10];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        // -100,000 ~ 100,000
        scanf("%d", arr + n);
    }

    memset(min_index, 0x3f, sizeof(min_index));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = arr[i] + arr[j];
            min_index[sum + 200005] = min(min_index[sum + 200005], i);
        }
    }

    int result = 0;

    // O(N^2 * log N)
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int k = arr[i] - arr[j];

            if (min_index[k + 200005] < i) { // query k in range [0, i)
                result++;
                break;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}