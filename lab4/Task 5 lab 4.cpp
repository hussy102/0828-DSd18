#include <iostream>
using namespace std;
class Queue
{
private:
	string arr[100];
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
	void enqueue(string document)
	{
		if (isFull())
		{
			cout << "Q full" << endl;
			return;
		}
		arr[++R] = document;
		cout << "document add: " << document << endl;
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "no documents " << endl;
			return;
		}
		cout << "print document: " << arr[f++] << endl;
	}
	void showFront()
	{
		if (isEmpty())
		{
			cout << "0 documents in q" << endl;
			return;
		}
		cout << "next doc: " << arr[f] << endl;
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "0 docs in q" << endl;
			return;
		}
		cout << "Pending documents: ";
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
	int cho;
	string doc;
	do
	{
		cout << endl;
		cout << "1. add document" << endl;
		cout << "2. print document" << endl;
		cout << "3. view next document" << endl;
		cout << "4. display all documents" << endl;
		cout << "5. exit" << endl;
		cout << "enter choice: ";
		cin >> cho;
		switch (cho)
		{
		case 1:
		{
			cout << "plzzz enter document name: ";
			cin >> doc;
			q.enqueue(doc);
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
			cout << "shutting down" << endl;
			break;
		}
		default:
		{
			cout << "invalid " << endl;
		}
		}
	} 
	while(cho != 5);
	
	
	return 0;
}