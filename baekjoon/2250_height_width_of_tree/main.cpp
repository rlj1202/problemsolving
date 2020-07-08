#include <cstdio>
#include <algorithm>

using namespace std;

struct tree {
    tree *left;
    tree *right;

    tree() : tree(nullptr, nullptr) {}
    tree(tree *left, tree *right) : left(left), right(right) {}
};

struct row {
    int minX;
    int maxX;

    row(): minX(0x3f3f3f3f), maxX(0) {}
};

tree nodes[10004];
int parents[10004];

row rows[100005];
int lastX;
int maxDepth;

void dfs(tree *node, int depth) {
    if (node->left) dfs(node->left, depth + 1);

    rows[depth].minX = min(rows[depth].minX, lastX);
    rows[depth].maxX = max(rows[depth].maxX, lastX);
    lastX++;
    maxDepth = max(maxDepth, depth);

    if (node->right) dfs(node->right, depth + 1);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);

        nodes[node] = {
            left != -1 ? nodes + left : nullptr,
            right != -1 ? nodes + right : nullptr
            };
        parents[left] = node;
        parents[right] = node;
    }

    int root = 0;
    for (int node = 1; node <= N; node++) {
        if (parents[node] == 0) {
            root = node;
            break;
        }
    }

    lastX = 1;
    maxDepth = 0;
    dfs(nodes + root, 1);

    int maxWidth = 0;
    int level = 0;

    for (int depth = 1; depth <= maxDepth; depth++) {
        int width = rows[depth].maxX - rows[depth].minX + 1;

        if (maxWidth < width) {
            maxWidth = width;
            level = depth;
        }
    }

    printf("%d %d\n", level, maxWidth);

    return 0;
}