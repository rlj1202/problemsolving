#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct pos {
    int r, c;
};

const int dr[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};

int N;
pos postoffice;
vector<pos> houses;
int heightMap[52][52];
vector<int> heights;

queue<pos> q;
bool visited[52][52];

bool bfs(int lower, int upper) {
    if (heightMap[postoffice.r][postoffice.c] < lower) return false;
    if (upper < heightMap[postoffice.r][postoffice.c]) return false;

    memset(visited, 0, sizeof(visited));

    q.push(postoffice);
    visited[postoffice.r][postoffice.c] = true;

    while (!q.empty()) {
        pos cur = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            pos next = {cur.r + dr[i], cur.c + dc[i]};
            if (next.r < 1 || N < next.r) continue;
            if (next.c < 1 || N < next.c) continue;
            if (visited[next.r][next.c]) continue;
            if (heightMap[next.r][next.c] < lower) continue;
            if (upper < heightMap[next.r][next.c]) continue;

            q.push(next);
            visited[next.r][next.c] = true;
        }
    }

    bool result = true;

    for (pos house : houses) {
        result &= visited[house.r][house.c];
    }

    return result;
}

int main() {
    scanf("%d", &N);
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            char type;
            scanf(" %c", &type);

            if (type == 'K') {
                houses.push_back({r, c});
            } else if (type == 'P') {
                postoffice = {r, c};
            }
        }
    }
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            scanf("%d", &heightMap[r][c]);
            heights.push_back(heightMap[r][c]);
        }
    }
    sort(heights.begin(), heights.end());
    heights.resize(unique(heights.begin(), heights.end()) - heights.begin());

    int result = 0x3f3f3f3f;

    for (int i = 0; i < heights.size(); i++) {
        int lower = heights[i];

        int l = i;
        int r = heights.size() - 1;
        int mid = (l + r) / 2;
        
        while (l < r) {
            int upper = heights[mid];

            if (bfs(lower, upper)) {
                r = mid;
            } else {
                l = mid + 1;
            }

            mid = (l + r) / 2;
        }

        int upper = heights[mid];
        if (bfs(lower, upper))
            result = min(result, upper - lower);
    }

    printf("%d\n", result);

    return 0;
}