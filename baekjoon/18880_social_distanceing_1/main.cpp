#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char arr[100005];
vector<int> zeros;

int main() {
    int N;
    scanf("%d %s", &N, arr);

    int count = 0;
    for (int n = 0; n < N + 1; n++) {
        if (arr[n] == '0') {
            count++;
        } else {
            zeros.push_back(count);
            count = 0;
        }
    }

    int result = 0;

    int l = 0;
    int r = N - 1;
    int mid = (l + r + 1) / 2;

    while (l < r) {
        int cows = 0;
        bool valid = true;

        for (int i = 0; i < zeros.size(); i++) {
            int zero = zeros[i];

            if (i == 0 || i == zeros.size() - 1) {
                if (zero >= mid) {
                    cows++;
                }
            } else {
                if ((zero + 1) / 2 >= mid) {
                    cows++;
                } else if (zero + 1 < mid) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid && cows >= 2) {
            l = mid;
        } else {
            r = mid - 1;
        }

        mid = (l + r + 1) / 2;
    }

    result = max(result, mid);

    l = 0;
    r = N - 1;
    mid = (l + r + 1) / 2;

    while (l < r) {
        int cows = 0;
        bool valid = true;

        for (int i = 0; i < zeros.size(); i++) {
            int zero = zeros[i];

            if (zeros.size() == 1) {
                if (zero >= mid) {
                    cows++;
                }
            } else if (i == 0 || i == zeros.size() - 1) {
                if (zero / 2 >= mid) {
                    cows++;
                }
            } else {
                if ((zero + 1) / 3 >= mid) {
                    cows++;
                } else if (zero + 1 < mid) {
                    valid = false;
                    break;
                }
            }
        }

        if (cows && valid) {
            l = mid;
        } else {
            r = mid - 1;
        }

        mid = (l + r + 1) / 2;
    }

    result = max(result, mid);

    printf("%d\n", result);
    
    return 0;
}