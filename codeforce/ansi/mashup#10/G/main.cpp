#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[200005];
int B[200005];

pair<int, int> A_max[200005];
pair<int, int> B_max[200005];

int A_groups[200005];
int B_groups[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            scanf("%d", A + n);
        }
        for (int n = 1; n <= N; n++) {
            scanf("%d", B + n);
        }

        memset(A_groups, 0, sizeof(A_groups));
        memset(B_groups, 0, sizeof(B_groups));

        for (int n = 2; n <= N; n++) {
            if (A[n - 1] != A[n]) {
                A_groups[A[n - 1]]++;
            }
        }
        A_groups[A[N]]++;
        for (int n = 2; n <= N; n++) {
            if (B[n - 1] != B[n]) {
                B_groups[B[n - 1]]++;
            }
        }
        B_groups[B[N]]++;

        for (int n = 1; n <= N; n++) {
            A_max[n].first = 0;
            B_max[n].first = 0;
            A_max[n].second = n;
            B_max[n].second = n;
        }

        for (int n = 1; n <= N; n++) {
            A_max[A[n]].first = max(A_max[A[n]].first, n);
        }
        for (int n = 1; n <= N; n++) {
            B_max[B[n]].first = max(B_max[B[n]].first, n);
        }

        sort(A_max + 1, A_max + N + 1);
        sort(B_max + 1, B_max + N + 1);

        bool valid = true;

        for (int n = 1; n <= N; n++) {
            if (A_max[n].second != B_max[n].second) {
                valid = false;
                break;
            }
        }

        for (int n = 1; n <= N; n++) {
            if (A_groups[n] < B_groups[n]) {
                valid = false;
                break;
            }
        }

        printf("%s\n", valid ? "YES" : "NO");
    }

    return 0;
}
