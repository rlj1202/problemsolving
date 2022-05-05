#include <cstdio>
#include <algorithm>

using namespace std;

struct element {
    long long index, value;

    bool operator<(const element& o) const {
        if (value == o.value) return index < o.index;
        return value < o.value;
    }
};

element arr[100005];


int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            int value;
            scanf("%d", &value);

            arr[n] = { n, value };
        }
        sort(arr, arr + N);

        long long result = 0;

        for (int i = 1; i < N; i++) {
            if (arr[i - 1].value == arr[i].value) {
                result += (arr[i - 1].index + 1) * (N - arr[i].index);

                arr[i].index += arr[i - 1].index + 1;
            }
        }

        printf("%lld\n", result);
    }

    return 0;
}
