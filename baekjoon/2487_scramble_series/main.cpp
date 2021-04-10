#include <cstdio>

using namespace std;

int arr[20004];

int parent[20004];
int amount[20004];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;

    if (amount[A] > amount[B]) {
        int tmp = A;
        A = B;
        B = tmp;
    }

    parent[A] = B;
    amount[B] += amount[A];

    return true;
}

// greater common divider
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// leaster common multiplier
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
    // 2e4
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }

    for (int n = 1; n <= N; n++) {
        parent[n] = n;
        amount[n] = 1;
    }

    for (int n = 1; n <= N; n++) {
        merge(n, arr[n]);
    }

    int result = 1;
    for (int n = 1; n <= N; n++) {
        if (n != parent[n]) continue;

        result = lcm(result, amount[n]);
    }

    printf("%d\n", result);

    return 0;
}