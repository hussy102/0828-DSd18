#include <iostream>
using namespace std;
class node {
public:
	string name;
	int front;
	node* next;
	node(string n, int p) {
		name = n;
		front = p;
		next = nullptr;
	}
};
class book {
	string title;
	node* head;
public:
	book(string t) {
		title = t;
		head = nullptr;
	}
	string gettitle() {
		return title;
	}
	void addstudent(string name, int front) {
		node* newnode = new node(name, front);
		if (head == nullptr || front < head->front) {
			newnode->next = head;
			head = newnode;
			return;
		}
		node* temp = head;
		while (temp->next != nullptr && temp->next->front <= front) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	void removestudent(string name) {
		if (head == nullptr) {
			cout << "empty" << endl;
			return;
		}
		if (head->name == name) {
			node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		node* temp = head;
		while (temp->next != nullptr && temp->next->name != name) {
			temp = temp->next;
		}
		if (temp->next == nullptr) {
			cout << "not found" << endl;
			return;
		}
		node* del = temp->next;
		temp->next = temp->next->next;
		delete del;
	}
	void updatepriority(string name, int newp) {
		removestudent(name);
		addstudent(name, newp);
	}
	void display() {
		cout << title << ": ";
		if (head == nullptr) {
			cout << "empty" << endl;
			return;
		}
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->name << "(" << temp->front << ") ";
			temp = temp->next;
		}
		cout << endl;
	}
	int count() {
		int c = 0;
		node* temp = head;
		while (temp != nullptr) {
			c++;
			temp = temp->next;
		}
		return c;
	}
	void serve() {
		if (head == nullptr) {
			cout << "no students" << endl;
			return;
		}
		node* temp = head;
		cout << "    served " << temp->name << " from " << title << endl;
		head = head->next;
		delete temp;
	}
};
int main() {
	book b1("data structures");
	book b2("me and you");
	b1.addstudent("ali", 2);
	b1.addstudent("rasheed", 1);
	b1.addstudent("hussnain", 3);
	b2.addstudent("areesha", 2);
	b2.addstudent("ayesha", 1);
	b2.addstudent("muazzz", 3);
	b1.display();
	b2.display();
	cout << b1.count() << endl;
	cout << b2.count() << endl;
	b1.updatepriority("hussnain", 0);
	b1.display();
	b1.removestudent("ali");
	b1.display();
	b1.serve();
	b1.display();
	b2.serve();
	b2.display();
	return 0;
}