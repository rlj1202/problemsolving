#include <cstdio>

using namespace std;

int v[3];
int s[3];
int e[3];

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d", v + i, s + i, e + i);
    }

    int result = -1;

    for (int t = 0; t <= 2000 * 2000; t++) {
        bool valid = true;
        for (int i = 0; i < 3; i++) {
            valid &= s[i] <= (t % v[i]) && (t % v[i]) <= e[i];
        }
        if (valid) {
            result = t;
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}
