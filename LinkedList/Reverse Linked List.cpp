#include <bits/stdc++.h>
using namespace std;



// Time Complexity: O(n)
// Space Complexity: O(n)  



class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};



Node* reverseLL(Node* head) {
    if (!head || !head->next) return head; // base case
    Node* newHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
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

    cout << "Original List:\n";
    printLL(head);

    head = reverseLL(head);

    cout << "Reversed List:\n";
    printLL(head);

    return 0;
}
