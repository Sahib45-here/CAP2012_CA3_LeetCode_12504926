#include <cstddef>
using namespace std;

class MyLinkedList {
    struct Node {
        int val;
        Node *next;
        Node(int v) : val(v), next(NULL) {}
    };
    Node *head;
    int size;

public:
    MyLinkedList() {
        head = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node *curr = head->next;
        for (int i = 0; i < index; i++) curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        Node *n = new Node(val);
        n->next = head->next;
        head->next = n;
        size++;
    }

    void addAtTail(int val) {
        Node *curr = head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node *curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        Node *n = new Node(val);
        n->next = curr->next;
        curr->next = n;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node *curr = head;
        for (int i = 0; i < index; i++) curr = curr->next;
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
};