#include <cstdio>

using namespace std;

int main() {
    int M, S, X1, X2;
    scanf("%d %d %d %d", &M, &S, &X1, &X2);

    for (int a = 0; a <= M; a++) {
        for (int c = 0; c <= M; c++) {
            if (X1 == (a*S + c) % M &&
                X2 == (a*X1 + c) % M) {
                printf("%d %d\n", a, c);
                return 0;
            }
        }
    }

    return 0;
}
