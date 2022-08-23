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

    sort(arr, arr + N);

    int M;
    cin >> M;
    for (int m = 0; m < M; m++) {
        int value;
        cin >> value;

        bool result = binary_search(arr, arr + N, value);

        cout << result << '\n';
    }

    return 0;
}
