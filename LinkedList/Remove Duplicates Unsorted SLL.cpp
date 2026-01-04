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

Node* removeDuplicatesUnsorted(Node* head) {
    if (!head) return NULL;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr) {
        if (seen.count(curr->data)) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

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
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    cout << "Original Unsorted Linked List:\n";
    printLL(head);

    head = removeDuplicatesUnsorted(head);

    cout << "After Removing Duplicates:\n";
    printLL(head);

    return 0;
}
