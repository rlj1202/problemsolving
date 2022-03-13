#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];
int lastset[200005];
int setmax[200005];

int main() {
    int N; // 2e5
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }
    int Q; // 2e5
    scanf("%d", &Q);
    for (int q = 1; q <= Q; q++) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            int p, x;
            scanf("%d %d", &p, &x);
            arr[p] = x;
            lastset[p] = q;
        } else {
            int x;
            scanf("%d", &x);
            setmax[q] = x;
        }
    }

    for (int q = Q - 1; q >= 0; q--) {
        setmax[q] = max(setmax[q], setmax[q + 1]);
    }

    for (int n = 1; n <= N; n++) {
        arr[n] = max(arr[n], setmax[lastset[n]]);
    }

    for (int n = 1; n <= N; n++) printf("%d ", arr[n]);
    printf("\n");

    return 0;
}
