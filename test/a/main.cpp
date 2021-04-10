#include <cstdio>

using namespace std;

class A {
public:
    A() {
        printf("Im in\n");
    }
    A(const A&& a) {
        this->value = a.value;
        printf("Im moved\n");
    }
    ~A() {
        printf("Im out\n");
    }

private:
    int value;
};

A test() {
    return A();
}

int main() {
    A a = test();
    printf("----------------------------------------\n");

    return 0;
}