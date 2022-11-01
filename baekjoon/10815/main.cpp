#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int &n : arr) cin >> n;

    sort(arr.begin(), arr.end());

    int M;
    cin >> M;
    while (M--) {
        int value;
        cin >> value;

        bool result = binary_search(arr.begin(), arr.end(), value);

        cout << result << ' ';
    }
    cout << '\n';

    return 0;
}
