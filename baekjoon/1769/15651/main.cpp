#include <bits/stdc++.h>

using namespace std;

int N, M;

int digits[10];

void recur(int place) {
    if (place == M) {
        for (int i = 0; i < M; i++) {
            cout << digits[i] << ' ';
        }
        cout << '\n';

        return;
    }

    for (int i = 1; i <= N; i++) {
        digits[place] = i;

        recur(place + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    recur(0);

    return 0;
}
