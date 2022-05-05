#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char features[2003][32];
char* sorted_features[2003];

bool feature_sort(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

void valid_card(const char* a, const char* b, char* result) {
    int i;
    for (i = 0; a[i] != 0; i++) {
        if (a[i] == b[i]) {
            result[i] = a[i];
        } else {
            for (int j = 0; j < 3; j++) {
                if (a[i] != "SET"[j] && b[i] != "SET"[j]) result[i] = "SET"[j];
            }
        }
    }
    result[i] = '\0';
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int n = 0; n < N; n++) {
        scanf("%s", features[n]);
        sorted_features[n] = features[n];
    }

    sort(sorted_features, sorted_features + N, feature_sort);

    int answer = 0;

    for (int n = 0; n < N; n++) {
        for (int m = n + 1; m < N; m++) {
            char target[32];
            valid_card(sorted_features[n], sorted_features[m], target);

            int result = lower_bound(
                sorted_features + m + 1, sorted_features + N,
                target, feature_sort) - sorted_features;

            if (result != N && strcmp(sorted_features[result], target) == 0) {
                answer++;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
