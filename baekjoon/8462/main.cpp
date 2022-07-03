#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int arr[100005];

vector<pii> ranges;

int counts[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, T;
    cin >> N >> T;
    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }
    for (int t = 0; t < T; t++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({ l, r });
    }

    sort(ranges.begin(), ranges.end());

    cout << '\n';

    return 0;
}
