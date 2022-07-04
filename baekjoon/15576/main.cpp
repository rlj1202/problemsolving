#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

typedef complex<double> cpx;

vector<cpx> A;
vector<cpx> B;

void fft(vector<cpx> &f, cpx w) {
    int n = f.size();
    if (n == 1) return;

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

vector<cpx> mul(vector<cpx> a, vector<cpx> b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    a.resize(n);
    b.resize(n);

    cpx w(cos(2*PI/n), sin(2*PI/n));

    fft(a, w);
    fft(b, w);

    vector<cpx> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    fft(c, cpx(1, 0) / w);

    for (auto &i : c) {
        i /= cpx(n, 0);
        i = cpx(round(i.real()), round(i.imag()));
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string Astr, Bstr;
    cin >> Astr >> Bstr;

    for (int i = 0; i < Astr.size(); i++) {
        int digit = Astr[Astr.size() - 1 - i] - '0';
        A.push_back(cpx(digit, 0));
    }
    for (int i = 0; i < Bstr.size(); i++) {
        int digit = Bstr[Bstr.size() - 1 - i] - '0';
        B.push_back(cpx(digit, 0));
    }

    vector<cpx> C = mul(A, B);

    for (int i = 0; i < C.size(); i++) {
        int carry = (int) C[i].real() / 10;
        int digit = (int) C[i].real() % 10;

        if (carry && i + 1 < C.size()) {
            C[i + 1] += cpx(carry, 0);
        } else if (carry) {
            C.push_back(cpx(carry, 0));
        }

        C[i].real(digit);
    }

    int i = 0;
    while ((int) C.rbegin()[i].real() == 0 && i < C.size()) i++;
    if (i == C.size()) cout << 0;
    while (i < C.size()) cout << C.rbegin()[i++].real();
    cout << '\n';

    return 0;
}
