#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int answer = 0;

        for (int three = 0; three * 3 <= N; three++) {
            answer += (N - three * 3) / 2;
            answer++;
        }

        cout << answer << '\n';
    }

    return 0;
}
