#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[1003];
int indegrees[1003];

int queue[1003];
int l, r;

int result[1003];
int size;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 1; m <= M; m++) {
        int singers;
        scanf("%d", &singers);
        int prev = -1;
        for (int s = 0; s < singers; s++) {
            int singer;
            scanf("%d", &singer);

            if (prev != -1) {
                adj[prev].push_back(singer);
                indegrees[singer]++;
            }

            prev = singer;
        }
    }
    for (int n = 1; n <= N; n++) {
        if (!indegrees[n])
            queue[r++] = n;
    }

    while (r - l) {
        int cur = queue[l++];
        result[size++] = cur;

        for (int next : adj[cur]) {
            if (--indegrees[next] == 0) {
                queue[r++] = next;
            }
        }
    }

    if (size == N) {
        for (int i = 0; i < size; i++) {
            printf("%d\n", result[i]);
        }
    } else {
        printf("0\n");
    }

    return 0;
}