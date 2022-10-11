#include <bits/stdc++.h>

using namespace std;

int colors[10004];

int cnt_a[10004];
int cnt_b[10004];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int uniques_a = 0;

    for (int n = 0; n < N; n++) {
        cin >> colors[n];

        if (cnt_a[colors[n]] == 0) uniques_a++;
        cnt_a[colors[n]]++;
    }

    int left = 0;
    int right = 0;

    int uniques_b = 0;

    int answer = 0x3f3f3f3f;

    while (left < N) {
        while (uniques_b < K && right < N) {
            int next = colors[right];

            if (cnt_b[next]++ == 0) uniques_b++;
            right++;
            if (cnt_a[next]-- == 1) uniques_a--;
        }

        while (left < right) {
            int cur = colors[left];

            if (cnt_b[cur] > 1) {
                cnt_b[cur]--;
                left++;

                if (cnt_a[cur]++ == 0) uniques_a++;
            } else {
                break;
            }
        }

        if (uniques_a == K && uniques_b == K) {
            answer = min(answer, right - left);
        }

        int cur = colors[left];
        if (cnt_b[cur]-- == 1) uniques_b--;
        if (cnt_a[cur]++ == 0) uniques_a++;

        left++;
    }

    cout << (answer == 0x3f3f3f3f ? 0 : answer) << '\n';

    return 0;
}
