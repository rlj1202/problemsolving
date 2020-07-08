#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct station {
    int pos, fuel;

    bool operator< (const station &o) const {
        if (fuel == o.fuel) return pos < o.pos;
        return fuel < o.fuel;
    }
};

station stations[10004];

priority_queue<station> q;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int a, b;
        scanf("%d %d", &a, &b);
        stations[n] = {a, b};
    }
    int L, P;
    scanf("%d %d", &L, &P);

    stations[N++] = {L, 0};

    sort(stations, stations + N, [](station &a, station &b) -> bool {
        return a.pos < b.pos;
    });

    int result = 0;

    int curFule = P;
    for (int n = 0; n < N; n++) {
        while (curFule < stations[n].pos) {
            if (q.empty()) {
                printf("-1\n");
                return 0;
            }

            curFule += q.top().fuel;
            q.pop();
            result++;
        }
        
        q.push(stations[n]);
    }

    printf("%d\n", result);

    return 0;
}