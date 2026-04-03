#include <iostream>
#include <string>
using namespace std;
class Queue
{
private:
    int id[100];
    string add[100];
    int strtT[100];
    int endT[100];
    int F, R;
public:
    Queue()
    {
        F = 0;
        R = -1;
    }
    bool isEmpty()
    {
        return F > R;
    }
    bool isFull()
    {
        return R == 99;
    }
    void enqueue(int pid, string addr, int start, int end)
    {
        if (isFull())
        {
            cout << "Q full" << endl;
            return;
        }
        R++;
        id[R] = pid;
        add[R] = addr;
        strtT[R] = start;
        endT[R] = end;
        cout << "package added" << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        cout << "delivered package id = " << id[F] << endl;
        F++;
        if (isEmpty())
        {
            F = 0;
            R = -1;
        }
    }
    void showFront()
    {
        if (isEmpty())
        {
            cout << "no packages" << endl;
            return;
        }
        cout << "front package id = " << id[F] << endl;
        cout << "address = " << add[F] << endl;
        cout << "time  = " << strtT[F] << " to " << endT[F] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        cout << "All packages = " << endl;
        for (int i = F; i <= R; i++)
        {
            cout << "Id = " << id[i] << " Address = " << add[i] << " Time = " << strtT[i] << "-" << endT[i] << endl;
        }
    }
    void timeToDeliver(int currentTime)
    {
        if (isEmpty())
        {
            cout << "No packages" << endl;
            return;
        }
        if (currentTime > endT[F])
        {
            cout << "Pac expired = " << id[F] << endl;
            F++;
        }
        else if (currentTime >= strtT[F] && currentTime <= endT[F])
        {
            cout << "Package  delivered." << endl;
            dequeue();
        }
        else
        {
            cout << "time = " << strtT[F] << endl;
        }
        if (isEmpty())
        {
            F = 0;
            R = -1;
        }
    }
};
int main()
{
    Queue q;
    int choice;
    int pid;
    int start;
    int end;
    int currentTime;
    string addr;
    do
    {
        cout << endl;
        cout << "1. add package" << endl;
        cout << "2. deliver package" << endl;
        cout << "3. view front package" << endl;
        cout << "4. display all packages" << endl;
        cout << "5. check time and deliver" << endl;
        cout << "6. exit" << endl;
        cout << "enter choice = ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "enter id = ";
            cin >> pid;
            cin.ignore();
            cout << "enter address = ";
            getline(cin, addr);
            cout << "enter start time = ";
            cin >> start;
            cout << "enter end time = ";
            cin >> end;
            q.enqueue(pid, addr, start, end);
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
            cout << "enter current time = ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
            break;
        }
        case 6:
        {
            cout << "exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid ." << endl;
            break;
        }
        }
    } 
    while (choice != 6);
    
    return 0;
}