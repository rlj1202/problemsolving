#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int id, pos;

    bool operator< (const node &o) const {
        return pos < o.pos;
    }
};

int l, r;
node nodes[200005];
int state[100005];

int push_node() {
    node cur = nodes[r++];
    return ++state[cur.id];
}

int pop_node() {
    node cur = nodes[l++];
    return --state[cur.id];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int h, o;
        scanf("%d %d", &h, &o);
        nodes[n * 2] = {n, h};
        nodes[n * 2 + 1] = {n, o};
    }
    int D;
    scanf("%d", &D);

    sort(nodes, nodes + N*2);

    int result = 0;

    int cur = 0;
    while (r < N*2) {
        if (push_node() == 2) cur++;

        while (l < r && nodes[r - 1].pos - nodes[l].pos > D) {
            if (pop_node() == 1) cur--;
        }

        result = max(result, cur);
    }

    printf("%d\n", result);
    
    return 0;
}