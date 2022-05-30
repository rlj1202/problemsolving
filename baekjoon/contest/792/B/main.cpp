#include <cstdio>
#include <string>
#include <cstring>
#include <set>

using namespace std;

char buffer[22];

set<string> s;

int main() {
    int N;
    scanf("%d", &N);
    int result = 0;
    for (int n = 0; n < N; n++) {
        scanf("%s", buffer);
        if (strcmp(buffer, "ENTER") == 0) {
            result += s.size();
            s.clear();
        } else {
            s.insert(string(buffer));
        }
    }
    result += s.size();

    printf("%d\n", result);

    return 0;
}