#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int S, G, P, D;

char str[42];

int arr[42];

int upper(char c) {
    if (c == 'D') return D * 2;
    if (c == 'P') return D - 1;
    if (c == 'G') return P - 1;
    if (c == 'S') return G - 1;
    if (c == 'B') return S - 1;
    return 0;
}

int main() {
    scanf("%d", &N);
    scanf("%d %d %d %d", &S, &G, &P, &D);
    scanf("%s", str);

    int result = 0;

    arr[N - 1] = min(upper(str[N - 1]), D);
    result += arr[N - 1];
    for (int n = N - 2; n >= 0; n--) {
        arr[n] = min(
            upper(str[n + 1]) - arr[n + 1],
            min(upper(str[n]), D));
        
        result += arr[n];
    }

    printf("%d\n", result);

    return 0;
}
