#include <algorithm>
#include <cstdio>

using namespace std;

int N;

int arr[12];
int ops[4];

int expr[12];

long long max_val = -0x3f3f3f3f;
long long min_val = 0x3f3f3f3f;

int dfs(int i) {
    if (i == N - 1) {
        long long val = arr[0];

        for (int n = 1; n < N; n++) {
            int op = expr[n - 1];

            if (op == 0) {
                val += arr[n];
            } else if (op == 1) {
                val -= arr[n];
            } else if (op == 2) {
                val *= arr[n];
            } else if (op == 3) {
                val /= arr[n];
            }
        }

        min_val = min(min_val, val);
        max_val = max(max_val, val);

        return 0;
    }

    for (int op = 0; op < 4; op++) {
        if (!ops[op]) {
            continue;
        }

        ops[op]--;
        expr[i] = op;

        dfs(i + 1);

        ops[op]++;
    }

    return 0;
}

int main() {
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", ops + i);
    }

    dfs(0);

    printf("%lld\n", max_val);
    printf("%lld\n", min_val);

    return 0;
}