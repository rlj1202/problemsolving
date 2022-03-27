#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int treeSize[100005];
int maxSubtree[100005];

int dfs(int N, int node, int parent) {
    int curSize = 1;
    int curMaxSubtree = 0;

    for (int next : adj[node]) {
        if (next == parent) continue;

        int subtreeSize = dfs(N, next, node);
        curSize += subtreeSize;
        curMaxSubtree = max(curMaxSubtree, subtreeSize);
    }

    curMaxSubtree = max(curMaxSubtree, N - curSize);

    treeSize[node] = curSize;
    maxSubtree[node] = curMaxSubtree;

    return curSize;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            adj[n].clear();
        }
        memset(treeSize, 0, sizeof(treeSize));
        memset(maxSubtree, 0, sizeof(maxSubtree));
        for (int n = 0; n < N - 1; n++) {
            int x, y;
            scanf("%d %d", &x, &y);

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(N, 1, 0);

        int minMaxSubtree = maxSubtree[1];
        int nodeCount = 0;
        for (int n = 1; n <= N; n++) {
            if (minMaxSubtree > maxSubtree[n]) {
                minMaxSubtree = maxSubtree[n];
                nodeCount = 1;
            } else if (minMaxSubtree == maxSubtree[n]) {
                nodeCount++;
            }
        }

        if (nodeCount == 1) {
            int randomChild = adj[1][0];
            printf("1 %d\n", randomChild);
            printf("1 %d\n", randomChild);
        } else {
            int centroid;
            for (int n = 1; n <= N; n++) {
                if (minMaxSubtree == maxSubtree[n]) {
                    centroid = n;
                    break;
                }
            }

            int anotherCentroid;
            int randomChild;
            for (int next : adj[centroid]) {
                if (minMaxSubtree == maxSubtree[next]) {
                    anotherCentroid = next;
                } else {
                    randomChild = next;
                }
            }

            printf("%d %d\n", centroid, randomChild);
            printf("%d %d\n", anotherCentroid, randomChild);
        }
    }

    return 0;
}
