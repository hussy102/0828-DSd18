#include <iostream>
#include <stack>
using namespace std;

class parkinglot {
private:
    stack<string> mycarstack;
    int capacity = 8;
public:
    void parkcar(string carnumber) {
        if (mycarstack.size() == capacity) {
            cout << "parking full";
            return;
        }
        mycarstack.push(carnumber);
        cout << "car " << carnumber << " parked";
    }
    void removecar(string carnumber) {
        if (mycarstack.empty()) {
            cout << "parking empty";
            return;
        }
        stack<string> tempstack;
        bool found = false;
        while (!mycarstack.empty()) {
            if (mycarstack.top() == carnumber) {
                mycarstack.pop();
                cout << "car " << carnumber << " removed";
                found = true;
                break;
            }
            tempstack.push(mycarstack.top());
            mycarstack.pop();
        }
        while (!tempstack.empty()) {
            mycarstack.push(tempstack.top());
            tempstack.pop();
        }
        if (!found) {
            cout << "car not found";
        }
    }
    void displaycars() {
        if (mycarstack.empty()) {
            cout << "no cars";
            return;
        }
        stack<string> temp = mycarstack;
        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
    }
    void totalcars() {
        cout << mycarstack.size() << endl;
    }
    void searchcar(string carnumber) {
        stack<string> temp = mycarstack;
        bool found = false;
        while (!temp.empty()) {
            if (temp.top() == carnumber) {
                found = true;
                break;
            }
            temp.pop();
        }
        if (found)
            cout << "found";
        else
            cout << "not found";
    }
};
int main() {
    parkinglot p;
        p.parkcar("abc123");
    p.parkcar("abc786");
    p.parkcar("hussy000");
        p.displaycars();
    p.totalcars();
        p.searchcar("abc786");
        p.removecar("abc786");
        p.displaycars();
        return 0;
}