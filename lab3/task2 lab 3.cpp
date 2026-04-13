#include <iostream>
using namespace std;

template <typename t>
class abstractstack {
public:
    virtual void push(t value) = 0;
    virtual t pop() = 0;
    virtual t top() const = 0;
    virtual bool isempty() const = 0;
    virtual bool isfull() const = 0;
    virtual ~abstractstack() {}
};
template <typename t>
class mystack : public abstractstack<t> {
private:
    t* arr;
    t* minarr;
    int maxsize;
    int topindex;
    int mintop;
public:
    mystack(int size) {
        maxsize = size;
        arr = new t[maxsize];
        minarr = new t[maxsize];
        topindex = -1;
        mintop = -1;
    }
    ~mystack() {
        delete[] arr;
        delete[] minarr;
    }
    void push(t value) override {
        if (isfull()) {
            cout << "overflow" << endl;
            return;
        }
        arr[++topindex] = value;
        if (mintop == -1 || value <= minarr[mintop]) {
            minarr[++mintop] = value;
        }
    }
    t pop() override {
        if (isempty()) {
            cout << "stack not full" << endl;
            return t();
        }
        t val = arr[topindex--];
        if (val == minarr[mintop]) {
            mintop--;
        }

        return val;
    }
    t top() const override {
        if (isempty()) {
            cout << "empty" << endl;
            return t();
        }
        return arr[topindex];
    }
    bool isempty() const override {
        return (topindex == -1);
    }
    bool isfull() const override {
        return (topindex == maxsize - 1);
    }
    t getmin() const {
        if (isempty()) {
            cout << "stack  empty" << endl;
            return t();
        }
        return minarr[mintop];
    }
    void display() const {
        if (isempty()) {
            cout << "stack empty" << endl;
            return;
        }
        cout << "stack element:" << endl;
        for (int i = topindex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};
int main() {
    int size;
    cout << "enter stack size: ";
   cin >> size;
    mystack<int> s(size);
    int choice, value;
    do {
        cout << "1. push element" << endl;
        cout << "2. pop element" << endl;
        cout << "3. show top element" << endl;
        cout << "4. check if stack is empty" << endl;
        cout << "5. check if stack is full" << endl;
        cout << "6. display stack elements" << endl;
        cout << "7. show minimum element" << endl;
        cout << "8. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "popped: " << s.pop() << endl;
            break;
        case 3:
            cout << "top element: " << s.top() << endl;
            break;
        case 4:
            if (s.isempty())
                cout << "stack is empty" << endl;
            else
                cout << "stack is not empty" << endl;
            break;
        case 5:
            if (s.isfull())
                cout << "stack is full" << endl;
            else
                cout << "stack is not full" << endl;
            break;
        case 6:
            s.display();
            break;
        case 7:
            cout << "minimum element: " << s.getmin() << endl;
            break;
                    case 8:
            cout << "exiting" << endl;
            break;
                    default:
            cout << "invalid" << endl;
        }
            } while (choice != 8);
        return 0;
}
