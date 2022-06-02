#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int arr[200005];

struct node {
    int index;
    int value;

    bool operator<(const node &o) const {
        if (abs(value) == abs(value)) return index > o.index;
        return abs(value) > abs(o.value);
    }
};

priority_queue<node> positive;
priority_queue<node> negative;

int find_max(int l, int r, int *max_l, int *max_r) {
    int result = 1;
    *max_l = l;
    *max_r = l;

    int cur_prod = 1;
    positive = priority_queue<node>();
    negative = priority_queue<node>();

    for (int i = l; i < r; i++) {
        cur_prod *= arr[i];

        int cur = cur_prod;
        int left = l - 1;

        if (result < cur) {
            result = cur;
            *max_l = left + 1;
            *max_r = i;
        }

        if (cur_prod > 0) {
            if (!positive.empty()) {
                cur = cur_prod / positive.top().value;
                left = positive.top().index;
            }

            positive.push({ i, cur_prod });
        } else {
            if (!negative.empty()) {
                cur = cur_prod / negative.top().value;
                left = negative.top().index;
            }

            negative.push({ i, cur_prod });
        }

        if (result < cur) {
            result = cur;
            *max_l = left + 1;
            *max_r = i;
        }
    }

    return result;
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

        int result = 1;
        int result_l = N;
        int result_r = 0;

        int prev = 0;
        for (int n = 0; n < N; n++) {
            if (arr[n] == 0) {
                int l, r;
                int cur = find_max(prev, n, &l, &r);
                if (result < cur) {
                    result = cur;
                    result_l = l;
                    result_r = N - r - 1;
                }

                prev = n + 1;
            }
        }
        {
            int l, r;
            int cur = find_max(prev, N, &l, &r);
            if (result < cur) {
                result = cur;
                result_l = l;
                result_r = N - r - 1;
            }
        }

        printf("%d %d\n", result_l, result_r);
    }

    return 0;
}
