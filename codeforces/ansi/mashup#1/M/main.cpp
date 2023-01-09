#include <cstdio>
#include <algorithm>

using namespace std;

// c1 = one ride on some bus or trolley
// c2 = infinite ride on some bus or trolley
// c3 = infinite ride on all bus or trolley
// c4 = infinite ride on all bus and trolley

int costs[4];
int buses[1003];
int trolleys[1003];

int minBus[1003];
int minTrolley[1003];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", costs + i);
    }

    int N, M;
    scanf("%d %d", &N, &M);

    for (int n = 0; n < N; n++) {
        scanf("%d", buses + n);
    }
    for (int m = 0; m < M; m++) {
        scanf("%d", trolleys + m);
    }

    int minBusSum = 0;
    int minTrolleySum = 0;

    for (int n = 0; n < N; n++) {
        minBus[n] = min(costs[0] * buses[n], costs[1]);

        minBusSum += minBus[n];
    }
    for (int m = 0; m < M; m++) {
        minTrolley[m] = min(costs[0] * trolleys[m], costs[1]);

        minTrolleySum += minTrolley[m];
    }

    int minBuses = min(costs[2], minBusSum);
    int minTrolleys = min(costs[2], minTrolleySum);

    int result = min(costs[3], minBuses + minTrolleys);

    printf("%d\n", result);

    return 0;
}
