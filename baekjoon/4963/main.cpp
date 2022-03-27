#include <cstdio>
#include <cstring>

using namespace std;

const int dh[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dw[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int W, H;

int map[52][52];
bool visited[52][52];

void dfs(int h, int w) {
    for (int i = 0; i < 8; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        
        if (nh < 0 || H <= nh) continue;
        if (nw < 0 || W <= nw) continue;
        if (visited[nh][nw]) continue;
        if (map[nh][nw] == 0) continue;

        visited[nh][nw] = true;
        dfs(nh, nw);
    }
}

int main() {
    while (true) {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) break;

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                scanf("%d", &map[h][w]);
            }
        }

        memset(visited, 0, sizeof(visited));

        int result = 0;

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (visited[h][w]) continue;
                if (map[h][w] == 0) continue;

                visited[h][w] = true;
                result++;
                dfs(h, w);
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
