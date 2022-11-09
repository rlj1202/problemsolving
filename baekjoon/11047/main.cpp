#include <bits/stdc++.h>

using namespace std;

int arr[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }

    int cur = K;
    int answer = 0;

    for (int n = N - 1; n >= 0; n--) {
        while (cur >= arr[n]) {
            cur -= arr[n];
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
