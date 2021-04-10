#include <cstdio>
#include <algorithm>

using namespace std;

struct cow {
    int pos;
    bool sick;

    bool operator< (const cow &o) const {
        return pos < o.pos;
    }
};

cow cows[1003];

int groups[1003];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        int x, s;
        scanf("%d %d", &x, &s);
        cows[n] = {x, s};
    }

    sort(cows, cows + N);

    int max_range = 0x3f3f3f3f;

    for (int i = 0; i < N; i++) {
        if (cows[i].sick) {
            if (i + 1 < N && !cows[i + 1].sick) {
                max_range = min(max_range, cows[i + 1].pos - cows[i].pos);
            }
            if (i - 1 >= 0 && !cows[i - 1].sick) {
                max_range = min(max_range, cows[i].pos - cows[i - 1].pos);
            }
        }
    }

    // printf("max range : %d\n", max_range);

    groups[0] = 1;
    for (int i = 1; i < N; i++) {
        if (cows[i].pos - cows[i - 1].pos < max_range) {
            groups[i] = groups[i - 1];
        } else {
            groups[i] = groups[i - 1] + 1;
        }
    }

    // printf("\tgroups : ");
    // for (int i = 0; i < N; i++) printf("%d ", groups[i]); printf("\n");

    int last_infected_group = 0;
    int result = 0;

    for (int i = 0; i < N; i++) {
        if (cows[i].sick && last_infected_group != groups[i]) {
            result++;
            last_infected_group = groups[i];
        }
    }

    printf("%d\n", result);

    return 0;
}