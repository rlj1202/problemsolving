#include <cstdio>
#include <vector>

using namespace std;

int N, M;

bool obstacle[102][102];

int rdig[102][102];
int rdig_index;
int ldig[102][102];
int ldig_index;

vector<int> adj[10004];

int parent[10004];

int visited[10004];
int visited_flag;

bool dfs(int cur) {
    if (visited[cur] == visited_flag) return false;
    visited[cur] = visited_flag;

    for (int next : adj[cur]) {
        if (!parent[next] || dfs(parent[next])) {
            parent[next] = cur;
            return true;
        }
    }
    
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int r, c;
        scanf("%d %d", &r, &c);

        obstacle[r][c] = true;
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (obstacle[r][c]) continue;
            if (rdig[r][c]) continue;

            int cur_r = r;
            int cur_c = c;

            rdig_index++;

            while (true) {
                if (cur_r < 1 || cur_r > N) break;
                if (cur_c < 1 || cur_c > N) break;
                if (obstacle[cur_r][cur_c]) break;

                rdig[cur_r][cur_c] = rdig_index;

                cur_r++;
                cur_c++;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (obstacle[r][c]) continue;
            if (ldig[r][c]) continue;

            int cur_r = r;
            int cur_c = c;

            ldig_index++;

            while (true) {
                if (cur_r < 1 || cur_r > N) break;
                if (cur_c < 1 || cur_c > N) break;
                if (obstacle[cur_r][cur_c]) break;

                ldig[cur_r][cur_c] = ldig_index;

                cur_r++;
                cur_c--;
            }
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (!rdig[r][c] || !ldig[r][c]) continue;
            adj[rdig[r][c]].push_back(ldig[r][c]);
        }
    }

    for (int i = 1; i <= rdig_index; i++) {
        visited_flag++;
        dfs(i);
    }

    int result = 0;

    for (int i = 1; i <= rdig_index; i++) {
        if (parent[i]) result++;
    }

    printf("%d\n", result);

    return 0;
}