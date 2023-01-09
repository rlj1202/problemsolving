#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[32];
vector<int> components;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long N, K;
        scanf("%lld %lld", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%lld", arr + n);
        }

        components.clear();

        bool result = true;

        for (int n = 0; n < N; n++) {
            long long cur = arr[n];

            int i = 0;
            while (cur) {
                long long remains = cur % K;
                if (remains == 1) components.push_back(i);
                else if (remains > 1) {
                    result = false;
                    break;
                }
                cur /= K;
                i++;
            }

            if (!result) break;
        }

        sort(components.begin(), components.end());

        for (int i = 1; i < components.size(); i++) {
            if (components[i] == components[i - 1]) {
                result = false;
                break;
            }
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
