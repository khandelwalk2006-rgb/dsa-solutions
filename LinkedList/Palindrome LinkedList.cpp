#include <bits/stdc++.h>
using namespace std;



// Time Complexity: O(n)
// Space Complexity: O(1)


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
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        Node* middle = getMid(head);
        Node* secondHalf = reverse(middle->next);
        Node* temp = secondHalf;
        middle->next = secondHalf;

        Node* firstHalf = head;
        bool palindrome = true;

        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        middle->next = reverse(temp); // restore list
        return palindrome;
    }
};

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
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    Solution sol;
    cout << "Linked List:\n";
    printLL(head);

    cout << "Is Palindrome? " << (sol.isPalindrome(head) ? "Yes" : "No") << endl;

    return 0;
}
