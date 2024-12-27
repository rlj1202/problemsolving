#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;

int arr[12];
int ops[4];

int min_val = INF;
int max_val = -INF;

void dfs(int i, int value) {
    if (i == N) {
        min_val = min(min_val, value);
        max_val = max(max_val, value);

        return;
    }

    for (int j = 0; j < 4; j++) {
        if (!ops[j])
            continue;

        ops[j]--;

        int next = value;

        if (j == 0) {
            next += arr[i];
        } else if (j == 1) {
            next -= arr[i];
        } else if (j == 2) {
            next *= arr[i];
        } else {
            next /= arr[i];
        }

        dfs(i + 1, next);

        ops[j]++;
    }
}

int main() {
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", ops + i);
    }

    dfs(1, arr[0]);

    printf("%d\n", max_val);
    printf("%d\n", min_val);

    return 0;
}