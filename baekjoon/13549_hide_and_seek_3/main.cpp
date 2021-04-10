#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct state {
    int pos, cost;

    bool operator >(const state &o) const {
        return cost > o.cost;
    }
};

priority_queue<state, vector<state>, greater<state>> q;
int mindist[100005];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    memset(mindist, 0x3f, sizeof(mindist));

    mindist[N] = 0;
    q.push({ N, 0 });

    while (!q.empty()) {
        state cur = q.top();
        q.pop();

        {
            state next = { cur.pos + 1, cur.cost + 1 };
            if (next.pos >= 0 && next.pos <= 100000) {
                if (mindist[next.pos] > next.cost) {
                    mindist[next.pos] = next.cost;
                    q.push(next);
                }
            }
        }
        {
            state next = { cur.pos - 1, cur.cost + 1 };
            if (next.pos >= 0 && next.pos <= 100000) {
                if (mindist[next.pos] > next.cost) {
                    mindist[next.pos] = next.cost;
                    q.push(next);
                }
            }
        }
        {
            state next = { cur.pos * 2, cur.cost };
            if (next.pos >= 0 && next.pos <= 100000) {
                if (mindist[next.pos] > next.cost) {
                    mindist[next.pos] = next.cost;
                    q.push(next);
                }
            }
        }
    }

    printf("%d\n", mindist[K]);

    return 0;
}