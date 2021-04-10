#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i : v) {
        printf("%d\n", i);
    }

    return 0;
}