#include <cstdio>
#include <algorithm>

using namespace std;

char str[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        scanf("%s", str);

        int cur_max = 0;

        for (int n = 0; n < N && K; n++) {
            int cur = str[n] - 'a';

            if (cur <= cur_max) {
                continue;
            }

            int remain_k = K - cur_max;

            if (!remain_k) break;

            if (cur - cur_max <= remain_k) {
                cur_max = cur;
            } else {
                int target = cur - remain_k;
                str[n] = target + 'a';

                for (int i = n + 1; i < N; i++) {
                    int next = str[i] - 'a';

                    if (target < next && next <= cur) {
                        str[i] = target + 'a';
                    }
                }

                K -= remain_k;
            }
        }

        for (int n = 0; n < N; n++) {
            int cur = str[n] - 'a';
            if (cur <= cur_max) {
                str[n] = 'a';
            }
        }

        printf("%s\n", str);
    }

    return 0;
}
