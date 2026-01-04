#include <bits/stdc++.h>
using namespace std;




// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))


class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void insertAtTail(Node* &head, Node* &tail, int value) {
        Node* temp = new Node(value);
        if (!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* head1, Node* head2) {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;

        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);
        }

        return ansHead;
    }

public:
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* ans = add(head1, head2);

        ans = reverse(ans);

        return ans;
    }
};

// Utility function to print linked list
void printLL(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Example usage
int main() {
    Node* head1 = new Node(3);
    head1->next = new Node(4);
    head1->next->next = new Node(2); // represents 342

    Node* head2 = new Node(4);
    head2->next = new Node(6);
    head2->next->next = new Node(5); // represents 465

    Solution sol;
    Node* ans = sol.addTwoLists(head1, head2); // 342 + 465 = 807

    cout << "Sum Linked List:\n";
    printLL(ans);

    return 0;
}
