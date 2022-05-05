#include <cstdio>
#include <cstring>

using namespace std;

char str[12];

bool check(char* s) {
    for (int i = 1; s[i] != 0; i++)
        if (s[i - 1] == s[i]) return false;

    return true;
}

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int perm(char* s) {
    if (*s == 0) {
        return check(str);
    }

    int result = 0;
    bool used[26];
    memset(used, 0, sizeof(used));

    for (int i = 0; s[i] != 0; i++) {
        if (used[s[i] - 'a']) continue;

        used[s[i] - 'a'] = true;

        swap(s, s + i);

        result += perm(s + 1);

        swap(s, s + i);
    }

    return result;
}

int main() {
    scanf("%s", str);

    printf("%d\n", perm(str));

    return 0;
}
