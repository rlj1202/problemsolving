#include <cstdio>
#include <cstring>

using namespace std;

char str[100005];
int cnt[26];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%s", str);

        bool valid = true;

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; str[i] != 0; i++) {
            int cur = str[i] - 'A';
            int next = str[i + 1] - 'A';

            cnt[cur]++;

            if (cnt[cur] % 3 == 0) {
                if (cur != next) {
                    valid = false;
                    break;
                }

                i++;
            }
        }

        printf("%s\n", valid ? "OK" : "FAKE");
    }

    return 0;
}
