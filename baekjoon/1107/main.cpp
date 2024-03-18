#include <bits/stdc++.h>

using namespace std;

bool broken[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int m = 0; m < M; m++) {
        int key;
        cin >> key;
        broken[key] = true;
    }

    int answer = 0x3f3f3f3f;

    for (int channel = 0; channel <= 10'000'000; channel++) {
        int digits = 0;
        int cur = channel;

        bool invalid = false;

        while (cur) {
            int digit = cur % 10;

            if (broken[digit]) {
                invalid = true;
                break;
            }

            digits++;
            cur /= 10;
        }

        if (channel == 0) {
            digits = 1;

            if (broken[0]) {
                invalid = true;
            }
        }

        if (invalid) {
            continue;
        }

        answer = min(answer, abs(N - channel) + digits);
    }

    answer = min(answer, abs(N - 100));

    cout << answer << '\n';

    return 0;
}
