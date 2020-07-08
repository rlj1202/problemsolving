#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int node, weight;
};

vector<edge> tree[100005];

// Returns longest distance from root to leaf
int get_radius(int node, int &radius) {
    if (tree[node].size() == 0) {
        return 0;
    }

    int a = 0;
    int b = 0;
    for (edge e : tree[node]) {
        int distance = get_radius(e.node, radius) + e.weight;

        if (a <= distance) {
            b = a;
            a = distance;
        } else if (b < distance) {
            b = distance;
        }
    }

    radius = max(radius, a + b);

    return a;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N - 1; n++) {
        int parent, child, weight;
        scanf("%d %d %d", &parent, &child, &weight);
        tree[parent].push_back({child, weight});
    }

    int result = 0;
    get_radius(1, result);
    printf("%d\n", result);

    return 0;
}