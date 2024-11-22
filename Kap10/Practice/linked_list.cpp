#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //destructor
    Node() {
        this->next = NULL;
    }

    //constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head) {
    Node* temp = head;

    while(temp!=NULL) {
        cout << temp->data;
        temp = temp -> next;

        if(temp!=NULL) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int getLength(Node* head) {
    Node* temp = head;
    int count = 0;

    while(temp!=NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->next = third;

    Node* head = first;
    cout << "Printing Linked List..." << endl;
    printLL(head);
    
    int length = getLength(head);
    cout << "Length of Linked List is: " << length << endl;

    return 0;
}