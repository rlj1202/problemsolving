#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[200005];
vector<int> ks;

int main() {
    int N, A, B, K; // 2e5, 1e9, 1e9, 1e9
    scanf("%d %d %d %d", &N, &A, &B, &K);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n); // 1e9
    }

    int result = 0;

    for (int n = 0; n < N; n++) {
        int remains = arr[n] % (A + B);

        if (1 <= remains && remains <= A) {
            result++;
        } else {
            int k;
            if (remains == 0) {
                k = (B + A - 1) / A;
            } else {
                k = (remains - 1) / A;
            }
            ks.push_back(k);
        }
    }
    sort(ks.begin(), ks.end());

    for (int i = 0; i < ks.size(); i++) {
        int cur = ks[i];

        if (cur <= K) {
            K -= cur;
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}
