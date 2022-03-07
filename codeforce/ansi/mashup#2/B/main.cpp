#include <cstdio>

using namespace std;

int arr[200005];
int cnt[22];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    for (int n = 0; n < N; n++) {
        int cur = arr[n];

        int i = 0;
        while (cur) {
            cnt[i] += cur % 2;

            cur >>= 1;
            i++;
        }
    }

    long long result = 0;

    for (int n = 0; n < N; n++) {
        long long number = 0;

        for (int i = 0; i < 22; i++) {
            if (cnt[i]) {
                cnt[i]--;
                number += 1LL << i;
            }
        }

        if (number == 0) break;

        result += number * number;
    }

    printf("%lld\n", result);

    return 0;
}
