#include <bits/stdc++.h>

using namespace std;

int frequencies[4003];
int sum[4003];
int square_sum[4003];

double dp[4003][30];

int get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int get_square_sum(int l, int r) {
    return square_sum[r] - square_sum[l - 1];
}

double get_avg(int l, int r) {
    return get_sum(l, r) / (double) (r - l + 1);
}

double get_err(int l, int r) {
    int cnt = r - l + 1;
    double avg = get_avg(l, r);
    return get_square_sum(l, r) + cnt * avg*avg - 2 * avg * get_sum(l, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int B, N;
    cin >> B >> N;

    // (a - x)^2 + (b - x)^2 + (c - x)^2
    // = a^2 + b^2 + c^2 + 3*x^2 - 2x(a + b + c)

    for (int n = 1; n <= N; n++) {
        cin >> frequencies[n];
    }

    for (int n = 1; n <= N; n++) {
        int cur = frequencies[n];
        sum[n] = sum[n - 1] + cur;
        square_sum[n] = square_sum[n - 1] + cur * cur;
    }

    for (int r = 1; r <= N; r++) {
        dp[r][1] = get_err(1, r);

        for (int b = 2; b <= min(B, r); b++) {
            dp[r][b] = dp[b - 1][b - 1] + get_err(b, r);
            
            for (int l = b + 1; l <= r; l++) {
                dp[r][b] = min(dp[r][b], dp[l - 1][b - 1] + get_err(l, r));
            }
        }
    }

    double answer = dp[N][1];
    for (int b = 1; b <= B; b++) {
        answer = min(answer, dp[N][b]);
    }

    cout << fixed << setprecision(6) << answer << '\n';

    return 0;
}
