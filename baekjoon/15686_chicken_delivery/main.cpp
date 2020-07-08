#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

struct pos {
    int r, c;

    int manhattan_distance(pos &o) {
        return abs(r - o.r) + abs(c - o.c);
    }
};

vector<pos> houses;
vector<pos> chickens;
int distances[102];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int type;
            scanf("%d", &type);

            if (type == 1) {
                houses.push_back({r, c});
            } else if (type == 2) {
                chickens.push_back({r, c});
            }
        }
    }

    int result = 0x3f3f3f3f;

    for (int i = 0; i < (1 << chickens.size()); i++) {
        memset(distances, 0x3f, sizeof(distances));

        int ci = 0;
        for (int c = 0; c < chickens.size(); c++) {
            if (((i >> c) & 1) == 0) continue;
            ci++;
            
            for (int h = 0; h < houses.size(); h++) {
                distances[h] = min(
                    distances[h],
                    houses[h].manhattan_distance(chickens[c]));
            }
        }

        if (ci > M || ci == 0) continue;

        int distance_sum = 0;
        for (int h = 0; h < houses.size(); h++) {
            distance_sum += distances[h];
        }

        result = min(result, distance_sum);
    }

    printf("%d\n", result);

    return 0;
}