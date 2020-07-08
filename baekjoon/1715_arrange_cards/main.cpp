#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int deck_size;
        scanf("%d", &deck_size);
        q.push(deck_size);
    }

    int result = 0;

    while (q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();

        result += a + b;

        q.push(a + b);
    }

    printf("%d\n", result);

    return 0;
}