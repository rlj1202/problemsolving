#include <cstdio>

using namespace std;

const int MOD = 1e4 + 7;

int comb[53][53];

int w[53][53];
int l[53][53];

int main() {
    for (int i = 0; i <= 52; i++) {
        comb[i][0] = 1;
        
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= MOD;
        }
    }

    // 52
    int N;
    scanf("%d", &N);

    w[4][4] = 1;

    for (int deck = 0; deck <= 4; deck++) {
        for (int i = 0; i <= deck; i++) {
            l[deck][i] = comb[deck][i];
        }
    }
    l[4][4] = 0;

    for (int deck = 8; deck <= 52; deck += 4) {
        for (int i = 4; i <= deck; i++) {
            for (int j = 1; j <= i / 4; j++) {
                w[deck][i] += l[deck - 4 * j][i - 4 * j] * comb[deck / 4][j];
                w[deck][i] %= MOD;
            }
        }
        for (int i = 0; i <= deck; i++) {
            l[deck][i] = comb[deck][i] - w[deck][i];
            if (l[deck][i] < 0) l[deck][i] += MOD;
        }
    }

    printf("%d\n", w[52][N]);

    for (int i = 4; i <= 52; i++) {
        printf("%d : %d\n", i, w[52][i]);
    }

    return 0;
}