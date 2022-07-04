#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

typedef long long ll;
typedef complex<double> cpx;

int bitrev(int n, int k) {
    int result = 0;

    for (int i = 0; i < k; i++) {
        result |= ((n >> i) & 1) << (k - 1 - i);
    }

    return result;
}

void fft(vector<cpx> &f, bool inverse = false) {
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

void mul(vector<cpx> &a) {
    int n = 1;
    while (n < a.size()*2) n <<= 1;

    a.resize(n);

    fft(a);

    for (int i = 0; i < n; i++) {
        a[i] = a[i]*a[i];
    }

    fft(a, true);
    for (int i = 0; i < n; i++) {
        a[i] = cpx(round(a[i].real()), round(a[i].imag()));
    }
}

vector<cpx> A;

ll cnt[500005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    A.resize(N);

    for (ll i = 1; i < N; i++) {
        A[(i*i) % N] += cpx(1, 0);
    }

    mul(A);

    ll result = 0;

    for (int i = 0; i < A.size(); i++) {
        cnt[i % N] += A[i].real();
    }
    for (ll i = 1; i < N; i++) {
        cnt[(i*i*2) % N]++;
    }

    for (ll i = 1; i < N; i++) {
        result += cnt[(i*i) % N];
    }

    cout << result / 2 << '\n';

    return 0;
}
