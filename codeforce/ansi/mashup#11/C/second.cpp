#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];

int result_power;
int result_l;
int result_r;

void query(int l, int r) {
    int power = 0;
    bool neg = false;

    for (int i = l; i < r; i++) {
        if (abs(arr[i]) == 2) power++;
        if (arr[i] < 0) neg = !neg;
    }

    if (!neg && result_power < power) {
        result_power = power;
        result_l = l;
        result_r = r;
    } else if (neg) {
        int cur_power, i;

        cur_power = power;
        i = r;
        while (l < i) {
            int cur = arr[--i];
            if (abs(cur) == 2) cur_power--;
            if (cur < 0) break;
        }

        if (result_power < cur_power) {
            result_power = cur_power;
            result_l = l;
            result_r = i;
        }

        cur_power = power;
        i = l;
        while (i < r) {
            int cur = arr[i++];
            if (abs(cur) == 2) cur_power--;
            if (cur < 0) break;
        }

        if (result_power < cur_power) {
            result_power = cur_power;
            result_l = i;
            result_r = r;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        result_power = 0;
        result_l = N;
        result_r = N;

        int prev = 0;
        for (int n = 0; n < N; n++) {
            if (arr[n] == 0) {
                query(prev, n);

                prev = n + 1;
            }
        }
        query(prev, N);

        printf("%d %d\n", result_l, N - result_r);
    }

    return 0;
}
