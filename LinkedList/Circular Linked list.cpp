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


Node* createCircularLL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < arr.size(); i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    tail->next = head; 
    return head;
}


void printCircularLL(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createCircularLL(arr);

    cout << "Circular Linked List:\n";
    printCircularLL(head);

    return 0;
}
