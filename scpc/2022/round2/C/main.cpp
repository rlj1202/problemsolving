#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, char> pic;

vector<pic> adj[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N, M, K;
        cin >> N >> M >> K;
        for (int n = 1; n <= N; n++) {
            adj[n].clear();
        }
        for (int m = 0; m < M; m++) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            adj[a].push_back({ b, c });
        }

        cout << "Case #" << t << '\n';
        cout << 0 << '\n';
    }

    return 0;
}
