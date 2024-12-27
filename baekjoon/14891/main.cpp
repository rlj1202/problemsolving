#include <algorithm>
#include <cstdio>

using namespace std;

char states[4][9];

int rotate(char *str, int dir) {
    if (dir == 1) {
        char last = str[7];
        for (int k = 7; k > 0; k--) {
            str[k] = str[k - 1];
        }
        str[0] = last;
    } else {
        char first = str[0];
        for (int k = 0; k < 8 - 1; k++) {
            str[k] = str[k + 1];
        }
        str[7] = first;
    }

    return 0;
}

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%s", states[i]);
    }

    int K;
    scanf("%d", &K);

    while (K--) {
        int i, d;
        scanf("%d %d", &i, &d);
        i--;

        int l = i;
        int r = i;

        while (r + 1 < 4) {
            char left = states[r][2];
            char right = states[r + 1][6];

            if (left == right) {
                break;
            }
            r++;
        }
        while (l - 1 >= 0) {
            char left = states[l - 1][2];
            char right = states[l][6];

            if (left == right) {
                break;
            }
            l--;
        }

        if ((i - l) % 2 == 1) {
            d *= -1;
        }
        for (int k = l; k <= r; k++) {
            rotate(states[k], d);
            d *= -1;
        }
    }

    int answer = 0;
    for (int i = 0; i < 4; i++) {
        answer += (states[i][0] - '0') << i;
    }

    printf("%d\n", answer);

    return 0;
}
