
/*
  Time Complexity:
  enqueue()  -> O(1)
  dequeue()  -> O(1)
  front()    -> O(1)
   Space Complexity: O(N)   // using array of size N

*/

#include <bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int f;      // renamed from front
    int rear;
    int size;

public:
    Queue() {
        size = 10001;
        arr = new int[size];
        f = 0;
        rear = 0;
    }

    bool isEmpty() {
        return (f == rear);
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (f == rear) {
            return -1;
        } else {
            int ans = arr[f];
            f++;

            if (f == rear) {
                f = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (f == rear) {
            return -1;
        } else {
            return arr[f];
        }
    }
};
