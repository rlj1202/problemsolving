#include <bits/stdc++.h>

using namespace std;

int colors[100005];
vector<int> adj[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Read colors
    for (int n = 1; n <= N; n++) {
        cin >> colors[n];
    }

    // Read edges
    for (int n = 0; n < N - 1; n++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int q = 0; q < Q; q++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'U') {
            int A;
            int c;
            cin >> A >> c;

            colors[A] = c;
        } else if (cmd == 'Q') {
            int A, B;
            int c;
            cin >> A >> B >> c;

            // TODO:

        cout << '\n';
        }
    }

    return 0;
}
