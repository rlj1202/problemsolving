#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char A[1000006];
char B[1000006];

int Alower[26];
int Aupper[26];

int Blower[26];
int Bupper[26];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        scanf("%s %s", A, B);

        memset(Alower, 0, sizeof(Alower));
        memset(Aupper, 0, sizeof(Aupper));
        memset(Blower, 0, sizeof(Blower));
        memset(Bupper, 0, sizeof(Bupper));

        for (int n = 0; n < N; n++) {
            int cur = A[n] - 'a';
            Alower[cur]++;
        }
        for (int i = 0; i < 26; i++) {
            Aupper[i] = Alower[i] / K;
            Alower[i] %= K;
        }

        int prev = B[0] - 'a';
        int len = 1;
        for (int n = 1; n < N; n++) {
            int cur = B[n] - 'a';

            if (prev == cur) {
                len++;
            } else {
                Blower[prev] += len % K;
                Bupper[prev] += len / K;

                prev = cur;
                len = 1;
            }
        }
        Blower[prev] += len % K;
        Bupper[prev] += len / K;

        for (int i = 0; i < 26; i++) {
            int lower_min = min(Blower[i], Alower[i]);
            Blower[i] -= lower_min;
            Alower[i] -= lower_min;
            for (int j = 0; j <= i; j++) {
                int upper_min = min(Blower[i] / K, Aupper[j]);
                Blower[i] -= upper_min * K;
                Aupper[j] -= upper_min;
            }

            for (int j = 0; j <= i; j++) {
                int upper_min = min(Bupper[i], Aupper[j]);
                Bupper[i] -= upper_min;
                Aupper[j] -= upper_min;
            }
        }

        bool valid = true;
        for (int i = 0; i < 26; i++) {
            if (Blower[i] || Bupper[i]) {
                valid = false;
                break;
            }
        }

        printf("%s\n", valid ? "Yes" : "No");
    }

    return 0;
}