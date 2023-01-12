#include <bits/stdc++.h>

using namespace std;

int primes[300005];
int plen;

int legs[300005];

vector<int> spiders[30004];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    primes[plen++] = 2;
    for (int i = 3; i <= 300005 / 2; i += 2) {
        bool isPrime = true;
        for (int pi = 0; pi < plen; pi++) {
            if (i % primes[pi] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes[plen++] = i;
        }
    }

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> legs[n];

        int cur = legs[n];

        for (int pi = 0; pi < plen; pi++) {
            if (cur % primes[pi] != 0) continue;
        }
    }

    int S, T;
    cin >> S >> T;


    bool possible = true;

    if (possible) {
        cout << 0 << '\n';
        for (int i = 0; i < 10; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
