#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int E, S, M;

    scanf("%d %d %d", &E, &S, &M);

    int e = 1, s = 1, m = 1;
    int answer = 1;

    while (E != e || S != s || M != m) {
        e++;
        s++;
        m++;

        if (e > 15)
            e = 1;
        if (s > 28)
            s = 1;
        if (m > 19)
            m = 1;

        answer++;
    }

    printf("%d\n", answer);

    return 0;
}