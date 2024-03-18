#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    // 1 * 2 * 3 * 4 * 5 * 6 * ... * N - 1 * N

    // 10이 곱해진 횟수를 구하면 된다.

    int answer = 0;
    answer += N / 5;
    answer += N / (5 * 5);
    answer += N / (5 * 5 * 5);

    cout << answer << '\n';

    return 0;
}
