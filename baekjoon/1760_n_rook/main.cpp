#include <cstdio>
#include <vector>

using namespace std;

const int HOLE = 1;
const int WALL = 2;

int grid[102][102];
int rowi[102][102];
int coli[102][102];
int rowi_cur;
int coli_cur;

vector<int> adj[20004];

int visited[20004];
int visited_flag;

int parent[20004];

bool dfs(int start) {
    if (visited[start] == visited_flag) return false;
    visited[start] = visited_flag;

    for (int next : adj[start]) {
        if (!parent[next] || dfs(parent[next])) {
            parent[next] = start;
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            scanf("%d", &grid[r][c]);
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] == WALL || rowi[r][c]) continue;

            rowi_cur++;
            int curr = r;
            while (curr <= N && grid[curr][c] != WALL) {
                rowi[curr][c] = rowi_cur;
                curr++;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] == WALL || coli[r][c]) continue;

            coli_cur++;
            int curc = c;
            while (curc <= M && grid[r][curc] != WALL) {
                coli[r][curc] = coli_cur;
                curc++;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (!rowi[r][c] || !coli[r][c]) continue;
            if (grid[r][c] == HOLE) continue;

            int a = rowi[r][c];
            int b = coli[r][c] + 10000;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    for (int i = 1; i <= 10000; i++) {
        visited_flag++;
        dfs(i);
    }

    int result = 0;

    for (int i = 1; i <= 10000; i++) {
        if (parent[i + 10000]) result++;
    }

    printf("%d\n", result);

    return 0;
}