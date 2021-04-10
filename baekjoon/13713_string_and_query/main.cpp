#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[1000006];
char tmp[1000006];

int Z[1000006];

int main() {
    scanf("%s", tmp);
    int M; // 1e5
    scanf("%d", &M);

    int len = strlen(tmp);
    for (int i = 0; i < len; i++) {
        S[i] = tmp[len - i - 1];
    }

    Z[0] = len;
    int l = 0, r = 0;
    for (int i = 1; i < len; i++) {
        if (i > r) {
            l = r = i;
        } else {
            int k = i - l;
            if (Z[k] < r - i) {
                Z[i] = Z[k];
                continue;
            }

            l = i;
        }

        while (S[r] == S[r - l]) r++;
        Z[i] = r - l;
    }
    
    while (M--) {
        int i;
        scanf("%d", &i);
        i = len - i;

        printf("%d\n", Z[i]);
    }

    return 0;
}