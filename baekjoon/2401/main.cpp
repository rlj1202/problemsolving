#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char L[100005];

char buffer[10004];
int pi[10004];

vector<int> shorts[100005];
int dp[100005];

int main() {
    scanf("%s", L);
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%s", buffer);

        int len = strlen(buffer);

        int j = 0;
        for (int i = 1; buffer[i] != 0; i++) {
            while (j && buffer[i] != buffer[j]) j = pi[j - 1];
            if (buffer[i] == buffer[j]) pi[i] = ++j;
        }

        j = 0;
        for (int i = 0; L[i] != 0; i++) {
            while (j && L[i] != buffer[j]) j = pi[j - 1];
            if (L[i] == buffer[j]) {
                if (buffer[j + 1] == 0) {
                    shorts[i].push_back(len);

                    j = pi[j];
                } else {
                    j++;
                }
            }
        }
    }

    for (int i = 0; L[i] != 0; i++) {
        if (i - 1 >= 0) dp[i] = max(dp[i], dp[i - 1]);

        for (int len : shorts[i]) {
            if (i - len >= 0) dp[i] = max(dp[i], len + dp[i - len]);
            else dp[i] = max(dp[i], len);
        }
    }

    printf("%d\n", dp[strlen(L) - 1]);

    return 0;
}