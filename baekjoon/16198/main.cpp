#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int arr[12];
bool used[12];
int ans = 0;

void dfs(int left, int val) {
    if (left == 0) {
        ans = max(ans, val);
        return;
    }

    for (int i = 1; i < N - 1; i++) {
        if (used[i])
            continue;

        used[i] = true;

        int l = i - 1;
        int r = i + 1;
        while (used[l])
            l--;
        while (used[r])
            r++;

        dfs(left - 1, val + arr[l] * arr[r]);

        used[i] = false;
    }
}

int main() {
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    dfs(N - 2, 0);

    printf("%d\n", ans);

    return 0;
}