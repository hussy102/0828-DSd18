#include <iostream>
using namespace std;

class shape {
public:
    virtual float area() = 0;
};
class circle : public shape {
private:
    float radius;
public:
    circle(float r) {
        radius = r;
    }
    float area() {
        return 3.1416 * radius * radius;
    }
};
class rectangle : public shape {
private:
    float length;
    float width;
public:
    rectangle(float l, float w) {
        length = l;
        width = w;
    }
    float area() {
        return length * width;
    }
};
int main() {
    circle c(5);
    rectangle r(4, 6);
    cout << "area circle: " << c.area() << endl;
    cout << "area of rectangle: " << r.area() << endl;
    return 0;
}