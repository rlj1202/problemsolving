#include <bits/stdc++.h>

using namespace std;

struct state {
    int scv[3];
    int depth;
};

state init;
bool visited[61][61][61];

bool &mark(state &s) {
    return visited[s.scv[0]][s.scv[1]][s.scv[2]];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> init.scv[n];
    }

    queue<state> q;
    q.push(init);
    mark(init) = true;

    int answer = 0;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.scv[0] == 0 && cur.scv[1] == 0 && cur.scv[2] == 0) {
            answer = cur.depth;
            break;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;

                for (int k = 0; k < 3; k++) {
                    if (i == k) continue;
                    if (j == k) continue;

                    state next = cur;
                    next.scv[i] = max(next.scv[i] - 9, 0);
                    next.scv[j] = max(next.scv[j] - 3, 0);
                    next.scv[k] = max(next.scv[k] - 1, 0);
                    next.depth++;

                    if (mark(next)) continue;

                    q.push(next);
                    mark(next) = true;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
