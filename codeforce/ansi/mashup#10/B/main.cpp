#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int children[200005];
priority_queue<int> pq;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        memset(children, 0, sizeof(children));
        for (int n = 2; n <= N; n++) {
            int parent;
            scanf("%d", &parent);

            children[parent]++;
        }

        sort(children + 1, children + N + 1, greater<int>());

        pq = priority_queue<int>();

        int cnt = 1;
        for (int n = 1; n <= N; n++) {
            if (children[n]) cnt++;
        }

        for (int n = 1; children[n] > 0; n++) {
            int remains = children[n] + n - 1 - cnt;
            if (remains > 0) {
                pq.push(remains);
            }
        }
     
        int seconds = 0;
        while (!pq.empty()) {
            int value = pq.top();
            if (value - seconds < 2) break;

            pq.pop();
            pq.push(value - 1);
            seconds++;
        }

        int result = cnt;
        if (!pq.empty()) result += pq.top();

        printf("%d\n", result);
    }

    return 0;
}
