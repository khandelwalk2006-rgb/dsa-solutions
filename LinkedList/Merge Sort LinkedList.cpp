#include <bits/stdc++.h>
using namespace std;


// Time Complexity: O(n log n)
// Space Complexity: O(log n)


class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Find middle of linked list
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted linked lists

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* ans = new Node(-1); 
    Node* temp = ans;

    while (left && right) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left) temp->next = left;
    if (right) temp->next = right;

    Node* head = ans->next;
    delete ans;              // delete dummy node
    return head;
}

// Merge Sort function


Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left, right);
    return result;
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
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original Linked List:\n";
    printLL(head);

    head = mergeSort(head);

    cout << "Sorted Linked List:\n";
    printLL(head);

    return 0;
}
