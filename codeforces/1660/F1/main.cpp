#include <cstdio>
#include <cstring>

using namespace std;

char str[3003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", str);

        int result = 0;

        for (int i = 0; i < N; i++) {
            int minus = 0;
            int plus = 0;

            for (int j = i; j < N; j++) {
                if (str[j] == '+') plus++;
                if (str[j] == '-') minus++;

                int delta = minus - plus;
                if (delta < 0) continue;

                if (delta % 3 == 0) {
                    result++;
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
