#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(1)


class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* getMiddle(Node* head) {
    if (!head) return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


void printLL(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List:\n";
    printLL(head);

    Node* mid = getMiddle(head);
    if (mid)
        cout << "Middle Node: " << mid->data << endl;

    return 0;
}
