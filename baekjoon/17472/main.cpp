#include <bits/stdc++.h>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct point {
    int r, c;
};

struct edge {
    int u, v;
    int weight;

    bool operator<(const edge &o) const {
        return weight < o.weight;
    }
};

int N, M;

int grid[12][12];
int group[12][12];
int group_cur;

int parent[102];

vector<edge> edges;

int find(int n) {
    if (!parent[n]) return n;
    return parent[n] = find(parent[n]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;

    parent[A] = B;

    return true;
}

void bfs(point p) {
    queue<point> q;
    q.push(p);

    group[p.r][p.c] = ++group_cur;

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            point next = { cur.r + dr[i], cur.c + dc[i] };

            if (next.r < 0 || next.r >= N) continue;
            if (next.c < 0 || next.c >= M) continue;
            if (grid[next.r][next.c] == 0) continue;
            if (group[next.r][next.c]) continue;

            group[next.r][next.c] = group_cur;

            q.push(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == 0) continue;
            if (group[r][c]) continue;

            bfs({ r, c });
        }
    }

    for (int r = 0; r < N; r++) {
        int prev_island = -1;
        int length = 0;

        for (int c = 0; c < M; c++) {
            if (grid[r][c] == 1) {
                int cur_island = group[r][c];

                if (length > 1 && prev_island != -1 && prev_island != cur_island) {
                    edges.push_back({ prev_island, cur_island, length });
                }

                prev_island = cur_island;
                length = 0;
            } else {
                length++;
            }
        }
    }
    for (int c = 0; c < M; c++) {
        int prev_island = -1;
        int length = 0;

        for (int r = 0; r < N; r++) {
            if (grid[r][c] == 1) {
                int cur_island = group[r][c];

                if (length > 1 && prev_island != -1 && prev_island != cur_island) {
                    edges.push_back({ prev_island, cur_island, length });
                }

                prev_island = cur_island;
                length = 0;
            } else {
                length++;
            }
        }
    }

    sort(edges.begin(), edges.end());

    int answer = 0;

    int cnt = 0;

    for (edge &e : edges) {
        if (merge(e.u, e.v)) {
            answer += e.weight;
            cnt++;
        }
    }

    if (cnt + 1 != group_cur) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}
