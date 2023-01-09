#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
    int time;
    int low;
    int high;
};

vector<person> visits;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        visits.clear();

        int N, M; // 100, -1e9 ~ 1e9
        scanf("%d %d", &N, &M);
        for (int n = 0; n < N; n++) {
            int t, l, h; // t is given in non-decreasing order.
            scanf("%d %d %d", &t, &l, &h);

            if (visits.size() && visits.back().time == t) {
                person& p = visits.back();
                p.low = max(p.low, l);
                p.high = min(p.high, h);
            } else {
                visits.push_back({t, l, h});
            }
        }

        bool result = true;
        int curMinTemp = M;
        int curMaxTemp = M;
        int prevTime = 0;

        for (person& p : visits) {
            if (p.low > p.high) {
                result = false;
                break;
            }

            int delta = p.time - prevTime;
            curMinTemp += -delta;
            curMaxTemp += delta;

            prevTime = p.time;

            if (curMaxTemp < p.low || p.high < curMinTemp) {
                result = false;
                break;
            }

            curMinTemp = max(curMinTemp, p.low);
            curMaxTemp = min(curMaxTemp, p.high);
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
