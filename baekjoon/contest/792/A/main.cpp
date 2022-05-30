#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int A, B;
    scanf("%d %d", &A, &B);

    printf("%d\n", min(N, A / 2 + B));

    return 0;
}
