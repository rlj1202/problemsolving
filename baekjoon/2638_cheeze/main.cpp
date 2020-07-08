#include <cstdio>
#include <cstring>

using namespace std;

struct pos {
    int r, c;
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int mapA[10004];
int mapB[10004];

int *curMap;
int *nxtMap;

bool visited[10004];
pos queue[10004];
int l, r;

int main() {
    curMap = mapA;
    nxtMap = mapB;

    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            scanf("%d", curMap + (m + n * M));
        }
    }

    int result = 0;
    while (true) {
        bool empty = true;

        // Spread airs using BFS
        memset(visited, 0, sizeof(visited));
        l = r = 0;
        curMap[0] = -1;
        queue[r++] = {0, 0};
        visited[0] = true;
        while (l < r) {
            pos cur = queue[l++];

            for (int i = 0; i < 4; i++) {
                pos next = {cur.r + dr[i], cur.c + dc[i]};
                if (next.r < 0 || next.c < 0 ||
                        next.r >= N || next.c >= M) continue;
                if (visited[next.c + next.r * M]) continue;
                if (curMap[next.c + next.r * M] == 1) continue;

                curMap[next.c + next.r * M] = -1;
                queue[r++] = next;
                visited[next.c + next.r * M] = true;
            }
        }

        // for (int r = 0; r < N; r++) {
        //     for (int c = 0; c < M; c++) {
        //         printf("%c ", ".-#"[curMap[c + r * M] + 1]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        // Process cheeze...
        for (int r = 1; r < N - 1; r++) {
            for (int c = 1; c < M - 1; c++) {
                if (curMap[c + r * M] == 1) empty = false;

                int surrounds = 0;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    surrounds += curMap[nc + nr * M] != -1;
                }
                if (curMap[c + r * M] == 1)
                    nxtMap[c + r * M] = surrounds >= 3;
                else
                    nxtMap[c + r * M] = 0;
            }
        }

        if (empty) break;

        int *tmpMap = curMap;
        curMap = nxtMap;
        nxtMap = tmpMap;

        result++;
    }

    printf("%d\n", result);

    return 0;
}