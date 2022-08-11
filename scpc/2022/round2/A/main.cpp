#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int arr[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;

        for (int n = 0; n < N; n++) {
            cin >> arr[n];

            arr[n] = max(K - arr[n], 0);
        }

        int l = 0;
        int r = N - 1;

        int l_max = arr[l];
        int r_max = arr[r];

        int height = 0;

        ll cnt = 0;
        ll sum = 0;

        while (l <= r) {
            int next_height = min(l_max, r_max);

            sum += (r - l + 1) * (ll) max(next_height - height, 0);

            if (next_height > height) {
                cnt += (ll) (next_height - height);
                height = next_height;
            }

            if (l_max < r_max) {
                l++;
                l_max = max(l_max, arr[l]);
            } else {
                r--;
                r_max = max(r_max, arr[r]);
            }
        }

        cout << "Case #" << t << '\n';
        cout << cnt << ' ' << sum << '\n';
    }

    return 0;
}
