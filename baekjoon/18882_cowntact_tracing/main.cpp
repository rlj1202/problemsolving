#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

struct contact {
    int time, x, y;
};

char arr[102];
contact contacts[252];

bool infected[102];
int spreads[102];

int main() {
    int N, T;
    scanf("%d %d %s", &N, &T, arr + 1);

    for (int t = 0; t < T; t++) {
        int time, x, y;
        scanf("%d %d %d", &time, &x, &y);
        contacts[t] = {time, x, y};
    }
    sort(contacts, contacts + T, [&](contact &a, contact &b) -> bool {
        return a.time < b.time;
    });

    int zp_candidates = 0;
    int min_k = 0;
    int max_k = 0;

    for (int z = 1; z <= N; z++) {
        if (arr[z] == '0') continue;

        memset(infected, 0, sizeof(infected));
        memset(spreads, 0, sizeof(spreads));

        infected[z] = true;

        int possible_k = INF;
        bool valid = true;

        for (int t = 0; t < T; t++) {
            contact c = contacts[t];

            if (infected[c.x] && !infected[c.y]) {
                if (arr[c.y] == '0' || spreads[c.x] >= possible_k) {
                    if (possible_k == INF) {
                        possible_k = spreads[c.x];
                    } else if (spreads[c.x] != possible_k) {
                        valid = false;
                        break;
                    }
                } else {
                    infected[c.y] = true;
                    spreads[c.x]++;
                }
            } else if (infected[c.y] && !infected[c.x]) {
                if (arr[c.x] == '0' || spreads[c.y] >= possible_k) {
                    if (possible_k == INF) {
                        possible_k = spreads[c.y];
                    } else if (spreads[c.y] != possible_k) {
                        valid = false;
                        break;
                    }
                } else {
                    infected[c.x] = true;
                    spreads[c.y]++;
                }
            } else if (infected[c.x] && infected[c.y]) {
                if (spreads[c.x] < possible_k) {
                    spreads[c.x]++;
                }
                if (spreads[c.y] < possible_k) {
                    spreads[c.y]++;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (arr[i] - '0' != infected[i]) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        zp_candidates++;

        for (int i = 1; i <= N; i++) {
            min_k = max(min_k, spreads[i]);
        }
        max_k = max(max_k, possible_k);

        // printf("\tzero patient : %d\n", z);
        // printf("\tpossible K   : %d\n", possible_k);
        // printf("\tinfections : ");
        // for (int i = 1; i <= N; i++) printf("%d ", infected[i]); printf("\n");
        // printf("\tspreads    : ");
        // for (int i = 1; i <= N; i++) printf("%d ", spreads[i]); printf("\n");
        // printf("\n");
    }

    // number of possible cows who could been patient zero
    // smallest possible value of K (could be zero)
    // largest possible value of K (could be 'Infinity')
    printf("%d %d", zp_candidates, min_k);
    if (max_k == INF) {
        printf(" Infinity");
    } else {
        printf(" %d", max_k);
    }
    printf("\n");

    return 0;
}