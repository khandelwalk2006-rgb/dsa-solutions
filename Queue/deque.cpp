/*
Time Complexity: O(1) per operation
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) ||
                (rear + 1) % size == front);
    }

    bool pushFront(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            front--;

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else if (rear == size - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[front];

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }

    int popRear()
    {
        if (isEmpty())
            return -1;

        int ans = arr[rear];

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        return ans;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
};
