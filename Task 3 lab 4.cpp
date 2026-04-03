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
    void push(int value)
    {
        arr[++t] = value;
    }
    int pop()
    {
        return arr[t--];
    }
};
class Queue
{
private:
    int arr[100];
    int frontIndex, rear;
public:
    Queue()
    {
        frontIndex = 0;
        rear = -1;
    }
    bool isEmpty()
    {
        return frontIndex > rear;
    }
    void enqueue(int value)
    {
        if (rear == 99)
        {
            cout << "Q overflow" << endl;
            return;
        }
        arr[++rear] = value;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Q underflow" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }
    int front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[frontIndex];
    }
    int size()
    {
        return rear - frontIndex + 1;
    }
    void display()
    {
        for (int i = frontIndex; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void reverseK(Queue& q, int a)
{
    if (a <= 1 || q.isEmpty())
    {
        return;
    }
    if (a > q.size())
    {
        a = q.size();
    }
    Stack s;
    for (int i = 0; i < a; i++)
    {
        s.push(q.dequeue());
    }
    while (!s.isEmpty())
    {
        q.enqueue(s.pop());
    }
    int remaining = q.size() - a;
    for (int i = 0; i < remaining; i++)
    {
        q.enqueue(q.dequeue());
    }
}
int main()
{
    Queue q;
    int n, value, r;
    cout << "Enter number of elements: " << endl;
    cin >> n;
    cout << "Enter q elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.enqueue(value);
    }
    cout << "Queue: ";
    q.display();
    cout << "how many elements to reverse: " << endl;
    cin >> r;
    reverseK(q, r);
    cout << "Output: ";
    q.display();


    return 0;
}