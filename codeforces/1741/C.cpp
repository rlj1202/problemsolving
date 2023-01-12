#include <bits/stdc++.h>

using namespace std;

int arr[2003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int n = 0; n < N; n++) {
            cin >> arr[n];
        }

        int answer = 0x3f3f3f3f;

        for (int l = 1; l <= N; l++) {
            int firstSeg = 0;
            int maxThick = l;
            bool possible = true;

            int i = 0;
            for (; i < l; i++) {
                firstSeg += arr[i];
            }

            while (i < N) {
                int curSeg = 0;
                int thick = 0;
                while (i < N && curSeg + arr[i] <= firstSeg) {
                    curSeg += arr[i];
                    i++;
                    thick++;
                }

                if (curSeg != firstSeg) {
                    possible = false;
                    break;
                }

                maxThick = max(maxThick, thick);
            }

            if (possible) {
                answer = min(answer, maxThick);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
