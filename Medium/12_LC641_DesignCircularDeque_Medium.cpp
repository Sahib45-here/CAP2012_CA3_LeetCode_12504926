#include <vector>
using namespace std;

class MyCircularDeque {
    vector<int> arr;
    int front, rear, capacity, count;

public:
    MyCircularDeque(int k) {
        arr.resize(k);
        capacity = k;
        front = 0;
        rear = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : arr[front]; }
    int getRear()  { return isEmpty() ? -1 : arr[(rear - 1 + capacity) % capacity]; }
    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == capacity; }
};