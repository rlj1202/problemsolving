#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct cell {
    int r, c;
    int height;

    bool operator>(const cell &o) const {
        if (height == o.height) {
            if (c == o.c)
                return r > o.r;
            return c > o.c;
        }
        return height > o.height;
    }
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int M, N;

priority_queue<cell, vector<cell>, greater<cell>> pq;

int heights[302][302];

bool visited[302][302];
cell q[90004];
int left, right;

int fill(int r, int c, int height) {
    left = right = 0;
    memset(visited, 0, sizeof(visited));

    q[right++] = {r, c};
    visited[r][c] = true;

    int minWallHeight = std::numeric_limits<int>::max();

    while (right - left) {
        cell cur = q[left++];

        for (int i = 0; i < 4; i++) {
            cell next = {cur.r + dr[i], cur.c + dc[i]};
            if (visited[next.r][next.c])
                continue;

            if (height != heights[next.r][next.c]) {
                minWallHeight = min(minWallHeight, heights[next.r][next.c]);
            } else {
                if (next.r < 1 || next.c < 1 || next.r >= N - 1 ||
                    next.c >= M - 1) {
                    return 0;
                }

                q[right++] = next;
                visited[next.r][next.c] = true;
            }
        }
    }

    if (minWallHeight <= height) {
        return 0;
    } else {
        for (int i = 0; i < right; i++) {
            cell c = q[i];
            heights[c.r][c.c] = minWallHeight;
        }

        return (minWallHeight - height) * right;
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int height;
            scanf("%d", &height);
            heights[r][c] = height;

            if (r >= 1 && c >= 1 && r < N - 1 && c < M - 1)
                pq.push({r, c, height});
        }
    }

    int result = 0;

    while (!pq.empty()) {
        cell cur = pq.top();
        pq.pop();
        if (heights[cur.r][cur.c] != cur.height)
            continue;

        int filled = fill(cur.r, cur.c, cur.height);
        result += filled;
    }

    printf("%d\n", result);

    return 0;
}