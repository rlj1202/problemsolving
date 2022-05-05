#include <cstdio>
#include <queue>

using namespace std;

long long arr[200005];

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 1; n <= N; n++) {
        scanf("%lld", arr + n);
    }

    long long sum = 0;
    int cnt = 0;

    for (int n = 1; n <= N; n++) {
        if (sum + arr[n] >= 0) {
            sum += arr[n];
            cnt++;

            if (arr[n] < 0) pq.push(arr[n]);
        } else if (!pq.empty()) {
            if (-pq.top() + arr[n] >= 0) {
                sum += -pq.top() + arr[n];

                pq.pop();
                pq.push(arr[n]);
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
