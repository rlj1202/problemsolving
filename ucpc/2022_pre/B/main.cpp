#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point { ll x, y; };
struct line { point a, b; ll weight; };

vector<line> lines;

ll costs[3003];
ll gains[3003];

bool used[3003];
bool adj[3003][3003];

ll ccw(point p1, point p2, point p3){
    ll t1 = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    ll t2 = p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;

    if (t1 == t2) return 0;
    else return t1 < t2 ? -1 : 1; 
}

bool intersects(line &a, line &b) {
    ll r1 = ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b);
    ll r2 = ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b);

    return r1 == -1 && r2 == -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    lines.resize(N);
    for (int n = 0; n < N; n++) {
        auto &[a, b, weight] = lines[n];
        cin >> a.x >> a.y >> b.x >> b.y >> weight;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersects(lines[i], lines[j])) {
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }

    //
    for (int i = 0; i < N; i++) {
        ll &curcost = costs[i];
        ll &curgain = gains[i];

        curcost += lines[i].weight;

        for (int j = 0; j < N; j++) {
            if (!adj[i][j]) continue;
            if (i == j) continue;

            curcost += lines[i].weight;
            curgain += lines[j].weight;
        }
    }

    //
    ll result = 0;

    for (int i = 0; i < N; i++) {
        // find mincost vertex
        int minvertex = -1;
        ll mincost = 0x3f3f3f3f3f3f3f3f;
        ll maxgain = 0;

        for (int n = 0; n < N; n++) {
            if (used[n]) continue;
            
            if (mincost > costs[n]) {
                mincost = costs[n];
                maxgain = gains[n];
                minvertex = n;
            } else if (mincost == costs[n]) {
                if (maxgain < gains[n]) {
                    maxgain = gains[n];
                    minvertex = n;
                }
            }
        }

        if (minvertex == -1) break;

        used[minvertex] = true;
        result += mincost;

        // update neighbor vertices
        for (int n = 0; n < N; n++) {
            if (used[n]) continue;
            if (!adj[minvertex][n]) continue;

            costs[n] -= lines[n].weight;
            gains[n] -= lines[minvertex].weight;

            adj[minvertex][n] = false;
            adj[n][minvertex] = false;
        }
    }

    cout << result << '\n';

    return 0;
}
