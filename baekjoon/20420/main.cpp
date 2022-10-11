#include <bits/stdc++.h>

using namespace std;

struct point {
    int r, c;
    int free_l, free_r;
};

int R, C, K;

const int dr[] = { 0, -1, 0, 1 };
const int dc[] = { 1, 0, -1, 0 };

int grid[52][52];
bool visited[52][52][152][152];

bool safe(const point &p) {
    if (p.r < 0 || p.r >= R) return false;
    if (p.c < 0 || p.c >= C) return false;
    return true;
}

bool &get_visited(const point &p) {
    return visited[p.r][p.c][p.free_l][p.free_r];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C >> K;

    for (int r = 0; r < R; r++) {
        char temp[52];
        cin >> temp;

        for (int c = 0; c < C; c++) {
            char dir = temp[c];
            if (dir == 'R') grid[r][c] = 0;
            if (dir == 'U') grid[r][c] = 1;
            if (dir == 'L') grid[r][c] = 2;
            if (dir == 'D') grid[r][c] = 3;
        }
    }

    deque<point> q;
    q.push_front({ 0, 0, K, K });
    get_visited({ 0, 0, K, K }) = true;

    while (!q.empty()) {
        point cur = q.front();
        q.pop_front();

        int dir = grid[cur.r][cur.c];

        point next = cur;
        next.r += dr[dir];
        next.c += dc[dir];
        if (safe(next) && !get_visited(next)) {
            q.push_front(next);
            get_visited(next) = true;
        }

        int left_turn = (dir + 1) % 4;
        int right_turn = (dir - 1 + 4) % 4;
        int back_turn = (dir + 2) % 4;
        point left = cur;
        point right = cur;
        point back = cur;
        left.r += dr[left_turn];
        left.c += dc[left_turn];
        right.r += dr[right_turn];
        right.c += dc[right_turn];
        back.r += dr[back_turn];
        back.c += dc[back_turn];

        if (safe(left)) {
            if (left.free_l) {
                point p = left;
                p.free_l--;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
            if (left.free_r >= 3) {
                point p = left;
                p.free_r -= 3;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
        }

        if (safe(right)) {
            if (right.free_r) {
                point p = right;
                p.free_r--;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
            if (right.free_l >= 3) {
                point p = right;
                p.free_l -= 3;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
        }

        if (safe(back)) {
            if (back.free_l >= 2) {
                point p = back;
                p.free_l -= 2;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
            if (back.free_r >= 2) {
                point p = back;
                p.free_r -= 2;

                if (!get_visited(p)) {
                    q.push_back(p);
                    get_visited(p) = true;
                }
            }
        }
    }

    bool answer = false;

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            answer |= get_visited({ R - 1, C - 1, i, j });
        }
    }

    cout << (answer ? "Yes" : "No") << '\n';

    return 0;
}
