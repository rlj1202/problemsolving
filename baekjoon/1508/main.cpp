#include <cstdio>

using namespace std;

int arr[52];
char answer[52];

int main() {
    int N, M, K; // 1e6
    scanf("%d %d %d", &N, &M, &K);
    for (int k = 0; k < K; k++) {
        scanf("%d", arr + k);
    }

    int l = 0;
    int r = N;
 
    while (r - l) {
        int mid = (l + r + 1) / 2;
 
        int count = 1;
        int prev = arr[0];
        for (int k = 1; k < K; k++) {
            if (arr[k] - prev >= mid) {
                count++;
                prev = arr[k];
            }
        }
 
        if (count >= M) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    for (int k = 0; k < K; k++) answer[k] = '0';
    answer[K] = 0;

    answer[0] = '1';

    int count = 1;
    int prev = arr[0];
    for (int k = 1; k < K && count < M; k++) {
        if (arr[k] - prev >= l) {
            answer[k] = '1';
            prev = arr[k];
            count++;
        }
    }

    printf("%s\n", answer);

    return 0;
}
