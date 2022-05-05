#include <cstdio>

using namespace std;

long long arr[1003];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, K;
        scanf("%d %d", &N, &K);

        for (int n = 0; n < N; n++) {
            scanf("%lld", arr + n);
        }

        long long sum = 0;
        long long result = 0;

        for (int n = 0; n < N; n++) {
            result += sum * arr[n];
            sum += arr[n];
        }

        printf("\t%lld %lld\n", sum, result);

        bool possible = false;
        long long answer;

        if (result == 0) {
            answer = 0;
            possible = true;
        } else if (sum != 0) {
            answer = -result / sum;

            if (sum * answer + result == 0) {
                possible = true;
            }
        }

        printf("Case #%d: ", t);
        if (possible) printf("%lld", answer);
        else printf("IMPOSSIBLE");
        printf("\n");
    }

    return 0;
}
