#include <bits/stdc++.h>

using namespace std;

const int dr[] = { 0, -1, 0, 1 };
const int dc[] = { -1, 0, 1, 0 };

char grid[12][12];

struct point {
    int r, c;

    bool operator==(const point &o) const {
        return r == o.r && c == o.c;
    }

    bool operator!=(const point &o) const {
        return r != o.r || c != o.c;
    }
};

struct state {
    point red;
    point blue;
    int moves;
    bool red_dropped;
    bool blue_dropped;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        cin >> grid[r];
    }

    point red, blue, hole;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char cell = grid[r][c];

            if (cell == 'R') {
                red = { r, c };
                grid[r][c] = '.';
            } else if (cell == 'B') {
                blue = { r, c };
                grid[r][c] = '.';
            } else if (cell == 'O') {
                hole = { r, c };
                grid[r][c] = '.';
            }
        }
    }

    deque<state> q;
    q.push_back({ red, blue, 0, false, false });

    int answer = -1;

    while (true) {
        state prev_state = q.front();
        q.pop_front();

        if (prev_state.moves > 10) {
            answer = -1;
            break;
        }

        if (prev_state.red_dropped && !prev_state.blue_dropped) {
            answer = prev_state.moves;
            break;
        }

        if (prev_state.blue_dropped) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            state cur_state = prev_state;
            point &cur_red = cur_state.red;
            point &cur_blue = cur_state.blue;
            cur_state.moves++;

            // Roll both balls until there are no changes at all
            while (true) {
                bool changed = false;

                point next_red = { cur_red.r + dr[i], cur_red.c + dc[i] };
                point next_blue = { cur_blue.r + dr[i], cur_blue.c + dc[i] };

                if (grid[next_red.r][next_red.c] == '.' && (cur_state.blue_dropped || (!cur_state.blue_dropped && next_red != cur_blue))) {
                    cur_red = next_red;
                    changed = true;

                    if (cur_red == hole) {
                        cur_state.red_dropped = true;
                    }
                }

                if (grid[next_blue.r][next_blue.c] == '.' && (cur_state.red_dropped || (!cur_state.red_dropped && next_blue != cur_red))) {
                    cur_blue = next_blue;
                    changed = true;

                    if (cur_blue == hole) {
                        cur_state.blue_dropped = true;
                    }
                }

                if (!changed) {
                    break;
                }
            }

            q.push_back(cur_state);
        }
    }

    cout << answer << '\n';

    return 0;
}
