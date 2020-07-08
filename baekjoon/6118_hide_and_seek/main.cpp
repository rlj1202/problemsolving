#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[20004];
int queue[20004];
int l, r;
int distances[20004];

void bfs() {
    l = r = 0;
    queue[r++] = 1;

    while (r - l) {
        int cur = queue[l++];
        for (int next : adj[cur]) {
            if (next == 1 || distances[next]) continue;

            distances[next] = distances[cur] + 1;
            queue[r++] = next;
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(distances, 0, sizeof(distances));
    bfs();

    int result;
    int max = 0;
    int count = 0;
    for (int n = 1; n <= N; n++) {
        if (max < distances[n]) {
            max = distances[n];
            result = n;
            count = 1;
        } else if (max == distances[n]) {
            count++;
        }
    }

    printf("%d %d %d\n", result, max, count);
    
    return 0;
}