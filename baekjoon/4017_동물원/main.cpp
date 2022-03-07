#include <cstdio>
#include <vector>

using namespace std;

int cage[50004];
vector<int> fears[50004];
vector<int> likes[50004];

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    for (int c = 0; c < C; c++) {
        int E, F, L;
        scanf("%d %d %d", &E, &F, &L);

        cage[c] = E;

        for (int f = 0; f < F; f++) {
            int value;
            scanf("%d", &value);
            fears[c].push_back(value);
        }
        for (int l = 0; l < L; l++) {
            int value;
            scanf("%d", &value);
            likes[c].push_back(value);
        }
    }

    printf("%d\n", 0);

    return 0;
}
