#include <cstdio>

using namespace std;

int stack[500005];
int count[500005];
int top;

int main() {
    int N;
    scanf("%d", &N);

    long long result = 0;

    for (int n = 0; n < N; n++) {
        int height;
        scanf("%d", &height);

        while (top && stack[top - 1] < height) {
            result += count[top - 1];
            top--;
        }

        if (top && stack[top - 1] == height) {
            result += count[top - 1];
            if (top > 1) result++;

            count[top - 1]++;
        } else {
            if (top) result++;

            stack[top] = height;
            count[top++] = 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}