#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int arr[2003];

set<int> left;
set<int> right;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    int result = N;

    for (int i = 0; i < N; i++) {
        right.clear();

        int max_r;
        for (max_r = N; max_r > i; max_r--) {
            if (left.count(arr[max_r - 1]) || right.count(arr[max_r - 1])) {
                break;
            }

            right.insert(arr[max_r - 1]);
        }

        result = min(result, max_r - i);

        if (!left.count(arr[i])) {
            left.insert(arr[i]);
        } else {
            break;
        }
    }

    printf("%d\n", result);

    return 0;
}
