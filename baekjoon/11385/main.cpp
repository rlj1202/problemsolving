#include <bits/stdc++.h>

using namespace std;

const long double PI = acos(-1);

typedef long long ll;
typedef complex<long double> cpx;
typedef vector<cpx> poly;

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
        cpx w = polar(1.0L, 2*PI/i * (inv ? -1 : 1));

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
            f[i] /= n;
        }
    }
}

poly mul(poly a, poly b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    a.resize(n);
    b.resize(n);

    fft(a);
    fft(b);

    poly c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    fft(c, true);
    for (int i = 0; i < n; i++) {
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    poly A1(N+1), A2(N+1);
    poly B1(M+1), B2(M+1);

    for (int i = 0; i < N/2; i++) {
        int value;
        cin >> value;
        A1[i] = value;
    }
    for (int i = N/2; i < N+1; i++) {
        int value;
        cin >> value;
        A2[i] = value;
    }
    for (int i = 0; i < M/2; i++) {
        int value;
        cin >> value;
        B1[i] = value;
    }
    for (int i = M/2; i < M+1; i++) {
        int value;
        cin >> value;
        B2[i] = value;
    }

    // C = A * B
    // C = (A1 + A2)(B1 + B2)
    // C = A1*B1 + A1*B2 + A2*B1 + A2*B2

    vector<ll> coeff(N+M+2);
    poly C;

    C = mul(A1, B1); for (int i = 0; i < N+M+2; i++) coeff[i] += (ll) C[i].real();
    C = mul(A1, B2); for (int i = 0; i < N+M+2; i++) coeff[i] += (ll) C[i].real();
    C = mul(A2, B1); for (int i = 0; i < N+M+2; i++) coeff[i] += (ll) C[i].real();
    C = mul(A2, B2); for (int i = 0; i < N+M+2; i++) coeff[i] += (ll) C[i].real();

    ll result = 0;
    for (int i = 0; i < N+M+2; i++) {
        result ^= coeff[i];
    }

    cout << result << '\n';

    return 0;
}
