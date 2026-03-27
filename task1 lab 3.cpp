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
    int maxsize;
    int topindex;
public:
    mystack(int size) {
        maxsize = size;
        arr = new t[maxsize];
        topindex = -1;
    }
    ~mystack() {
        delete[] arr;
    }
    void push(t value) override {
        if (isfull()) {
            cout << "overflow" << endl;
            return;
        }
        arr[++topindex] = value;
    }
    t pop() override {
        if (isempty()) {
            cout << "stack not full" << endl;
            return t();
        }
        return arr[topindex--];
    }
    t top() const override {
        if (isempty()) {
            cout << " empty" << endl;
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
    void display() const {
        if (isempty()) {
            cout << "stack is empty!" << endl;
            return;
        }
        cout << "stack:" << endl;
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
        cout << "stack menu" << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. top" << endl;
        cout << "4. check if empty" << endl;
        cout << "5. check if full" << endl;
        cout << "6. display stack" << endl;
        cout << "0. exit" << endl;
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
        case 0:
            cout << "exiting program" << endl;
            break;
        default:
            cout << "invalid choice" << endl;
        }
    } while (choice != 0);
    return 0;
}

