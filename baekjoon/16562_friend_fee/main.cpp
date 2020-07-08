#include <cstdio>
#include <algorithm>

using namespace std;


int parents[100005];
int size[100005];
int fees[100005];

bool checked[100005];

int find(int a) {
    if (parents[a] == 0) return a;
    return parents[a] = find(parents[a]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;

    if (size[A] > size[B]) {
        int tmp = A;
        A = B;
        B = tmp;
    }

    parents[A] = B;
    size[B] += size[A];
    fees[B] = min(fees[B], fees[A]);

    return true;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int n = 1; n <= N; n++) {
        scanf("%d", fees + n);
        size[n] = 1;
    }
    for (int m = 0; m < M; m++) {
        int v, w;
        scanf("%d %d", &v, &w);
        merge(v, w);
    }

    int totalCount = 0;
    int totalFee = 0;

    for (int n = 1; n <= N; n++) {
        int g = find(n);
        if (checked[g]) continue;
        checked[g] = true;

        totalCount += size[g];
        totalFee += fees[g];
    }

    if (totalCount == N && totalFee <= K) {
        printf("%d\n", totalFee);
    } else {
        printf("Oh no\n");
    }

    return 0;
}