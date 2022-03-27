#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

int main() {
    int N;
    scanf("%d", &N);

    long long count = 0;

    int first;
    scanf("%d", &first);
    m[first] = 0;
    printf("0\n");

    for (int n = 0; n < N - 1; n++) {
        int value;
        scanf("%d", &value);

        m[value] = 0;
        auto it = m.find(value);

        int leftVal = 0;
        int rightVal = 0;

        if (it != m.begin()) {
            auto left = it;
            left--;
            leftVal = left->second;
        }

        auto right = it;
        right++;
        if (right != m.end()) {
            rightVal = right->second;
        }

        m[value] = max(leftVal, rightVal) + 1;

        count += m[value];

        printf("%lld\n", count);
    }

    return 0;
}
