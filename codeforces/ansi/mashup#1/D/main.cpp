#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> primes;

int main() {
    primes.push_back(2);
    for (int i = 3; i <= sqrt(1e9); i += 2) {
        int pi;
        for (pi = 0; pi < primes.size(); pi++) {
            if (i % primes[pi]) break;
        }
        if (pi == primes.size()) primes.push_back(i);
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // max = 1e9
        scanf("%d", &N);

        bool result = false;

        if (N % 2 == 1) { // odd number
            if (N != 1) result = true;
        } else { // even number
            if (N == 2) {
                result = true;
            } else {
                int remains = N;
                int cnt = 0;
                while (remains % 2 == 0) {
                    remains /= 2;
                    cnt++;
                }

                if (remains > 1) {
                    if (cnt > 1) {
                        result = true;
                    } else {
                        bool isPrime = true;
                        for (int i = 2; i <= sqrt(remains); i++) {
                            if (remains % i == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                        // for (int prime : primes) {
                        //     if (remains != prime && remains % prime == 0) {
                        //         isPrime = false;
                        //         break;
                        //     }
                        // }
                        if (!isPrime) result = true;
                    }
                }
            }
        }

        printf("%s\n", result ? "Ashishgup" : "FastestFinger");
    }

    return 0;
}
