#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    double x;
    double bottom, top;
    bool left;
    int id;

    bool operator< (const node &o) const {
        if (x == o.x) {
            if (bottom == o.bottom) return top < o.top;
            return bottom < o.bottom;
        }
        return x < o.x;
    }
};

node arr[62];

vector<node> lines;

int main() {
    // 30
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        double x, y, w, h;
        scanf("%lf %lf %lf %lf", &x, &y, &w, &h);
        arr[n * 2] = {x, y, y + h, true, n};
        arr[n * 2 + 1] = {x + w, y, y + h, false, n};
    }

    sort(arr, arr + N*2);

    double result = 0;

    double prevX = arr[0].x;
    for (int i = 0; i < N*2; i++) {
        node cur = arr[i];

        if (!lines.empty()) {
            double width = cur.x - prevX;
            double heightSum = lines[0].top - lines[0].bottom;

            double min_height = lines[0].bottom;
            double max_height = lines[0].top;

            for (node line : lines) {
                if (line.bottom >= max_height) {
                    min_height = line.bottom;
                    max_height = line.top;
                    heightSum += line.top - line.bottom;
                } else if (line.top > max_height) {
                    heightSum += line.top - max_height;
                    max_height = line.top;
                }
            }

            result += width * heightSum;
            // printf("\t %.2lf \tx %.2lf \t= %.2f \t, sum = %.2f\n",
            //     width, heightSum, width * heightSum, result);
        }

        prevX = cur.x;

        if (cur.left) {
            node tmp = cur;
            tmp.x = 0;
            lines.push_back(tmp);
            sort(lines.begin(), lines.end());
        } else {
            for (auto it = lines.begin(); it != lines.end(); it++) {
                if (it->id == cur.id) {
                    lines.erase(it);
                    break;
                }
            }
        }
    }

    if (((int) (result * 100)) % 100 == 0) {
        printf("%d\n", (int) result);
    } else {
        printf("%.2lf\n", result);
    }

    return 0;
}