#include <cstdio>
#include <algorithm>

using namespace std;

int perm[100005];
int indices[100005];

int parent[100005];

int setsize[100005 * 4];

int update(int node, int l, int r, int i, int value) {
    if (i < l || r < i) return setsize[node];

    if (l == r) {
        return setsize[node] = value;
    }

    int mid = (l + r) / 2;
    int left = update(node * 2 + 1, l, mid, i, value);
    int right = update(node * 2 + 2, mid + 1, r, i, value);

    return setsize[node] = max(left, right);
}

int query(int node, int l, int r, int i, int j) {
    if (j < l || r < i) return 0;

    if (i <= l && r <= j) {
        return setsize[node];
    }

    int mid = (l + r) / 2;
    int left = query(node * 2 + 1, l, mid, i, j);
    int right = query(node * 2 + 2, mid + 1, r, i, j);

    return max(left, right);
}

int find(int i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent[i]);
}

void merge(int i, int j, int n) {
    int A = find(i);
    int B = find(j);

    if (A == B) return;

    parent[A] = B;

    int Asetsize = query(0, 0, n, A, A);
    int Bsetsize = query(0, 0, n, B, B);
    update(0, 0, n, B, Asetsize + Bsetsize);
    update(0, 0, n, A, 0);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 1e5
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", perm + n); // N

            indices[perm[n]] = n;

            parent[n] = -1;
            update(0, 0, N, n, 1);
        }
        parent[N] = -1;
        update(0, 0, N, N, 0);

        bool result = true;

        for (int n = 1; n <= N; n++) {
            int A = find(indices[n]);
            int B = find(indices[n] + 1);

            // printf("\t");
            // for (int i = 0; i < N; i++) printf("%d ", query(0, 0, N, i, i));
            // printf("\n");

            int maxSize = query(0, 0, N, 0, N - 1);
            int Asize = query(0, 0, N, A, A);

            // printf("\t%d at position %d, maxSize = %d\n", n, indices[n], maxSize);

            if (Asize == maxSize) {
                merge(A, B, N);
            } else {
                result = false;
                break;
            }
        }

        printf("%s\n", result ? "Yes" : "No");
    }

    return 0;
}
