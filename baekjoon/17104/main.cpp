#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

typedef complex<double> cpx;
typedef vector<cpx> poly;

const int PRIME_MAX = 1000006;
bool not_prime[PRIME_MAX];

int bitrev(int n, int k) {
    int r = 0;
    for (int i = 0; i < k; i++) r |= ((n >> i) & 1) << (k - 1 - i);
    return r;
}

void fft(poly &f, bool inv = false) {
    int n = f.size();

    int p = 0;
    for (int i = n; i > 1; i >>= 1) p++;

    for (int i = 0; i < n; i++) {
        int rev = bitrev(i, p);
        if (i < rev) swap(f[i], f[rev]);
    }

    for (int i = 2; i <= n; i <<= 1) {
        cpx w(cos(2*PI/i), sin(2*PI/i * (inv ? -1 : 1)));

        for (int j = 0; j < n; j += i) {
            cpx wp(1, 0);

            for (int k = 0; k < i / 2; k++) {
                cpx even = f[j + k];
                cpx odd = f[j + k + i/2];

                f[j + k] = even + wp * odd;
                f[j + k + i/2] = even - wp * odd;
                
                wp *= w;
            }
        }
    }

    if (inv) {
        for (int i = 0; i < n; i++) {
            f[i] /= cpx(n, 0);
        }
    }
}

poly mul(poly a) {
    int n = 1;
    while (n < a.size() * 2) n <<= 1;

    a.resize(n);

    fft(a);

    poly c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * a[i];
    }

    fft(c, true);
    for (int i = 0; i < n; i++) {
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 2; i < PRIME_MAX; i++) {
        if (not_prime[i]) continue;

        for (int j = 2; i*j < PRIME_MAX; j++) {
            not_prime[i*j] = true;
        }
    }

    poly A(PRIME_MAX / 2);

    for (int i = 3; i < PRIME_MAX; i += 2) {
        if (not_prime[i]) continue;

        A[i / 2] = 1;
    }

    poly C = mul(A);

    int T;
    cin >> T;

    while (T--) {
        // N = p + q, N is even
        // N = (2u+1) + (2v+1)
        // N = 2(u+v) + 2
        // N/2 - 1 = u + v
        int N;
        cin >> N;

        if (N == 4) {
            cout << 1 << '\n';
        } else {
            int result = C[N/2 - 1].real();

            if (!not_prime[N / 2]) result++;

            cout << result / 2 << '\n';
        }

    }

    return 0;
}
