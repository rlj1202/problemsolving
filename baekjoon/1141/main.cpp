#include <bits/stdc++.h>

using namespace std;

string arr[52];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }

    sort(arr, arr + N);

    int cnt = 0;

    for (int n = 0; n < N; n++) {
        bool is_prefix = false;
        for (int m = n + 1; m < N; m++) {
            if (arr[m].substr(0, arr[n].length()) == arr[n]) {
                is_prefix = true;
                break;
            }
        }

        if (is_prefix) {
            cnt++;
        }
    }

    int answer = N - cnt;

    cout << answer << '\n';

    return 0;
}
