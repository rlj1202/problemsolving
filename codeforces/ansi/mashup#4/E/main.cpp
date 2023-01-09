#include <cstdio>
#include <vector>

using namespace std;

vector<int> answers;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 1e9
        scanf("%d", &N);

        answers.clear();

        int s = 1;
        while (true) {
            int divisions = N / s;
            int remains = N % s;

            answers.push_back(divisions);

            if (divisions && divisions <= remains) {
                s += remains / divisions;
            }

            s++;

            if (divisions == 0) break;
        }

        printf("%d\n", answers.size());
        for (int i = 0; i < answers.size(); i++) {
            printf("%d ", answers.rbegin()[i]);
        }
        printf("\n");
    }

    return 0;
}
