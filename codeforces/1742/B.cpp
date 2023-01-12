#include <bits/stdc++.h>

using namespace std;

int arr[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int n = 0; n < N; n++) {
            cin >> arr[n];
        }

        sort(arr, arr + N);

        bool result = true;

        for (int n = 1; n < N; n++) {
            if (arr[n - 1] == arr[n]) {
                result = false;
                break;
            }
        }

        cout << (result ? "YES" : "NO") << '\n';
    }

    return 0;
}
