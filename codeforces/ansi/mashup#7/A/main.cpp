#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int A[100005];
int B[100005];
int C[100005];

int colored[100005];
vector<int> uncolored[100005];

int result[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        for (int n = 1; n <= N; n++) {
            scanf("%d", A + n);
        }
        for (int n = 1; n <= N; n++) {
            scanf("%d", B + n);
        }
        for (int m = 1; m <= M; m++) {
            scanf("%d", C + m);
        }

        memset(colored, 0, sizeof(colored));

        for (int n = 1; n <= N; n++) uncolored[n].clear();
        for (int n = 1; n <= N; n++) {
            if (A[n] != B[n]) {
                uncolored[B[n]].push_back(n);
            } else {
                colored[B[n]] = n;
            }
        }

        vector<int> unused;
        for (int m = 1; m <= M; m++) {
            if (uncolored[C[m]].size()) {
                int index = uncolored[C[m]].back();
                uncolored[C[m]].pop_back();

                result[m] = index;
                colored[C[m]] = index;

                while (!unused.empty()) {
                    int painter = unused.back();
                    unused.pop_back();

                    result[painter] = index;
                }
            } else if (colored[C[m]]) {
                result[m] = colored[C[m]];

                while (!unused.empty()) {
                    int painter = unused.back();
                    unused.pop_back();

                    result[painter] = colored[C[m]];
                }
            } else {
                unused.push_back(m);
            }
        }

        bool possible = unused.empty();

        for (int n = 1; n <= N; n++) {
            if (!uncolored[n].empty()) {
                possible = false;
                break;
            }
        }

        printf("%s\n", possible ? "YES" : "NO");
        if (possible) {
            for (int m = 1; m <= M; m++) {
                printf("%d ", result[m]);
            }
            printf("\n");
        }
    }

    return 0;
}
