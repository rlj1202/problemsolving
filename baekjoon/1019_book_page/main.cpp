#include <cstdio>

using namespace std;

int digits[10];

void calc(int num, int unit) {
    for (; num; num /= 10) {
        digits[num % 10] += unit;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int a = 1;
    int b = N;
    int unit = 1;
    while (true) {
        while (a % 10 != 0 && a <= b) {
            calc(a++, unit);
        }
        while (b % 10 != 9 && a <= b) {
            calc(b--, unit);
        }
        if (a > b) break;

        a /= 10;
        b /= 10;

        int rows = b - a + 1;
        for (int i = 0; i < 10; i++) {
            digits[i] += rows * unit;
        }

        unit *= 10;
    }

    for (int i = 0; i < 10; i++) printf("%d ", digits[i]);
    printf("\n");

    return 0;
}