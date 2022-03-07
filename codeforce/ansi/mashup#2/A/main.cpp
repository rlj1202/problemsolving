#include <cstdio>

using namespace std;

int arr[1003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        int aliceTotal = 0;
        int bobTotal = 0;

        int alice = 0;
        int bob = 0;

        int left = 0;
        int right = N;

        int moves = 0;

        while (right - left > 0) {
            alice = 0;
            while (alice <= bob && right - left > 0) {
                alice += arr[left++];
            }

            aliceTotal += alice;
            if (alice > 0) moves++;

            bob = 0;
            while (bob <= alice && right - left > 0) {
                bob += arr[--right];
            }

            bobTotal += bob;
            if (bob > 0) moves++;
        }

        printf("%d %d %d\n", moves, aliceTotal, bobTotal);
    }

    return 0;
}
