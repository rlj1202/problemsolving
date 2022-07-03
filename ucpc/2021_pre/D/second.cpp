#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char str[300005];
int arr[300005];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", str);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    vector<int> new_list;

    int cur_max = arr[0];
    for (int n = 1; n < N; n++) {
        if (str[n - 1] == str[n]) {
            cur_max = max(cur_max, arr[n]);
        } else {
            new_list.push_back(cur_max);
            cur_max = arr[n];
        }
    }
    new_list.push_back(cur_max);

    long long result = 0;

    if (new_list.size() <= 2) {
        printf("0\n");
        return 0;
    }

    sort(new_list.begin() + 1, new_list.end() - 1);

    for (int n = 0; n < (new_list.size() - 1) / 2; n++) {
        result += new_list.rbegin()[1 + n];
    }

    printf("%lld\n", result);

    return 0;
}
