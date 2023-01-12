#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int maxIndex[1003];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        memset(maxIndex, 0, sizeof(maxIndex));

        for (int n = 1; n <= N; n++) {
            cin >> arr[n];

            maxIndex[arr[n]] = max(maxIndex[arr[n]], n);
        }

        int answer = -1;

        for (int i = 1; i <= 1000; i++) {
            for (int j = i; j <= 1000; j++) {
                if (!isCoprime(i, j)) continue;
                if (maxIndex[i] == 0) continue;
                if (maxIndex[j] == 0) continue;

                answer = max(answer, maxIndex[i] + maxIndex[j]);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
