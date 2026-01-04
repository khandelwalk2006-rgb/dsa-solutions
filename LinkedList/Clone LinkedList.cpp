#include <bits/stdc++.h>
using namespace std;



// Time Complexity: O(n)
/ Space Complexity: O(n)


class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return NULL;

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while (temp) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode && cloneNode) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode) {
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// Utility function to print linked list
void printLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->random) cout << "(" << head->random->data << ")";
        cout << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;            // 1->3
    head->next->random = head;                  // 2->1
    head->next->next->random = head->next;      // 3->2

    Solution sol;
    Node* cloned = sol.cloneLinkedList(head);

    cout << "Original List:\n";
    printLL(head);

    cout << "Cloned List:\n";
    printLL(cloned);

    return 0;
}
