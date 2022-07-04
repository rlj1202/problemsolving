#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

const int PRIME_MAX = 1e6;

int bitrev(int n, int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        result |= ((n >> i) & 1) << (k - 1 - i);
    }

    return result;
}

void fft(vector<cpx> &f, bool inverse) {
    int n = f.size();

    int p = 0;
    for (int i = n; i > 1; i >>= 1) p++;

    for (int i = 0; i < n; i++) {
        int rev = bitrev(i, p);
        if (i < rev) swap(f[i], f[rev]);
    }

    for (int i = 2; i <= n; i <<= 1) {
        cpx w(cos(2*PI/i), sin(2*PI/i * (inverse ? -1 : 1)));

        for (int j = 0; j < n; j += i) {
            cpx wp(1, 0);

            for (int k = 0; k < i / 2; k++) {
                cpx even = f[j + k];
                cpx odd = f[j + k + i / 2];

                f[j + k] = even + wp * odd;
                f[j + k + i / 2] = even - wp * odd;

                wp *= w;
            }
        }
    }

    if (inverse) {
        for (int i = 0; i < n; i++) {
            f[i] /= cpx(n, 0);
        }
    }
}

vector<cpx> mul(vector<cpx> a, vector<cpx> b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);

    vector<cpx> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    fft(c, true);

    for (int i = 0; i < n; i++) {
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

bool not_prime[1000006];

vector<cpx> A;
vector<cpx> B;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for (int i = 2; i < PRIME_MAX; i++) {
        if (not_prime[i]) continue;

        for (int j = 2; i*j < PRIME_MAX; j++) {
            not_prime[i*j] = true;
        }
    }

    A.resize(PRIME_MAX);
    B.resize(PRIME_MAX);
    
    for (int i = 2; i < PRIME_MAX; i++) {
        if (not_prime[i]) continue;

        A[i] = cpx(1, 0);
        if (i * 2 < PRIME_MAX) B[i * 2] = cpx(1, 0);
    }

    vector<cpx> C = mul(A, B);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        cout << C[N].real() << '\n';
    }

    return 0;
}
