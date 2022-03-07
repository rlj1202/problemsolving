#include <cstdio>
#include <algorithm>

using namespace std;

int heights[9];

int main() {
    for (int i = 0; i < 9; i++) {
        scanf("%d", heights + i);
    }

    sort(heights, heights + 9);

    for (int i = 0; i < 9 - 1; i++) {
        for (int j = i + 1; j < 9; j++) {
            int sum = 0;
            for (int k = 0 ; k < 9; k++) {
                if (k != i && k != j) sum += heights[k];
            }

            if (sum == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) printf("%d\n", heights[k]);
                }

                return 0;
            }
        }
    }

    return 0;
}