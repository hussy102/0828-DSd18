#include <iostream>
#include <string>
using namespace std;
template <typename T>
class AbstractQueue
{
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front_element() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue : public AbstractQueue<T>
{
private:
    T* data;
    int f;
    int r;
    int m;
public:
    myQueue(int s)
    {
        m = s;
        data = new T[m];
        f = -1;
        r = -1;
    }
    ~myQueue()
    {
        delete[] data;
    }
    bool isEmpty() const
    {
        return (f == -1);
    }
    bool isFull() const
    {
        return (r == m - 1);
    }
    void enQueue(T value)
    {
        if (isFull())
        {
            cout << " full" << endl;
            return;
        }
        if (isEmpty())
        {
            f = 0;
        }
        r++;
        data[r] = value;
    }
    T deQueue()
    {
        if (isEmpty())
        {
            cout << " empty" << endl;
            return T();
        }
        T value = data[f];
        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f++;
        }
        return value;
    }
    T front_element() const
    {
        if (isEmpty())
        {
            cout << " empty" << endl;
            return T();
        }
        return data[f];
    }
    void display() const
    {
        if (isEmpty())
        {
            cout << "empty" << endl;
            return;
        }
        for (int i = f; i <= r; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int qSize;
    cout << "Enter the size : ";
    cin >> qSize;
    myQueue<int> q(qSize);
    int choice;
    int val;
    do
    {
        cout << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. front Element" << endl;
        cout << "4. check if Empty" << endl;
        cout << "5. check if Full" << endl;
        cout << "6. display" << endl;
        cout << "7. exit" << endl;
        cout << "choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> val;
            q.enQueue(val);
            break;
        }
        case 2:
        {
            val = q.deQueue();
            if (val != 0 || !q.isEmpty())
            {
                cout << "deleted val: " << val << endl;
            }
            break;
        }
        case 3:
        {
            if (!q.isEmpty())
            {
                cout << "front: " << q.front_element() << endl;
            }
            else
            {
                q.front_element();
            }
            break;
        }
        case 4:
        {
            if (q.isEmpty())
            {
                cout << "qeue is currently empty." << endl;
            }
            else
            {
                cout << "qeue is not empty." << endl;
            }
            break;
        }
        case 5:
        {
            if (q.isFull())
            {
                cout << "queue is currently full." << endl;
            }
            else
            {
                cout << "queue is not full." << endl;
            }
            break;
        }
        case 6:
        {
            q.display();
            break;
        }
        case 7:
        {
            cout << "closing" << endl;
            break;
        }
        default:
        {
            cout << "Invalid" << endl;
        }
        }
    }
    
    while (choice != 7);

    return 0;
}