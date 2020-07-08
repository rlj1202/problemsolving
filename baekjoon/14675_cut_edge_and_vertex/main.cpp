#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const char ANSWERS[2][4] = {"no", "yes"};

vector<int> adj[100005];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N - 1; n++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type, k;
        scanf("%d %d", &type, &k);

        if (type == 1) {
            printf("%s\n", ANSWERS[adj[k].size() >= 2]);
        } else if (type == 2) {
            printf("%s\n", ANSWERS[1]);
        }
    }

    return 0;
}