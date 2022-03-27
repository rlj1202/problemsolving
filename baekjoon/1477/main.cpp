#include <cstdio>

using namespace std;

int arr[52];

int main() {
    int N, M, L; // 50, 100, 1000
    scanf("%d %d %d", &N, &M, &L);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    printf("%d\n", 0);

    return 0;
}
