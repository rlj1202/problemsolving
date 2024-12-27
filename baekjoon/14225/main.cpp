#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int arr[22];
bool possible[100005 * 20];

void dfs(int i, int prev) {
    int cur = prev + arr[i];

    possible[cur] = true;

    for (int j = i + 1; j < N; j++) {
        dfs(j, cur);
    }
}

int main() {
    scanf("%d", &N);

    int total = 0;
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
        total += arr[n];
    }

    for (int n = 0; n < N; n++) {
        dfs(n, 0);
    }

    int answer = 0;

    for (int n = 1; n <= total + 1; n++) {
        if (!possible[n]) {
            answer = n;
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}