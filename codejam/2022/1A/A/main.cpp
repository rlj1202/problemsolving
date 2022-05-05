#include <cstdio>

using namespace std;

char str[102];
char result[202];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%s", str);

        int j = 0;

        char prev = str[0];
        int count = 1;
        result[j++] = str[0];
        for (int i = 1; str[i]; i++) {
            if (str[i - 1] > str[i]) {
                prev = str[i];
                count = 1;
            } else if (str[i - 1] < str[i]) {
                while (count--) {
                    result[j++] = str[i - 1];
                }
                prev = str[i];
                count = 1;
            } else if (str[i - 1] == str[i]) {
                count++;
            }

            result[j++] = str[i];
        }
        result[j++] = 0;

        printf("Case #%d: %s\n", t, result);
    }

    return 0;
}
