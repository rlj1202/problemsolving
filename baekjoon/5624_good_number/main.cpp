#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[5003];

struct add {
    int sum, index;

    bool operator < (const add &o) const {
        if (sum == o.sum) return index < o.index;
        return sum < o.sum;
    }
};

vector<add> pairs;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        // -100,000 ~ 100,000
        scanf("%d", arr + n);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            pairs.push_back({ arr[i] + arr[j], i });
        }
    }
    sort(pairs.begin(), pairs.end());

    int result = 0;

    // O(N^2 * log N)
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            int k = arr[i] - arr[j];

            int l = 0;
            int r = pairs.size() - 1;
            int mid = (l + r) / 2;

            while (l < r) {
                add &cur = pairs[mid];

                if (k <= cur.sum) {
                    r = mid;
                } else { // cur.sum < k
                    l = mid + 1;
                }

                mid = (l + r) / 2;
            }

            if (pairs[mid].sum == k && pairs[mid].index < i) { // query k in range [0, i)
                result++;
                break;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}