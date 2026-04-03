#include <iostream>
using namespace std;
class Stack
{
private:
    int arr[100];
    int t;

public:
    Stack()
    {
        t = -1;
    }
    bool isEmpty()
    {
        return t == -1;
    }
    bool isFull()
    {
        return t == 99;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "overflow";
            return;
        }
        arr[++t] = value;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stackunderflow\n";
            return -1;
        }
        return arr[t--];
    }
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[t];
    }
};
class QueueStack
{
private:
    Stack stack1, stack2;
public:
    void enqueue(int value)
    {
        stack1.push(value);
        cout << value << " inserted\n";
    }
    void transfer()
    {
        while (!stack1.isEmpty())
        {
            stack2.push(stack1.pop());
        }
    }
    int dequeue()
    {
        if (stack2.isEmpty())
        {
            transfer();
        }
        if (stack2.isEmpty())
        {
            cout << "Q is empty" << endl;
            return -1;
        }

        return stack2.pop();
    }
    int front()
    {
        if (stack2.isEmpty())
        {
            transfer();
        }
        if (stack2.isEmpty())
        {
            cout << "q is empty\n";
            return -1;
        }
        return stack2.peek();
    }
    void display()
    {
        if (stack1.isEmpty() && stack2.isEmpty())
        {
            cout << "Q is empty" << endl;;
            return;
        }
        Stack temp1 = stack2;
        while (!temp1.isEmpty())
        {
            cout << temp1.pop() << " ";
        }
        Stack temp2;
        Stack temp3 = stack1;
        while (!temp3.isEmpty())
        {
            temp2.push(temp3.pop());
        }
        while (!temp2.isEmpty())
        {
            cout << temp2.pop() << " ";
        }
        cout << endl;
    }
};
int main()
{
    QueueStack q;
    int choice, value;
    do
    {
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. font" << endl;
        cout << "4. display" << endl;
        cout << "5. exit" << endl;
        cout << "choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        }
        case 2:
        {
            value = q.dequeue();
            if (value != -1)
                cout << "deleteddd: " << value << endl;
            break;
        }
        case 3:
        {
            value = q.front();
            if (value != -1)
                cout << "front: " << value << endl;
            break;
        }
        case 4:
        {
            cout << "queue elements: ";
            q.display();
            break;
        }
        case 5:
        {
            cout << "closing." << endl;
            break;
        }
        default:
        {
            cout << "Invalid " << endl;
        }

        }
    }
    while (choice != 5);

    return 0;
}