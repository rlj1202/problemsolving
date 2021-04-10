#include <cstdio>
#include <algorithm>

using namespace std;

struct point { int r, c; };

point points[102];

int main() {
    // 1e6 1e6 100 1e6
    int N, M, T, K;
    scanf("%d %d %d %d", &N, &M, &T, &K);
    for (int t = 0; t < T; t++) {
        int a, b;
        scanf("%d %d", &a, &b);
        points[t] = {a, b};
    }

    int answer = 0;
    point answer_point;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            int left = min(points[i].r, points[j].r);
            int down = min(points[i].c, points[j].c);

            if (left + K > N) left = N - K;
            if (down + K > M) down = M - K;

            int right = left + K;
            int up = down + K;

            int count = 0;

            for (int p = 0; p < T; p++) {
                point cur = points[p];

                if (left <= cur.r && cur.r <= right &&
                    down <= cur.c && cur.c <= up) {
                    count++;
                }
            }

            if (answer < count) {
                answer = count;
                answer_point = { left, up };
            }
        }
    }
    
    printf("%d %d\n", answer_point.r, answer_point.c); // left upper corner
    printf("%d\n", answer); // number of jewelries

    return 0;
}