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

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node* head) {
    Node* zeroHead = new Node(-1), *zeroTail = zeroHead;
    Node* oneHead = new Node(-1), *oneTail = oneHead;
    Node* twoHead = new Node(-1), *twoTail = twoHead;

    Node* curr = head;

    while (curr) {
        int value = curr->data;
        if (value == 0) insertAtTail(zeroTail, curr);
        else if (value == 1) insertAtTail(oneTail, curr);
        else insertAtTail(twoTail, curr);

        curr = curr->next;
    }

    // merge lists
    if (oneHead->next) zeroTail->next = oneHead->next;
    else zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void printLL(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    cout << "Original Linked List:\n";
    printLL(head);

    head = sortList(head);

    cout << "Sorted Linked List:\n";
    printLL(head);

    return 0;
}
