#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node* prev;
	node(int value) {
		data = value;
		next = NULL;
		prev = NULL;
	}
};
void insertAttail(node*& head, int val) {
	node* n = new node(val);
	if (head == NULL) {
		head = n;
		return;
	}
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}
void insertposition(node*& head,int newelement, int pos) {
	
	node* n = new node(newelement);
	node* temp = head;
	int lengthofnode = 0;
	while (temp != NULL) {
		lengthofnode++;
		temp = temp->next;
	}

	if (pos == 1) {
		cout << "pos should be >1 " << endl;
	}
	else if (pos < 1 || pos > lengthofnode) {
		cout << "invalid position " << endl;
		return;
	}

	int count = 1;
	while (count < pos - 1) {
		if (temp->next != NULL) {
			temp = temp->next;
			count++;
		}
	}
	n->next = temp->next;
	temp->next->prev = n;
	temp->next = n;
	n->prev = temp;
}
void display(node* head) {
	node* temp = head;
	while (temp->next != NULL) {
		cout << temp->data << "<--> ";
		temp = temp->next;
	}
	cout << "null";
	cout << endl;
}
int main() {
	node* head = NULL;
	cout << "before insert new node: ";
	for (int i = 1; i < 10; i++) {
		insertAttail(head, i);
	}
	display(head);
	cout << "after insert new node: ";
	insertposition(head, 8, 11);
	display(head);
	
}