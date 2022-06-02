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

        for (int i = 0; i < N && K > 0; i++) {
            int cur = str[i] - 'a';

            int delta = min(cur, K);
            int pivot = cur;
            for (int j = 0; j < N; j++) {
                int next = str[j] - 'a';

                if (delta < next && next <= K) {
                    delta = next;
                    pivot = next;
                }
            }

            for (int j = 0; j < N; j++) {
                int next = str[j] - 'a';
                if (pivot < next) continue;

                str[j] = min(next, pivot - delta) + 'a';
            }

            K -= delta;
        }

        printf("%s\n", str);
    }

    return 0;
}
