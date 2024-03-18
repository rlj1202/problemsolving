#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int A[2003];
int B[2003];

int A_remap[2003];
int B_remap[2003];

pii lines[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }
    for (int m = 0; m < M; m++) {
        cin >> B[m];
    }

    for (int n = 0; n < N; n++) {
        A_remap[A[n]] = n;
    }
    for (int m = 0; m < M; m++) {
        B_remap[B[m]] = m;
    }

    int K;
    cin >> K;

    for (int k = 0; k < K; k++) {
        int a, b;
        cin >> a >> b;

        a = A_remap[a];
        b = B_remap[b];

        lines[k] = { a, b };
    }

    sort(lines, lines + K, [](pii &a, pii &b) -> bool {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    vector<int> arr;

    for (int k = 0; k < K; k++) {
        int cur = lines[k].second;

        auto index = lower_bound(arr.begin(), arr.end(), cur);

        if (index == arr.end()) {
            arr.push_back(cur);
        } else {
            *index = cur;
        }
    }

    int answer = K - arr.size();

    cout << answer << '\n';

    return 0;
}
