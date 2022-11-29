#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cpd;

const double PI = acos(-1);

/**
 * Fast Fourier Transform
 * The given vector v must have length of power of 2.
 */
void fft(vector<cpd> &v, cpd twd) {
    int n = v.size();

    if (n == 1) return;

    vector<cpd> v_even(n >> 1);
    vector<cpd> v_odd(n >> 1);

    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            v_even[i >> 1] = v[i];
        } else {
            v_odd[i >> 1] = v[i];
        }
    }

    fft(v_even, twd * twd);
    fft(v_odd, twd * twd);

    cpd twd_k(1, 0);
    for (int i = 0; i < n / 2; i++) {
        v[i] = v_even[i] + twd_k * v_odd[i];
        v[i + n / 2] = v_even[i] - twd_k * v_odd[i];
        twd_k *= twd;
    }

    return ;
}

vector<int> mul(const vector<int> &a, const vector<int> &b) {
    vector<cpd> a_fft(a.begin(), a.end());
    vector<cpd> b_fft(b.begin(), b.end());

    int n = 1;
    while (n < (int) max(a.size(), b.size())) n <<= 1;
    n <<= 1;

    a_fft.resize(n);
    b_fft.resize(n);

    cpd twd(cos(2*PI/n), -sin(2*PI/n));
    fft(a_fft, twd);
    fft(b_fft, twd);

    for (int i = 0; i < n; i++) a_fft[i] *= b_fft[i];

    fft(a_fft, conj(twd));

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = round(a_fft[i].real());
        result[i] /= n;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> a = {2, 1};
    vector<int> b = {3, 1};

    vector<int> c = mul(a, b);

    for (int i : c) cout << i << ' ';
    cout << '\n';

    return 0;
}
