#include <bits/stdc++.h>
using namespace std;



// Time Complexity: O(n)
// Space Complexity: O(1)


class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node() {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
    Node(int d, Node* n, Node* p) {
        data = d;
        next = n;
        prev = p;
    }
};

Node* removeDuplicates(Node* head) {
    if (!head) return NULL;

    Node* curr = head;

    while (curr) {
        if (curr->next && curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
            if (next_next) next_next->prev = curr;
        }
        else {
            curr = curr->next;
        }
    }

    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;

    cout << "Original Doubly Linked List:\n";
    printDLL(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates:\n";
    printDLL(head);

    return 0;
}
