#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int dr[] = { 0, 1, 0, -1 };
const int dc[] = { 1, 0, -1, 0 };

struct state {
    int depth;
    pii coins[2];
};

char grid[22][22];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        cin >> grid[n];
    }

    state init;
    init.depth = 0;

    int ci = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char cur = grid[r][c];

            if (cur == 'o') {
                init.coins[ci++] = { r, c };
            }
        }
    }

    queue<state> q;
    q.push(init);

    int answer = 0;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        
        // 등호를 넣은 이유는 이미 끝나지 않았으므로 1번의 움직임이 더 필요하다는 것을 의미
        if (cur.depth >= 10) {
            answer = -1;
            break;
        }

        bool finished = false;

        for (int dir = 0; dir < 4; dir++) {
            state next = cur;
            next.depth++;

            int droppped = 0;

            for (int ci = 0; ci < 2; ci++) {
                pii moved = next.coins[ci];
                moved.first += dr[dir];
                moved.second += dc[dir];

                if (moved.first < 0 || moved.first >= N ||
                    moved.second < 0 || moved.second >= M) {
                    droppped++;
                    continue;
                }

                if (grid[moved.first][moved.second] == '#') {
                    continue;
                }

                next.coins[ci] = moved;
            }

            if (droppped == 1) {
                answer = next.depth;
                finished = true;
                break;
            } else if (droppped == 2) {
                continue;
            }

            q.push(next);
        }

        if (finished) {
            break;
        }
    }
    
    cout << answer << '\n';

    return 0;
}
