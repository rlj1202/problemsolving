#include <bits/stdc++.h>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct point {
    int r, c;
    bool broke;
};

char grid[1003][1003];
int visited[1003][1003][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    queue<point> q;
    q.push({ 1, 1, false });
    visited[1][1][false] = 1;

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            point next = { cur.r + dr[i], cur.c + dc[i], cur.broke };

            if (next.r < 1 || next.r > N) continue;
            if (next.c < 1 || next.c > M) continue;

            if (grid[next.r][next.c] == '1') {
                if (next.broke) continue;

                next.broke = true;
            }

            if (visited[next.r][next.c][next.broke]) continue;

            q.push(next);
            visited[next.r][next.c][next.broke] =
                visited[cur.r][cur.c][cur.broke] + 1;
        }
    }

    if (!visited[N][M][false] && !visited[N][M][true]) {
        cout << -1 << '\n';
        return 0;
    }

    int result = 0;
    if (!visited[N][M][false]) result = visited[N][M][true];
    else if (!visited[N][M][true]) result = visited[N][M][false];
    else result = min(visited[N][M][false], visited[N][M][true]);

    cout << result << '\n';

    return 0;
}
