#include <cstdio>

using namespace std;

int arr[100005];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    long long l = 0;
    long long r = 2e9;

    while (r - l) {
        int mid = (l + r) / 2; // delta upper bound

        for (int n = 0; n < N; n++) {
            
        }
    }

    printf("%llu\n", 0LLU);

    return 0;
}
