#include <cstdio>
#include <algorithm>

using namespace std;

const char ANSWER[2][4] = {"NO", "YES"};

int parcels[5003];

int first[800005];
int second[800005];

int main() {
    int W, N;
    scanf("%d %d", &W, &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", parcels + n);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            int w = parcels[i] + parcels[j];
            first[w] = i;
            second[w] = j;
        }
    }

    for (int w = 1; w <= W / 2; w++) {
        if (!first[w] || !first[W - w]) continue;

        if (first[w] == first[W - w]) continue;
        if (first[w] == second[W - w]) continue;
        if (second[w] == first[W - w]) continue;
        if (second[w] == second[W - w]) continue;

        printf("%s\n", ANSWER[true]);

        return 0;
    }

    printf("%s\n", ANSWER[false]);

    return 0;
}