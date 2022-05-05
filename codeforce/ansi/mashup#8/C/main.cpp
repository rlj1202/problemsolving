#include <cstdio>

using namespace std;

int count[100005];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        int x;
        scanf("%d", &x);

        count[x]++;
    }

    long long rects = 0;
    long long pairs = 0;

    for (int x = 1; x < 100005; x++) {
        rects += count[x] / 4;
        pairs += (count[x] % 4) / 2;
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        char event;
        int x;
        scanf(" %c %d", &event, &x);

        rects -= count[x] / 4;
        pairs -= (count[x] % 4) / 2;

        count[x] += event == '+' ? 1 : -1;

        rects += count[x] / 4;
        pairs += (count[x] % 4) / 2;

        bool possible = (rects >= 2) || (rects == 1 && pairs >= 2);

        printf("%s\n", possible ? "YES" : "NO");
    }

    return 0;
}
