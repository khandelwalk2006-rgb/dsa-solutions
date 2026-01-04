#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n)
// Space Complexity: O(n/k)  


class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* kReverse(Node* head, int k) {
    if (!head) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next) {
        head->next = kReverse(next, k);
    }

    return prev;
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
    head->next->next->next->next->next = new Node(6);

    int k = 2;

    cout << "Original Linked List:\n";
    printLL(head);

    head = kReverse(head, k);

    cout << "Reversed in K-Groups Linked List:\n";
    printLL(head);

    return 0;
}
