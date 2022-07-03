#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

vector<int> A;
vector<int> B;

int dp[3003];

int main() {
    int L, N;
    cin >> L >> N;

    A.push_back(0);
    for (int n = 0; n < N; n++) {
        int length;
        cin >> length;

        if (length == 1) {
            A.push_back(0);
        } else {
            A.push_back(1);
            A.push_back(2);
        }
    }

    int M;
    cin >> M;

    B.push_back(0);
    for (int m = 0; m < M; m++) {
        int length;
        cin >> length;

        if (length == 1) {
            B.push_back(0);
        } else {
            B.push_back(1);
            B.push_back(2);
        }
    }

    dp[1] = 1;
    dp[2] = 1;

    for (int l = 3; l <= L; l++) {
        dp[l] = 0;

        for (int i = 0; i < l / 2; i++) {
            int left = i * 2 + 1;
            int right = l - left;
            dp[l] += dp[left] * dp[right];
            if (left != 1 && right != 1) {
                dp[l] += dp[left] * dp[right];
            }

            cout << "\t\t" << dp[left] << " " << dp[right] << "\n";
        }

        cout << "\t" << l << " " << dp[l] << "\n";
    }

    cout << 0 << " " << 0 << "\n";

    return 0;
}
