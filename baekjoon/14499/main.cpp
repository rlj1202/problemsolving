#include <bits/stdc++.h>

using namespace std;

const int EAST = 1;
const int WEST = 2;
const int NORTH = 3;
const int SOUTH = 4;

int grid[22][22];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    int x, y;
    int K;
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> grid[n][m];
        }
    }

    for (int k = 0; k < K; k++) {
        int cmd;
        cin >> cmd;
    }

    cout << '\n';

    return 0;
}
