#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<long long> pq;
priority_queue<long long> cur;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        pq = priority_queue<long long>();
        cur = priority_queue<long long>();

        long long sum = 0;

        for (int n = 0; n < N; n++) {
            long long value;
            scanf("%lld", &value);
            sum += value;
            pq.push(value);
        }

        cur.push(sum);

        while (!pq.empty()) {
            while (!pq.empty() && !cur.empty() && pq.top() == cur.top()) {
                pq.pop();
                cur.pop();
            }

            if (pq.empty()) break;
            if (pq.top() > cur.top()) break;

            long long value = cur.top();
            cur.pop();

            cur.push(value / 2);
            cur.push((value + 1) / 2);
        }

        printf("%s\n", pq.empty() ? "YES" : "NO");
    }

    return 0;
}
