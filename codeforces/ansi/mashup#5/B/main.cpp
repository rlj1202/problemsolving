#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        bool result = true;

        int minheight = arr[0];
        int maxheight = arr[0];

        for (int n = 1; n < N; n++) {
            int nextminheight = minheight - K + 1;
            int nextmaxheight = maxheight + K - 1;

            nextminheight = max(nextminheight, arr[n]);
            nextmaxheight = min(nextmaxheight, arr[n] + K - 1);

            if (nextminheight > nextmaxheight) {
                result = false;
                break;
            }

            minheight = nextminheight;
            maxheight = nextmaxheight;
        }

        if (result) {
            if (arr[N - 1] < minheight || maxheight < arr[N - 1]) {
                result = false;
            }
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
