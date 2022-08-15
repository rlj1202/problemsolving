#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

struct mat {
    ll arr[2][2];

    mat operator*(const mat &o) {
        mat result{{ {0, 0}, {0, 0} }};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.arr[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.arr[i][j] += arr[i][k] * o.arr[k][j];

                    if (result.arr[i][j] < 0) {
                        result.arr[i][j] += MOD;
                    } else {
                        result.arr[i][j] %= MOD;
                    }
                }
            }
        }
        return result;
    }
};

mat power(mat m, ll exp) {
    mat result{ { {1, 0}, {0, 1} } };

    mat cur = m;
    while (exp) {
        if (exp & 1 == 1) {
            result = result * cur;
        }

        cur = cur * cur;
        exp >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N;
    cin >> N;

    if (N % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    mat result = power({{ {4, -1}, {1, 0} }}, N / 2 - 1) * mat{ { {3, 0}, {1, 0} } };

    cout << result.arr[0][0] << '\n';

    return 0;
}
