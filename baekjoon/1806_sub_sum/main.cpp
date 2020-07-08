#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int arr[100005];

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    int result = INF;

    int l = 0;
    int r = 0;
    int curSum = 0;

    while (l < N) {
        if (r < N && curSum < S) {
            curSum += arr[r++];
        } else {
            curSum -= arr[l++];
        }

        if (curSum >= S) {
            result = min(result, r - l);
        }
    }

    printf("%d\n", result != INF ? result : 0);

    return 0;
}