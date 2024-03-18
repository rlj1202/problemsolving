#include <bits/stdc++.h>

using namespace std;

int A[102][102];
int B[102][102];
int result[102][102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> A[n][m];
        }
    }

    cin >> M >> K;

    for (int m = 0; m < M; m++) {
        for (int k = 0; k < K; k++) {
            cin >> B[m][k];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
