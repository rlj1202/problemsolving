#include <bits/stdc++.h>

using namespace std;

int nums[12];

bool is_prime(int n) {
    if (n == 1) return false;

    bool is_it = true;

    int sqrt_n = sqrt(n);

    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            is_it = false;
            break;
        }
    }

    return is_it;
}

void dfs(int digits) {
    if (digits == 0) {
        cout << nums[1] << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        nums[digits] = nums[digits + 1] * 10 + i;

        if (!is_prime(nums[digits])) {
            continue;
        }

        dfs(digits - 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    dfs(N);

    return 0;
}
