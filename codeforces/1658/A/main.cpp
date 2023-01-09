#include <cstdio>
#include <algorithm>

using namespace std;

char str[102];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", str);

        int male = 0;
        int female = 0;

        int addedFemale = 0;

        for (int i = 0; i < N; i++) {
            if (i > 0 && i < N - 1 && str[i] == '1') {
                if (str[i - 1] == '0' && str[i + 1] == '0') {
                    addedFemale++;
                }
            }
            if (i && str[i] == '0' && str[i - 1] == '0') {
                addedFemale += 2;
            }
        }

        printf("%d\n", addedFemale);
    }

    return 0;
}
