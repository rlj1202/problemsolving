#include <cstdio>

using namespace std;

const long long INF = 1e9;

int main() {
    long long X, Y;
    scanf("%lld %lld", &X, &Y);

    long long Z = (Y * 100) / X;

    long long l = 1;
    long long r = INF;

    while (r - l) {
        long long mid = (l + r) / 2;

        long long newZ = (Y + mid) * 100 / (X + mid);

        if (newZ > Z) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    long long newZ = (Y + l) * 100 / (X + l);

    printf("%lld\n", newZ > Z ? l : -1);

    return 0;
}
