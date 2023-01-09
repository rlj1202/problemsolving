#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[4003];
vector<int> lens;

bool possible[4003][2003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N*2; n++) {
            scanf("%d", arr + n);
        }

        lens.clear();

        int maxValue = arr[0];
        int len = 0;
        for (int n = 0; n < N*2; n++) {
            int cur = arr[n];

            if (maxValue < cur) {
                maxValue = cur;

                lens.push_back(len);
                len = 1;
            } else {
                len++;
            }
        }
        lens.push_back(len);

        // It is now a subset-sum problem

        sort(lens.begin(), lens.end());

        memset(possible, 0, sizeof(possible));
        possible[0][0] = true;

        bool result = false;

        for (int i = 1; i <= lens.size(); i++) {
            for (int n = 0; n <= N; n++) {
                possible[i][n] |= possible[i - 1][n];
                if (n - lens[i - 1] >= 0)
                    possible[i][n] |= possible[i - 1][n - lens[i - 1]];
            }

            result |= possible[i][N];
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
