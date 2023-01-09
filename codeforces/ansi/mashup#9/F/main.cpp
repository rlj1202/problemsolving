#include <cstdio>

using namespace std;

char str[1 << 18];
int tree[1 << 18];

int main() {
    int K;
    scanf("%d", &K);
    scanf("%s", str);

    int len = (1 << K) - 1;
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    for (int i = len - 1; i >= 0; i--) {
        int child = i * 2 + 1;

        char cur = str[i];

        if (child + 1 < len) {
            if (cur == '1') tree[i] = tree[child];
            if (cur == '0') tree[i] = tree[child + 1];
            if (cur == '?') tree[i] = tree[child] + tree[child + 1];
        } else {
            if (cur == '1') tree[i] = 1;
            if (cur == '0') tree[i] = 1;
            if (cur == '?') tree[i] = 2;
        }
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int P; char C;
        scanf("%d %c", &P, &C);

        P--;
        P = len - P - 1;

        str[P] = C;

        int parent = P;
        int child = parent * 2 + 1;
        while (true) {
            char cur = str[parent];

            if (child + 1 < len) {
                if (cur == '1') tree[parent] = tree[child];
                if (cur == '0') tree[parent] = tree[child + 1];
                if (cur == '?') tree[parent] = tree[child] + tree[child + 1];
            } else {
                if (cur == '1') tree[parent] = 1;
                if (cur == '0') tree[parent] = 1;
                if (cur == '?') tree[parent] = 2;
            }

            if (parent == 0) break;

            parent = (parent - 1) / 2;
            child = parent * 2 + 1;
        }

        printf("%d\n", tree[0]);
    }

    return 0;
}
