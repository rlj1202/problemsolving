#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int parent;
    long long delta;
};

node nodes[100005];

int find(int a) {
    if (nodes[a].parent == 0) return a;

    int group = find(nodes[a].parent);
    nodes[a].delta += nodes[nodes[a].parent].delta;
    return nodes[a].parent = group;
}

void merge(int a, int b, long long delta) {
    int A = find(a);
    int B = find(b);

    if (A == B) return;

    nodes[A].parent = B;
    nodes[A].delta = nodes[b].delta - nodes[a].delta + delta;

    return;
}

int main() {
    while (true) {
        int N, M;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        memset(nodes, 0, sizeof(nodes));

        for (int m = 0; m < M; m++) {
            char type;
            scanf(" %c", &type);

            if (type == '!') {
                int a, b, w;
                scanf("%d %d %d", &a, &b, &w);
                
                merge(a, b, w);
            } else if (type == '?') {
                int a, b;
                scanf("%d %d", &a, &b);

                if (find(a) == find(b)) {
                    printf("%lld\n", nodes[a].delta - nodes[b].delta);
                } else {
                    printf("UNKNOWN\n");
                }
            }
        }
    }

    return 0;
}