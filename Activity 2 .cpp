#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	string songName;
	string artistName;
	Node* link;
} Node;

Node* createNode(string data, string artist) {
	Node* newNode = new Node;
	newNode->songName = data;
	newNode->artistName = artist;
	newNode->link = newNode;

	return newNode;
}

void traverse(Node *head) {
	Node *temp = head;

	cout << "My Playlist" << endl;
	do {
		cout << temp->songName << "  " << temp->artistName << " " << endl;

		temp = temp->link;
	} while (temp != head);
}

Node* insertAtEnd(string data, string artist, Node* head) {
	if(head == NULL) {
		Node *newNode = createNode(data, artist);
		head = newNode;
		cout <<"A new node has been inserted at the end \n"<<endl;
		return head;
	}
	Node *temp = new Node;
	temp = head;

	while(temp->link != head) {
		temp = temp ->link;
	}

	Node *newNode = createNode (data, artist);
	temp->link = newNode;
	newNode->link = head;

	cout<< "A new node has been inserted at the end \n"<<endl;
	return head;

}


Node* insertAtBeginning(string data, string artist, Node* head) {
	Node *temp = head;

	while (temp->link != head) {
		temp = temp->link;
	}

	Node *newNode = createNode(data, artist);
	newNode->link = head;
	temp->link = newNode;

	head = newNode;

	cout << "A new node has been inserted at the beginning \n" << endl;

	return head;
}

string insertAtAfter(string after, string data, string artist, Node* head) {
	Node *temp = new Node;
	temp = head;

	while (temp->songName.compare(after) != 0) {
		if (temp == NULL) {
			return "No such song exist, please try again later.";
		}

		temp = temp->link;
	}
	Node *newNode = createNode(data, artist);
	newNode->link = temp->link;
	temp->link = newNode;

	return "An new node has been added after " + after + "\n";
}

string deleteAtEnd(Node* head) {
	Node *temp = head;

	while (temp->link->link != head) {
		temp = temp->link;
	}

	temp->link = head;

	return "A node has been deleted from the end \n";
}

Node* deleteFromBeginning(Node* head) {
	Node* temp = head;

	while (temp->link != head) {
		temp = temp->link;
	}

	temp->link = head->link;
	head = head->link;

	cout << "A node has been deleted from the beginning. \n" << endl;

	return head;
}

Node* deleteFromGivenNode(string givenNode, Node* head) {
	if (head == NULL) {
		cout << "The linked list is empty \n" << endl;
		return NULL;
	}

	if (head->songName.compare(givenNode) == 0) {
		head = deleteFromBeginning(head);
		cout << "The Node " + givenNode + " has been deleted \n" << endl;
		return head;
	}

	Node *temp = new Node;
	Node *next = new Node;
	temp = head;
	next = temp->link;

	while (next->songName.compare(givenNode) != 0) {
		if (temp == NULL) {
			cout << "No such node exist \n" << endl;
			return head;
		}

		next = next->link;
		temp = temp->link;
	}

	temp->link = next->link;
	cout << "The Node " + givenNode + " has been deleted \n" << endl;
	return head;
}


int main() {
	Node *head = createNode("Sanctuary","by Joji");
	

	head = insertAtEnd ("Sunday Morning","by Maroon", head);
	traverse(head);
	head = insertAtEnd ("Season","by Wave to Earth", head);
    traverse(head);
	head = insertAtEnd ("Scott Street", "by Phoebe Bridgers", head);
    traverse(head);
	head = insertAtEnd ("Perfect", "by Simple Plan", head);


    traverse(head);
	head = insertAtBeginning ("Top", "by BINI", head);
    traverse(head);
	head = insertAtBeginning ("Day and Night", "by ALAMAT", head);
    traverse(head);
	head = insertAtBeginning ("Yes or Yes", "by Twice", head);
    traverse(head);
	head = insertAtBeginning ("Iced Coffee", "by Pixie", head);


    traverse(head);
	cout<< insertAtAfter ("Top","Tonight","by FM Static",head) << endl;
    traverse(head);
	cout<< insertAtAfter ("Yes or Yes","Moment of Truth","by FM Static", head) << endl;
    traverse(head);
	cout<< insertAtAfter ("Iced Coffee","Unwell", "by Matchbox Twenty", head) << endl;

	traverse(head);

	cout << deleteAtEnd(head) << endl;
    traverse(head);
	head = deleteFromBeginning(head);
    traverse(head);
	head = deleteFromGivenNode("Perfect", head);
	traverse (head);

	return 0;
}