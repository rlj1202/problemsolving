#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
typedef complex<double> cpx;

vector<cpx> X;
vector<cpx> Y;

void fft(vector<cpx> &f, cpx w) {
    int n = f.size();
    if (n == 1) return; // base case

    vector<cpx> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++) {
        (i % 2 ? odd : even)[i / 2] = f[i];
    }

    fft(even, w*w);
    fft(odd, w*w);

    cpx wp(1, 0);
    for (int i = 0; i < n / 2; i++) {
        f[i] = even[i] + wp * odd[i];
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
    }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    a.resize(n);
    b.resize(n);

    vector<cpx> c(n);

    cpx w(cos(2 * PI / n), sin(2 * PI / n));

    fft(a, w);
    fft(b, w);

    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    fft(c, cpx(1, 0) / w);
    for (int i = 0; i < n; i++) {
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    X.resize(N * 2);
    Y.resize(N);

    for (int n = 0; n < N; n++) {
        int x;
        cin >> x;
        X[n].real(x);
    }
    for (int n = 0; n < N; n++) {
        int y;
        cin >> y;
        Y[N - n - 1].real(y);
    }

    for (int n = 0; n < N; n++) {
        X[n + N] = X[n];
    }

    auto C = multiply(X, Y);

    double result;

    for (int i = N; i < N*2; i++) {
        result = max(result, C[i].real());
    }

    cout << (long long) result << '\n';

    return 0;
}
