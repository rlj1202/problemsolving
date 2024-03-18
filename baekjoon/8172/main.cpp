#include <bits/stdc++.h>

using namespace std;

int weight[1000006];
int A[1000006];
int B[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> weight[n];
    }
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }
    for (int n = 0; n < N; n++) {
        cin >> B[n];
    }

    cout << 0 << '\n';

    return 0;
}
