#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ceilings;
vector<int> floors;

int get_obstacles(vector<int> &v, int height) {
    int idx = lower_bound(v.begin(), v.end(), height) - v.begin();
    return v.size() - idx;
}

int main() {
    int N, H;
    scanf("%d %d", &N, &H);
    for (int n = 0; n < N; n++) {
        int height;
        scanf("%d", &height);

        if (n % 2 == 0) {
            floors.push_back(height);
        } else {
            ceilings.push_back(height);
        }
    }

    sort(floors.begin(), floors.end());
    sort(ceilings.begin(), ceilings.end());

    int result = 0x3f3f3f3f;
    int count = 0;

    for (int h = 1; h <= H; h++) {
        int obstacles = get_obstacles(floors, h) +
                            get_obstacles(ceilings, H - h + 1);

        if (result > obstacles) {
            result = obstacles;
            count = 1;
        } else if (result == obstacles) {
            count++;
        }
    }

    printf("%d %d\n", result, count);

    return 0;
}