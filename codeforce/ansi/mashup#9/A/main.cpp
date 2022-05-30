#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        bool win = true;

        if (N % 2 == 0) {
            int cur = N;
            int power = 0;
            while (cur % 2 == 0) {
                cur /= 2;
                power++;
            }

            if (cur == 1) {
                if (power % 2 == 0) {
                    win = true;
                } else {
                    win = false;
                }
            } else {
                win = true;
            }
        } else {
            win = false;
        }

        printf("%s\n", win ? "Alice" : "Bob");
    }

    return 0;
}
