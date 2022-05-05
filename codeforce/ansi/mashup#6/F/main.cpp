#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%s", str);

        int len = strlen(str);

        int minVal = len;

        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                int cur = a;
                int next = b;

                int count = 0;

                for (int i = 0; i < len; i++) {
                    int digit = str[i] - '0';

                    if (digit == cur) {
                        count++;

                        int temp = cur;
                        cur = next;
                        next = temp;
                    }
                }

                if (a != b) {
                    count -= count % 2;
                }

                minVal = min(minVal, len - count);
            }
        }

        printf("%d\n", minVal);
    }

    return 0;
}
