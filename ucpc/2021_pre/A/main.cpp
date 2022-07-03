#include <cstdio>
#include <cstring>

using namespace std;

char str[3003];
char buffer[3003];

int main() {
    scanf("%s", str);

    int len = strlen(str);

    int cur = 0;
    for (int i = 0; i < len; i++) {
        cur *= 10;
        cur += str[i] - '0';

        bool valid = true;

        int j = i + 1;
        int next = cur;
        while (j < len) {
            next++;
            sprintf(buffer, "%d", next);
            int bufferlen = strlen(buffer);

            if (strncmp(str + j, buffer, bufferlen) == 0) {
                j += bufferlen;
            } else {
                valid = false;
                break;
            }
        }

        if (valid) {
            printf("%d %d\n", cur, next);
            return 0;
        }
    }

    return 0;
}
