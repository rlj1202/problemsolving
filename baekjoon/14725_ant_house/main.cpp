#include <cstdio>
#include <map>
#include <string>

using namespace std;

struct node {
    map<string, node> childs;

    void make(string *path, int cur, int len) {
        if (cur >= len) return;

        if (!childs.count(path[cur])) {
            childs[path[cur]] = node{};
        }

        childs[path[cur]].make(path, cur + 1, len);
    }

    void print(int level = 0) {
        for (auto key = childs.begin(); key != childs.end(); key++) {
            for (int i = 0; i < level; i++) printf("--");
            printf("%s\n", key->first.c_str());
            key->second.print(level + 1);
        }
    }
};

node top;

char name[20];
string path[20];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int K;
        scanf("%d", &K);
        for (int k = 0; k < K; k++) {
            scanf("%s", name);
            path[k] = string(name);
        }
        top.make(path, 0, K);
    }

    top.print();

    return 0;
}