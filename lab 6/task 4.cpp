#include <iostream>
using namespace std;
class node {
public:
	string name;
	node* next;
	node(string n) {
		name = n;
		next = nullptr;
	}
};
class hospital {
	node* head;
public:
	hospital() {
		head = nullptr;
	}
	void patient(string name) {
		node* newnode = new node(name);
		if (head == nullptr) {
			head = newnode;
			return;
		}
		node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
	void removepatient(string name) {
		if (head == nullptr) {
			cout << " empty" << endl;
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
			cout << " not found" << endl;
			return;
		}
		node* del = temp->next;
		temp->next = temp->next->next;
		delete del;
	}
	void display() {
		if (head == nullptr) {
			cout << "queue is empty" << endl;
			return;
		}
		node* temp = head;
		while (temp != nullptr) {
			cout << temp->name << " ";
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
};
int main() {
	hospital q;
	q.patient("hussnain");
	q.patient("rasheed");
	q.patient("ali");
	q.display();
	cout << q.count() << endl;
	q.removepatient("ali");
	q.display();
	cout << q.count() << endl;
	return 0;
}