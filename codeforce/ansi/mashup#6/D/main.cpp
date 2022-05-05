#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int arr[3][203];
int remains[3];
int len[3];

queue<pair<int, int>> pairs[3];

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", len + i);
        remains[i] = len[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < len[i]; j++) {
            scanf("%d", arr[i] + j);
        }
        sort(arr[i], arr[i] + len[i]);
    }

    long long answer = 0;

    while (true) {
        int maxVal, first = -1, second = -1;

        maxVal = 0;
        for (int i = 0; i < 3; i++) {
            if (!remains[i]) continue;

            if (maxVal < arr[i][remains[i] - 1]) {
                maxVal = arr[i][remains[i] - 1];
                first = i;
            }
        }

        if (first == -1) break;

        maxVal = 0;
        for (int i = 0; i < 3; i++) {
            if (!remains[i]) continue;
            if (first == i) continue;

            if (maxVal < arr[i][remains[i] - 1]) {
                maxVal = arr[i][remains[i] - 1];
                second = i;
            }
        }

        if (second == -1) {
            while (remains[first] >= 2 && !pairs[first].empty()) {
                pair<int, int> cur = pairs[first].front();
                pairs[first].pop();

                int a = arr[first][remains[first] - 1];
                int b = arr[first][remains[first] - 2];

                if (cur.first * cur.second < cur.first*a + cur.second*b) {
                    answer += cur.first * a;
                    answer += cur.second * b;

                    remains[first] -= 2;
                } else {
                    answer += cur.first * cur.second;
                }
            }

            break;
        }

        for (int i = 0; i < 3; i++) {
            if (first == i) continue;
            if (second == i) continue;

            pairs[i].push({
                arr[first][--remains[first]],
                arr[second][--remains[second]]
            });
        }
    }

    for (int i = 0; i < 3; i++) {
        while (!pairs[i].empty()) {
            pair<int, int> cur = pairs[i].front();
            pairs[i].pop();
            answer += (long long) cur.first * (long long) cur.second;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
