#include <cstdio>
#include <vector>

using namespace std;

char str[200005];
int groups[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", str);

        vector<int> endWith[2];

        int group = 0;
        for (int n = 0; n < N; n++) {
            int digit = str[n] - '0';

            if (endWith[!digit].empty()) {
                group++;

                endWith[digit].push_back(group);
                groups[n] = group;
            } else {
                int cur_group = endWith[!digit].back();
                endWith[!digit].pop_back();
                groups[n] = cur_group;

                endWith[digit].push_back(cur_group);
            }
        }

        printf("%d\n", group);
        for (int n = 0; n < N; n++) {
            printf("%d ", groups[n]);
        }
        printf("\n");
    }

    return 0;
}
