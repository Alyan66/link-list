#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;//pointer to point next node
	node(int value) {//ctor to pass value in node
		data = value;
		next = NULL;
	}
};
	void insertattail(node*& head, int value) {//to modify nodes we get by reference value
		
		node* n = new node(value);
		if (head == NULL) {
			head = n;
			return;
		}
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;//enter new node element
	}
	void display(node* head) {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout <<"NULL"<< endl;
	}
	int main() {
		node* head = NULL;
		for (int i = 1; i <= 30; i++) {
			insertattail(head, i);
			
		}
		display(head);
	}

