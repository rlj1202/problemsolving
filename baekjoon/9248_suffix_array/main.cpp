#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[500005];

int group[500005 * 2];
int tgroup[500005];
int sa[500005];

int order[500005];
int lcp[500005];

int t;

bool cmp(int a, int b) {
    if (group[a] == group[b])
        return group[a + t] < group[b + t];
    return group[a] < group[b];
};

int main() {
    scanf("%s", S);

    int len = strlen(S);

    // Suffix Array
    memset(group, -1, sizeof(group));
    for (int i = 0; i < len; i++) {
        // make group using first letter of each suffix
        sa[i] = i;
        group[i] = S[i] - 'a';
    }
    t = 1;
    while (t < len) {
        sort(sa, sa + len, cmp);

        tgroup[0] = 0;
        for (int i = 1; i < len; i++) {
            if (cmp(sa[i - 1], sa[i])) {
                tgroup[sa[i]] = tgroup[sa[i - 1]] + 1;
            } else {
                tgroup[sa[i]] = tgroup[sa[i - 1]];
            }
        }
        for (int i = 0; i < len; i++) group[i] = tgroup[i];

        t <<= 1;
    }

    // Longest Common Prefix
    for (int i = 0; i < len; i++) order[sa[i]] = i;

    int cur = 0;
    for (int i = 0; i < len; i++) {
        int k = order[i];

        if (k) {
            int j = sa[k - 1];

            while (S[j + cur] == S[i + cur]) {
                cur++;
            }

            lcp[k] = cur;

            if (cur) cur--;
        }
    }

    // Print answer
    for (int i = 0; i < len; i++) printf("%d ", sa[i] + 1);
    printf("\n");
    printf("x ");
    for (int i = 1; i < len; i++) printf("%d ", lcp[i]);
    printf("\n");

    return 0;
}