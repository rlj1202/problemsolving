#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int dr[] = {1, 0, -1, 0}; // down, right, up, left
const int dc[] = {0, 1, 0, -1};

const int DOWN = 0;
const int RIGHT = 1;
const int UP = 2;
const int LEFT = 3;

const int APPLE = 1 << 0;
const int SNAKE = 1 << 1;

int grid[102][102];

deque<pii> snake;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int k = 0; k < K; k++) {
        int r, c;
        cin >> r >> c;

        grid[r][c] ^= APPLE;
    }

    snake.push_back({ 1, 1 });
    grid[1][1] ^= SNAKE;

    int dir = RIGHT;

    int L;
    cin >> L;

    deque<pair<int, char>> inst;
    for (int l = 0; l < L; l++) {
        int X;
        char C;
        cin >> X >> C;

        inst.push_back({ X, C });
    }

    int time = 0;
    bool game_over = false;

    while (!game_over) {
        time++;

        pii head = snake.back();
        head.first += dr[dir];
        head.second += dc[dir];

        if (head.first < 1 || head.first > N) {
            game_over = true;
            break;
        }
        if (head.second < 1 || head.second > N) {
            game_over = true;
            break;
        }
        if (grid[head.first][head.second] & SNAKE) {
            game_over = true;
            break;
        }

        snake.push_back(head);
        grid[head.first][head.second] |= SNAKE;

        if (!(grid[head.first][head.second] & APPLE)) {
            pii tail = snake.front();
            snake.pop_front();

            grid[tail.first][tail.second] ^= SNAKE;
        } else {
            grid[head.first][head.second] ^= APPLE;
        }

        if (time == inst.front().first) {
            if (inst.front().second == 'L') {
                dir = (dir + 1) % 4;
            } else if (inst.front().second == 'D') {
                dir = (dir + 3) % 4;
            }

            inst.pop_front();
        }
    }

    cout << time << '\n';

    return 0;
}
