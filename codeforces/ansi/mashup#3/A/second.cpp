#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char str[100005];
vector<int> indices[26];

int main() {
    scanf("%s", str);
    
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        indices[str[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < 26; i++) {
        if (indices[i].size() == 0) continue;
    }

    long long result = 0;

    for (int a = 0; a < 26; a++) {
        result = max(result, (long long) indices[a].size());

        for (int b = 0; b < 26; b++) {
            long long count = 0;

            if (indices[a].size() == 0) continue;
            if (indices[b].size() == 0) continue;

            for (int i = 0; i < indices[a].size(); i++) {
                int right = indices[b].end() - upper_bound(indices[b].begin(), indices[b].end(), indices[a][i]);

                count += (long long) right;
            }

            result = max(result, count);
        }
    }

    printf("%lld\n", result);

    return 0;
}
