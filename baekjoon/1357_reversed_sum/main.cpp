#include <cstdio>

using namespace std;

int digits[12];

int rev(int x) {
    int i = 0;
    while (x) {
        digits[i] = x % 10;
        x /= 10;
        i++;
    }

    int j = 0;
    while (digits[j] == 0) j++;
    for (; j < i; j++) {
        x *= 10;
        x += digits[j];
    }

    return x;
}

int main() {
    int X, Y; // [1, 1000]
    scanf("%d %d", &X, &Y);

    printf("%d\n", rev(rev(X) + rev(Y)));

    return 0;
}