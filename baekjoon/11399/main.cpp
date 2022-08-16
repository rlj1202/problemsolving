#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;

int arr[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> arr[n];
    }
    sort(arr, arr + N);

    int result = 0;

    int accum = 0;
    for (int n = 0; n < N; n++) {
        accum += arr[n];
        result += accum;
    }

    cout << result << endl;

    return 0;
}
