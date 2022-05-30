#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char L[100005];

char strs[502][10004];
int lens[502];
int pis[502][10004];
int js[502];

int dp[100005];

int main() {
    scanf("%s", L);
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        char* cur = strs[n];
        scanf("%s", cur);

        int* pi = pis[n];

        lens[n] = strlen(cur);

        int j = 0;
        for (int i = 1; cur[i] != 0; i++) {
            while (j && cur[i] != cur[j]) j = pi[j - 1];
            if (cur[i] == cur[j]) pi[i] = ++j;
        }
    }

    for (int i = 0; L[i] != 0; i++) {
        if (i) dp[i] = max(dp[i], dp[i - 1]);

        for (int n = 0; n < N; n++) {
            char* cur = strs[n];
            int& j = js[n];
            int* pi = pis[n];

            while (j && L[i] != cur[j]) j = pi[j - 1];
            if (L[i] == cur[j]) {
                if (cur[j + 1] == 0) {
                    if (i - lens[n] >= 0) dp[i] = max(dp[i], dp[i - lens[n]] + lens[n]);
                    else dp[i] = lens[n];

                    j = pi[j];
                } else {
                    j++;
                }
            }
        }
    }

    printf("%d\n", dp[strlen(L) - 1]);

    return 0;
}