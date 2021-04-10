#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

struct point {
    int r, s;
};

const int MAX_N = 102;
const int MAX_TOWER = MAX_N * MAX_N;
const int MAX_VARS = MAX_TOWER * 4;

int R, S;

char grid[MAX_N][MAX_N];

vector<int> adj[MAX_VARS];

int visited[MAX_VARS];
int visited_cur;
int group[MAX_VARS];
int group_cur;

stack<int> s;
stack<int> dag;

vector<point> towers;
int tower_map[MAX_N][MAX_N];

bool result[MAX_VARS];

inline int H(int tower) {
    return (tower << 2);
}
inline int V(int tower) {
    return (tower << 2) | 2;
}

point find(point start, point dir, char c, char stop) {
    point cur = start;

    bool found = false;

    while (!found) {
        cur.r += dir.r;
        cur.s += dir.s;

        if (cur.r < 1 || cur.r > R) break;
        if (cur.s < 1 || cur.s > S) break;

        if (grid[cur.r][cur.s] == c) {
            found = true;
        } else if (grid[cur.r][cur.s] == stop) {
            break;
        }
    }

    if (!found) return {-1, -1};

    return cur;
}

int dfs(int node) {
    visited[node] = ++visited_cur;
    int lower = visited[node];

    s.push(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            lower = min(lower, dfs(next));
        } else if (!group[next]) {
            lower = min(lower, visited[next]);
        }
    }

    if (lower == visited[node]) {
        group_cur++;

        while (!s.empty()) {
            int popped = s.top();
            s.pop();

            dag.push(popped);
            group[popped] = group_cur;

            if (popped == node) break;
        }
    }

    return lower;
}

int main() {
    // Take input
    scanf("%d %d", &R, &S);

    for (int r = 1; r <= R; r++) {
        for (int s = 1; s <= S; s++) {
            scanf(" %c", &grid[r][s]);
        }
    }

    // Mark points of towers
    for (int r = 1; r <= R; r++) {
        for (int s = 1; s <= S; s++) {
            if (grid[r][s] == 'T') { // tower
                towers.push_back({r, s});
                tower_map[r][s] = towers.size();
            }
        }
    }

    // Make directed graph using boolean expressions
    for (int r = 1; r <= R; r++) {
        for (int s = 1; s <= S; s++) {
            if (grid[r][s] == '.') continue;
            if (grid[r][s] == '#') continue;

            point up = find({r, s}, {1, 0}, 'T', '#');
            point down = find({r, s}, {-1, 0}, 'T', '#');
            point right = find({r, s}, {0, 1}, 'T', '#');
            point left = find({r, s}, {0, -1}, 'T', '#');

            if (grid[r][s] == 'T') { // tower
                int tower = tower_map[r][s];
                int h = H(tower);
                int v = V(tower);

                if (right.r != -1) { // h must be false (left)
                    adj[h].push_back(h ^ 1);
                }

                if (left.r != -1) { // h must be true (right)
                    adj[h ^ 1].push_back(h);
                }

                if (up.r != -1) { // v must be false (down)
                    adj[v].push_back(v ^ 1);
                }

                if (down.r != -1) { // v must be true (up)
                    adj[v ^ 1].push_back(v);
                }
            } else if (grid[r][s] == 'n') { // clone
                int a = -1;
                int b = -1;

                if (up.r != -1 && down.r == -1) {
                    int tower = tower_map[up.r][up.s];
                    tower = V(tower) ^ 1;

                    if (a == -1) a = tower;
                    else b = tower;
                }
                if (down.r != -1 && up.r == -1) {
                    int tower = tower_map[down.r][down.s];
                    tower = V(tower);

                    if (a == -1) a = tower;
                    else b = tower;
                }
                if (left.r != -1 && right.r == -1) {
                    int tower = tower_map[left.r][left.s];
                    tower = H(tower);
                    if (a == -1) a = tower;
                    else b = tower;
                }
                if (right.r != -1 && left.r == -1) {
                    int tower = tower_map[right.r][right.s];
                    tower = H(tower) ^ 1;
                    if (a == -1) a = tower;
                    else b = tower;
                }

                if (b == -1) {
                    adj[a ^ 1].push_back(a);
                } else {
                    adj[a ^ 1].push_back(b);
                    adj[b ^ 1].push_back(a);
                }
            }
        }
    }

    // Do SCC algorithm
    for (int i = 1; i < MAX_VARS; i++) {
        if (!visited[i]) dfs(i);
    }

    // (!) a test case is always given the way the answer exists.
    //     validness check is unnecessary.
    
    // Make answer
    while (!dag.empty()) {
        int popped = dag.top();
        dag.pop();

        if (result[popped] == false) {
            result[popped ^ 1] = true;
        }
    }

    // Print answer
    for (int r = 1; r <= R; r++) {
        for (int s = 1; s <= S; s++) {
            if (grid[r][s] == 'T') {
                int tower = tower_map[r][s];

                int h = result[H(tower)];
                int v = result[V(tower)];

                printf("%c", "1423"[(h << 1) + !v]);
            } else {
                printf("%c", grid[r][s]);
            }
        }
        printf("\n");
    }

    return 0;
}