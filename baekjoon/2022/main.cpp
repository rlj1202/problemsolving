#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    double X, Y, C;
    scanf("%lf %lf %lf", &X, &Y, &C);

    double l = 0;
    double r = min(X, Y);
    double mid = (l + r) / 2.0;

    while (r - l > 0.0001) {
        double height1 = sqrt(X*X - mid*mid);
        double height2 = sqrt(Y*Y - mid*mid);

        double c = (height1 * height2) / (height1 + height2);

        if (c < C) {
            r = mid;
        } else {
            l = mid;
        }

        mid = (l + r) / 2.0;
    }

    printf("%.3f\n", mid);

    return 0;
}
