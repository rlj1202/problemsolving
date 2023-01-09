#include <cstdio>
#include <cmath>

using namespace std;

long long arr[5003];
long long m[5003];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%lld", arr + n);
    }

    long long result = 0x3f3f3f3f3f3f3f3f;

    for (int n = 0; n < N; n++) {
        m[n] = 0;

        long long m_sum = 0;

        for (int i = n + 1; i < N; i++) {
            long long prev = m[i - 1] * arr[i - 1];
            long long next_m = (long long) floor(prev / (double) arr[i]) + 1;

            m[i] = next_m;

            m_sum += abs(m[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            long long next = m[i + 1] * arr[i + 1];
            long long prev_m = (long long) ceil(next / (double) arr[i]) - 1;

            m[i] = prev_m;

            m_sum += abs(m[i]);
        }

        if (result > m_sum) {
            result = m_sum;
        }
    }

    printf("%lld\n", result);

    return 0;
}
