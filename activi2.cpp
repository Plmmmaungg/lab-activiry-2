#include <iostream>

using namespace std;

struct Node {
    string songName;
    Node* link;
};

Node* createNode(string data) {
    Node* newNode = new Node();
    newNode->songName = data;
    newNode->link = NULL;
    return newNode;
}

void traverseList(Node* head) {
    Node* temp = head;
    cout << "\nMy Playlist:\n";
    while (temp != NULL) {
        cout << temp->songName << endl;
        temp = temp->link;
    }
    cout << "\n" << endl;
}

Node* insertAtEnd(string data, Node* head) {
    if (head == NULL) {
        head = createNode(data);
    } else {
        Node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = createNode(data);
    }
    cout << "A new node has been inserted at the end: " << data << endl;
    return head;
}

Node* insertAtBeginning(string data, Node* head) {
    Node* newNode = createNode(data);
    newNode->link = head;
    head = newNode;
    cout << "A new node has been inserted at the beginning: " << data << endl;
    return head;
}

Node* insertAfter(string after, string data, Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->songName.compare(after) != 0) {
        temp = temp->link;
    }
    if (temp == NULL) {
        cout << "No such song exists: " << after << ". Please try again later.\n";
        return head;
    }
    Node* newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    cout << "A new node has been added after \"" << after << "\": " << data << endl;
    return head;
}


string deleteAtEnd(Node *head) {
    if (head == NULL) {
        return "The linked list is empty";
    }
    Node* temp = new Node;
    temp = head;

    while(temp->link->link != NULL) {
        temp = temp->link;
    }

    temp->link = NULL;

    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head) {
    if (head == NULL) {
        cout << "The linked list is empty\n";

    }

    if(head->link == NULL) {
        delete head;
    

    }

    head = head->link;

    cout << "A node has been deleted at the beginning\n";

    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty\n";
        return head;
    }

    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = head->link;

    while(next->songName.compare(givenNode) != 0){
       if(temp->link == NULL){
           cout << "The song does not exist\n";
           return head;
       }
       next = next->link;
         temp = temp->link;
    }

    temp->link = next->link;
    cout << "The Node" + givenNode + "has been deleted\n" << endl;
    return head;

}



int main() {
    Node* head = createNode("Sanctuary by Joji");
    traverseList(head);
    cout << "\nInsert 3 Most Played Songs at the End\n";
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverseList(head);
    head = insertAtEnd("Take it to the Top by BINI", head);
    traverseList(head);
    head = insertAtEnd("Mundo by IV of Spades", head);
    traverseList(head);

    cout << "\nInsert 4 Favorite Songs at the Beginning\n";
    head = insertAtBeginning("Bohemian Rhapsody by Queen", head);
    traverseList(head);
    head = insertAtBeginning("Cherry on Top by BINI", head);
    traverseList(head);
    head = insertAtBeginning("With A Smile by Eraserheads", head);
    traverseList(head);
    head = insertAtBeginning("Hotel California by Eagles", head);
    traverseList(head);

    cout << "\nInsert 3 OPM Songs After Favorite Songs\n";
    head = insertAfter("Hotel California by Eagles", "Blinding Lights by The Weeknd", head);
    traverseList(head);
    head = insertAfter("Bohemian Rhapsody by Queen", "Someone Like You by Adele", head);
    traverseList(head);
    head = insertAfter("Someone Like You by Adele", "Hanggang Kailan by Orange & Lemons", head);

    traverseList(head);
    

     cout << "\nDelete Songs\n";
    traverseList(head);
    head = deleteFromBeginning(head);
    traverseList(head);
    head = deleteFromGivenNode("Blinding Lights by The Weeknd", head);
    traverseList(head);
}


