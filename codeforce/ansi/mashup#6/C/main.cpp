#include <cstdio>
#include <cstring>

using namespace std;

const char TARGET[8] = "abacaba";

char str[52];
char temp[52];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 50
        scanf("%d", &N);
        scanf("%s", str);

        bool result = false;

        for (int n = 0; n < N - 7 + 1; n++) {
            bool match = true;

            for (int i = 0; i < 7; i++) {
                if (str[n + i] != '?' && str[n + i] != TARGET[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                for (int i = 0; i < n; i++) {
                    temp[i] = str[i] == '?' ? 'z' : str[i];
                }
                for (int i = 0; i < 7; i++) {
                    temp[n + i] = TARGET[i];
                }
                for (int i = n + 7; i < N; i++) {
                    temp[i] = str[i] == '?' ? 'z' : str[i];
                }
                temp[N] = '\0';

                int count = 0;
                for (int i = 0; i < N - 7 + 1; i++) {
                    if (strncmp(TARGET, temp + i, 7) == 0) count++;
                }

                if (count == 1) {
                    result = true;
                    break;
                }
            }
        }

        printf("%s\n", result ? "Yes" : "No");
        if (result) printf("%s\n", temp);
    }

    return 0;
}
