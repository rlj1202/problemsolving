#include <bits/stdc++.h>

using namespace std;

int arr[1000006];
int compressed[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }

    memcpy(compressed, arr, sizeof(arr));

    sort(compressed, compressed + N);
    int len = unique(compressed, compressed + N) - compressed;

    for (int n = 0; n < N; n++) {
        int index = lower_bound(compressed, compressed + len, arr[n]) - compressed;

        cout << index << ' ';
    }

    cout << '\n';

    return 0;
}
