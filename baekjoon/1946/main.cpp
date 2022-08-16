#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        vector<pii> arr;

        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            int grade, order;
            cin >> grade >> order;
            arr.push_back({ grade, order });
        }

        sort(arr.begin(), arr.end());

        int result = 0;
        int cur_min = N + 1;
        for (int n = 0; n < N; n++) {
            pii &cur = arr[n];

            if (cur_min > cur.second) {
                cur_min = cur.second;
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
