#include <cstdio>

using namespace std;

char temp[2003];
int map[2003][2003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int r = 0; r < N; r++) {
            scanf("%s", temp);
            for (int c = 0; c < N; c++) {
                map[r][c] = temp[c] - '0';
            }
        }

        for (int r = 0; r < N - 1; r++) {
            for (int c = 0; c < N; c++) {
                map[r + 1][(c + 1) % N] += map[r][c];
            }
        }

        int sum = 0;
        int maxVal = 0;
        for (int c = 0; c < N; c++) {
            int cur = map[N - 1][c];
            sum += cur;
            if (maxVal < cur) {
                maxVal = cur;
            }
        }

        int answer = (N - maxVal) + (sum - maxVal);

        printf("%d\n", answer);
    }

    return 0;
}
