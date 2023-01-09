#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char buffer[100005][4];
pair<char*, int> strs[100005];

bool comp(const pair<char*, int> &a, const pair<char*, int> &b) {
    if (strcmp(a.first, b.first) == 0) return a.second < b.second;
    return strcmp(a.first, b.first) < 0;
}

bool compFirst(const pair<char*, int> &a, const pair<char*, int> &b) {
    return strcmp(a.first, b.first) < 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%s", buffer[n]);
            strs[n] = { buffer[n], n };
        }

        sort(strs, strs + N, comp);

        bool possible = false;

        for (int n = 0; n < N; n++) {
            char *cur = strs[n].first;
            int len = strlen(cur);
            if (cur[0] == cur[len - 1]) {
                possible = true;
                break;
            }
        }

        for (int n = 0; n < N; n++) {
            char *cur = strs[n].first;
            int len = strlen(cur);

            char target[4] = { 0, 0, 0, 0 };
            bool exist = false;

            int lower, upper;

            if (len == 2) {
                target[0] = cur[1];
                target[1] = cur[0];
                lower = lower_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                upper = upper_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                for (int i = lower; i < upper; i++) {
                    if (strs[i].second < strs[n].second) {
                        exist = true;
                        break;
                    }
                }
            } else if (len == 3) {
                target[0] = cur[2];
                target[1] = cur[1];
                lower = lower_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                upper = upper_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                for (int i = lower; i < upper; i++) {
                    if (strs[i].second < strs[n].second) {
                        exist = true;
                        break;
                    }
                }
         
                target[0] = cur[1];
                target[1] = cur[0];
                lower = lower_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                upper = upper_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                for (int i = lower; i < upper; i++) {
                    if (strs[n].second < strs[i].second) {
                        exist = true;
                        break;
                    }
                }
         
                target[0] = cur[2];
                target[1] = cur[1];
                target[2] = cur[0];
                lower = lower_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                upper = upper_bound(strs, strs + N, pair<char*, int>{ target, 0 }, compFirst) - strs;
                for (int i = lower; i < upper; i++) {
                    if (strs[i].second < strs[n].second) {
                        exist = true;
                        break;
                    }
                }
            }

            if (exist) {
                possible = true;
                break;
            }
        }

        printf("%s\n", possible ? "YES" : "NO");
    }

    return 0;
}
