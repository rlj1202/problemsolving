#include <bits/stdc++.h>

using namespace std;

int arr[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    int B, C;
    cin >> N;

    long long answer = 0;

    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }

    cin >> B >> C;

    for (int n = 0; n < N; n++) {
        arr[n] = max(0, arr[n] - B);
    }
    answer += N;

    for (int n = 0; n < N; n++) {
        answer += (arr[n] + C - 1) / C;
    }

    cout << answer << '\n';

    return 0;
}
