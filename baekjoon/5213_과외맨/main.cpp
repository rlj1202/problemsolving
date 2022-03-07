#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

struct point { int r, c; };

int N;
int arr[502][502 * 2];
int nodes[502][502 * 2];
point points[502 * 502];

int queue[502 * 502];
int visited[502 * 502];
int prev_node[502 * 502];
int left, right;

int row(int i) {
    return (i + (i / (N*2 - 1))) / N;
}

int col(int i) {
    return (i + (i / (N*2 - 1))) % N;
}

int main() {
    memset(nodes, -1, sizeof(nodes));

    scanf("%d", &N);
    for (int i = 0; i < N * N - N / 2; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        int r = row(i), c = col(i);

        arr[r][c*2 + 0 + (r % 2)] = a;
        arr[r][c*2 + 1 + (r % 2)] = b;

        nodes[r][c*2 + 0 + (r % 2)] = i;
        nodes[r][c*2 + 1 + (r % 2)] = i;

        points[i] = {r, c * 2 + (r % 2)};
    }

    memset(prev_node, -1, sizeof(prev_node));

    visited[0] = 1;
    queue[right++] = 0;

    while (right - left > 0) {
        int cur = queue[left++];
        int cr = points[cur].r;
        int cc = points[cur].c;
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                int nr = cr + dr[i];
                int nc = cc + j + dc[i];
                if (nr < 0) continue;
                if (nc < 0) continue;

                int next = nodes[nr][nc];
                if (next == -1) continue;
                if (cur == next) continue;
                if (visited[next]) continue;

                if (arr[cr][cc + j] != arr[nr][nc]) continue;

                visited[next] = visited[cur] + 1;
                queue[right++] = next;
                prev_node[next] = cur;
            }
        }
    }

    int final_node = N*N - N / 2 - 1;
    for (int i = 0; i < N*N - N / 2; i++) {
        int node = N*N - N / 2 - 1 - i;

        if (visited[node]) {
            final_node = node;
            break;
        }
    }

    printf("%d\n", visited[final_node]);

    int path[502 * 502];
    int path_top = 0;

    int cur = final_node;
    while (cur != -1) {
        path[path_top++] = cur;
        cur = prev_node[cur];
    }

    while (path_top) {
        printf("%d ", path[--path_top] + 1);
    }
    printf("\n");

    return 0;
}
