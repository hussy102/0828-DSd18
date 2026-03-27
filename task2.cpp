#include <iostream>
using namespace std;

class employee {
public:
    virtual float calculatesalary() = 0;
}
class fulltimeemployee : public employee {
private:
    float salary;
public:
    fulltimeemployee(float s) {
        salary = s;
    }
    float calculatesalary() {
        return salary;
    }
};
class parttimeemployee : public employee {
private:
    float hours;
    float rate;
public:
    parttimeemployee(float h, float r) {
        hours = h;
        rate = r;
    }
    float calculatesalary() {
        return hours * rate;
    }
};
int main() {
    fulltimeemployee f(50000);
    parttimeemployee p(20, 500);
        cout << "fulltime employee salary: " << f.calculatesalary() << endl;
    cout << "parttime employee salary: " << p.calculatesalary() << endl;
    return 0;
}