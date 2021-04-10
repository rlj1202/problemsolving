#include <cstdio>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    // 26, 1000
    int K, N;
    char final[30];
    char rows[1003][30];
    scanf("%d %d", &K, &N);
    scanf("%s", final);
    for (int n = 0; n < N; n++) {
        scanf("%s", rows[n]);
    }

    int upper[30];
    for (int i = 0; i < K; i++) upper[i] = i;

    int lower[30];
    for (int i = 0; i < K; i++) {
        lower[i] = final[i] - 'A';
    }

    for (int n = 0; n < N; n++) {
        char *row = rows[n];

        if (*row == '?') break;

        for (int k = 0; k < K - 1; k++) {
            if (row[k] == '-') {
                swap(upper[k], upper[k + 1]);
            }
        }
    }

    for (int n = N - 1; n >= 0; n--) {
        char *row = rows[n];

        if (*row == '?') break;

        for (int k = 0; k < K - 1; k++) {
            if (row[k] == '-') {
                swap(lower[k], lower[k + 1]);
            }
        }
    }

    bool valid = true;
    char result[30];

    for (int i = 0; i < K - 1; i++) {
        if (upper[i] == lower[i + 1] && upper[i + 1] == lower[i]) {
            result[i] = '-';
            swap(lower[i], lower[i + 1]);
        } else if (upper[i] == lower[i]) {
            result[i] = '*';
        } else {
            valid = false;
        }
    }
    result[K] = 0;

    if (!valid) {
        for (int i = 0; i < K - 1; i++) result[i] = 'x';
    }

    printf("%s\n", result);

    return 0;
}