#include <bits/stdc++.h>
using namespace std;


Detect and Remove Loop in Linked List

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

Node* floydDetectLoop(Node* head) {
    if (!head) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return slow;
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    Node* intersection = floydDetectLoop(head);
    if (!intersection) return NULL;

    Node* ptr1 = head;
    Node* ptr2 = intersection;

    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

Node* removeLoop(Node* head) {
    if (!head) return NULL;

    Node* startLoop = getStartingNode(head);
    if (!startLoop) return head;

    Node* temp = startLoop;
    while (temp->next != startLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;

    head = removeLoop(head);

    printLL(head);

    return 0;
}
