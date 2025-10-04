#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse k nodes starting from head
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    int count = 0;
    
    // Count k nodes
    while (node && count < k) {
        node = node->next;
        count++;
    }
    
    if (count < k) return head; // Less than k nodes, no change

    // Reverse k nodes
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    int i = 0;
    while (i < k && curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }

    // Recursively reverse remaining nodes
    if (next) head->next = reverseKGroup(next, k);

    return prev;
}

// Helper to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* newHead = reverseKGroup(head, k);
    printList(newHead);

    return 0;
}
