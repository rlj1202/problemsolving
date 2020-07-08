#include <cstdio>

const int SIZE = 50;
int fibo[SIZE];

int main() {
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        printf("%d\n", fibo[i]);
    }

    return 0;
}