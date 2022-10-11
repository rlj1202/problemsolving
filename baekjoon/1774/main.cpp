#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
    ll x, y;

    ll dist_square(const point &o) {
        ll dx = x - o.x;
        ll dy = y - o.y;
        return dx*dx + dy*dy;
    }
};

struct edge {
    int u, v;
    ll dist_square;

    bool operator<(const edge &o) const {
        return dist_square < o.dist_square;
    }
};

point points[1003];

int parent[1003];
vector<edge> edges;

int find(int a) {
    if (!parent[a]) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;

    parent[A] = B;

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    for (int n = 1; n <= N; n++) {
        int x, y;
        cin >> x >> y;

        points[n] = { x, y };
    }

    for (int m = 0; m < M; m++) {
        int u, v;
        cin >> u >> v;

        merge(u, v);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            ll dist = points[i].dist_square(points[j]);

            edges.push_back({ i, j, dist });
        }
    }

    sort(edges.begin(), edges.end());

    double answer = 0;

    for (auto &[u, v, weight] : edges) {
        if (merge(u, v)) {
            answer += sqrt(weight);
        }
    }

    cout << fixed << setprecision(2) << answer << '\n';

    return 0;
}
