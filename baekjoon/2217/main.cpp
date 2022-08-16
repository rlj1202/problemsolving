#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int arr[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }

    sort(arr, arr + N, greater<int>());

    int result = 0;

    for (int n = 0; n < N; n++) {
        result = max(result, arr[n] * (n + 1));
    }

    cout << result << '\n';

    return 0;
}
