#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char input[202];
int len;

int group[202];
int groups;

int stack[202];
int top;

vector<string> ans;

int main() {
    scanf("%s", input);

    len = strlen(input);

    for (int i = len - 1; i >= 0; i--) {
        if (input[i] == ')') {
            stack[top++] = i;
        } else if (input[i] == '(') {
            int r = stack[--top];

            groups++;
            group[i] = groups;
            group[r] = groups;
        }
    }

    for (int i = 1; i < (1 << groups); i++) {
        char tmp[202];
        int offset = 0;
        for (int j = 0; j < len; j++) {
            if (group[j] && ((1 << (group[j] - 1)) & i)) continue;
            offset += sprintf(tmp + offset, "%c", input[j]);
        }
        tmp[offset] = 0;
        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (string test : ans) {
        printf("%s\n", test.c_str());
    }

    return 0;
}
