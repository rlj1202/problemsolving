#include <bits/stdc++.h>

using namespace std;

int arr[1 << 18];
int low[1 << (18 + 2)];
int upper[1 << (18 + 2)];

void calc(int node, int l, int r) {
    if (l == r) {
        return;
    }

    int mid = (l + r) / 2;

    calc(node * 2, l, mid);
    calc(node * 2 + 1, mid + 1, r);

    low[node] = min(low[node * 2], low[node * 2 + 1]);
    upper[node] = max(upper[node * 2], upper[node * 2 + 1]);
}

bool isPossible(int node, int l, int r) {
    if (l == r) {
        return true;
    }

    int mid = (l + r) / 2;

    if (!isPossible(node * 2, l, mid)) return false;
    if (!isPossible(node * 2 + 1, mid + 1, r)) return false;

    if (upper[node * 2] + 1 != low[node * 2 + 1] && upper[node * 2 + 1] + 1 != low[node * 2]) return false;

    return true;
}

int count(int node, int l, int r) {
    if (l == r) {
        return 0;
    }

    bool switching = false;

    if (upper[node * 2] + 1 != low[node * 2 + 1]) {
        switching = true;
    }

    int mid = (l + r) / 2;
    return count(node * 2, l, mid) + count(node * 2 + 1, mid + 1, r) + switching;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> M;

        for (int m = 0; m < M; m++) {
            cin >> arr[m];

            low[m + M] = arr[m];
            upper[m + M] = arr[m];
        }

        calc(1, 0, M - 1);
        bool possible = isPossible(1, 0, M - 1);

        if (possible) {
            cout << count(1, 0, M - 1) << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}
