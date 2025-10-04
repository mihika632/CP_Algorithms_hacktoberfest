#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a new node at the end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Function to calculate sum of all nodes
int sumLinkedList(Node* head) {
    int sum = 0;
    Node* temp = head;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Linked List: ";
    printList(head);

    int total = sumLinkedList(head);
    cout << "Sum of all elements: " << total << endl;

    return 0;
}
