#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class StackLinkedList {
private:
    Node* top;
public:
    StackLinkedList() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);

        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "stack rong";
            return -1;
        }
        Node* temp = top;
        int poppedData = temp->val;
        top = top->next;
        
        delete temp;
        return poppedData;
    }
    int peek() {
        if (isEmpty()) {
            cout <<"rỗng";
            return -1;
        }
        return top->val;
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
}; 
