#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100005];
bool gomgom[100005];

queue<int> q;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
    }
    int S;
    scanf("%d", &S);
    for (int s = 0; s < S; s++) {
        int value;
        scanf("%d", &value);
        gomgom[value] = true;
    }

    bool result = false;

    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (gomgom[cur]) {
            continue;
        }

        if (adj[cur].empty()) {
            result = true;
            break;
        }

        for (int next : adj[cur]) {
            q.push(next);
        }
    }

    printf("%s\n", result ? "yes" : "Yes");

    return 0;
}
