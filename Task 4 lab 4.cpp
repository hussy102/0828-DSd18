#include <iostream>
using namespace std;
class Queue
{
private:
    int arr[100];
    int f, R;

public:
    Queue()
    {
        f = 0;
        R = -1;
    }
    bool isEmpty()
    {
        return f > R;
    }
    bool isFull()
    {
        return R == 99;
    }
    void enqueue(int ticket_id)
    {
        if (isFull())
        {
            cout << "Q full" << endl;
            return;
        }
        if (ticket_id < 1000 || ticket_id > 9999)
        {
            cout << "invalid  id" << endl;
            return;
        }
        arr[++R] = ticket_id;
        cout << "ticket added: " << ticket_id << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No tickets" << endl;
            return;
        }
        cout << "solved ticket: " << arr[f++] << endl;
    }
    void showFront()
    {
        if (isEmpty())
        {
            cout << "0 pending tickets" << endl;
            return;
        }
        cout << "next ticket: " << arr[f] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "0 pending tickets" << endl;
            return;
        }
        cout << "Pending tickets: ";

        for (int i = f; i <= R; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q;
    int choice, ticket_id;
    do
    {
        cout << endl;
        cout << "1. add ticket" << endl;
        cout << "2. solve ticket" << endl;
        cout << "3. view next ticket" << endl;
        cout << "4. display all tickets" << endl;
        cout << "5. exit" << endl;
        cout << "enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter four digit ticket id: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            q.showFront();
            break;
        }
        case 4:
        {
            q.display();
            break;
        }
        case 5:
        {
            cout << "Exit." << endl;
            break;
        }
        default:
        {
            cout << "invalid " << endl;
        }

        }
    }
    while (choice != 5);

    return 0;
}