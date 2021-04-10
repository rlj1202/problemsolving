#include <cstdio>
#include <vector>

using namespace std;

const char HOLE = '*';

char grid[52][52];
int rowi[52][52];
int coli[52][52];
int rowi_cur;
int coli_cur;

vector<int> adj[52*52*2];

int visited[52*52*2];
int visited_cur;

int parent[52*52*2];

bool dfs(int cur) {
    if (visited[cur] == visited_cur) return false;
    visited[cur] = visited_cur;

    for (int next : adj[cur]) {
        if (!parent[next] || dfs(parent[next])) {
            parent[next] = cur;
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int r = 1; r <= N; r++) {
        scanf("%s", grid[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] != HOLE) continue;

            rowi_cur++;
            for (int curr = r;
                curr <= N && grid[curr][c] == HOLE && rowi[curr][c] == 0;
                curr++) {
                rowi[curr][c] = rowi_cur;
            }

            coli_cur++;
            for (int curc = c;
                curc <= M && grid[r][curc] == HOLE && !coli[r][curc];
                curc++) {
                coli[r][curc] = coli_cur;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (!rowi[r][c] || !coli[r][c]) continue;

            int a = rowi[r][c];
            int b = coli[r][c] + N*M;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    for (int i = 1; i <= N*M; i++) {
        visited_cur++;
        dfs(i);
    }

    int result = 0;

    for (int i = 1; i <= N*M; i++) {
        if (parent[i + N*M]) result++;
    }

    printf("%d\n", result);
    
    return 0;
}