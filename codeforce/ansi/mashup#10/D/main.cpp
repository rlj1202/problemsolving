#include <cstdio>
#include <algorithm>

using namespace std;

int A[200005];
int B[200005];

int find_cost(int* arr, int len, int value) {
    int left = lower_bound(arr, arr + len, value) - arr;
    left = min(left, len - 1);

    int cost = abs(arr[left] - value);
    if (left - 1 >= 0) cost = min(cost, abs(arr[left - 1] - value));
    return cost;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", A + n);
        }
        for (int n = 0; n < N; n++) {
            scanf("%d", B + n);
        }

        int Aleft = A[0];
        int Aright = A[N - 1];
        int Bleft = B[0];
        int Bright = B[N - 1];

        sort(A, A + N);
        sort(B, B + N);

        long long result = 0;

        long long Aleftcost = find_cost(B, N, Aleft);
        long long Arightcost = find_cost(B, N, Aright);
        long long Bleftcost = find_cost(A, N, Bleft);
        long long Brightcost = find_cost(A, N, Bright);

        result = Aleftcost + Arightcost + Bleftcost + Brightcost;

        result = min(result, Aleftcost + Bleftcost + abs(Aright - Bright));
        result = min(result, Arightcost + Brightcost + abs(Aleft - Bleft));

        result = min(result, Aleftcost + Brightcost + abs(Aright - Bleft));
        result = min(result, Arightcost + Bleftcost + abs(Aleft - Bright));

        result = min(result, abs(Aleft - Bleft) + (long long) abs(Aright - Bright));
        result = min(result, abs(Aleft - Bright) + (long long) abs(Aright - Bleft));

        printf("%lld\n", result);
    }

    return 0;
}
