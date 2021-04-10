#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int D[502][502];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &D[i][j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        int m = INF;
        for (int j = 1; j <= N; j++) m = min(m, D[i][j]);
        for (int j = 1; j <= N; j++) D[i][j] -= m;
    }
    for (int j = 1; j <= N; j++) {
        int m = INF;
        for (int i = 1; i <= N; i++) m = min(m, D[i][j]);
        for (int i = 1; i <= N; i++) D[i][j] -= m;
    }

    while (true) {
        // find min vertex corver
    }

    printf("%d\n", 0);

    return 0;
}