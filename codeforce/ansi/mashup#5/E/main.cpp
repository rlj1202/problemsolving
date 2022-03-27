#include <cstdio>

using namespace std;

int arr[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int c = 0;
        bool prev;
        int transition = 0;
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);

            bool match = n == arr[n];
            if (!match) c++;

            if (n > 1) {
                if (prev == false && match == true) {
                    transition++;
                }
            }
            prev = match;
        }
        if (prev == false) transition++;

        int result = 0;

        if (c == 0) {
            result = 0;
        } else {
            if (transition == 1) {
                result = 1;
            } else {
                result = 2;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
