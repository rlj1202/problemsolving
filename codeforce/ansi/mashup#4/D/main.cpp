#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char targets[][6] = { "twone", "one", "two" };
int lens[] = { 5, 3, 3 };
int offsets[] = { 2, 1, 1 };

char str[200005];
vector<int> answers;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%s", str);

        answers.clear();
        for (int i = 0; str[i] != 0;) {
            int step = 1;
            for (int j = 0; j < 3; j++) {
                if (strncmp(targets[j], str + i, lens[j]) == 0) {
                    answers.push_back(offsets[j] + i);
                    step = lens[j];
                    break;
                }
            }

            i += step;
        }

        printf("%d\n", (int) answers.size());
        for (int i : answers) {
            printf("%d ", i + 1);
        }
        printf("\n");
    }

    return 0;
}
