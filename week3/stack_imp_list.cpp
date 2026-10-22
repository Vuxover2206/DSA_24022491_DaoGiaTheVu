#include<bits/stdc++.h>

using namespace std;

#define MAX 1000
class StackList {
private:
    int top;
    int arr[MAX];
public:
    StackList() {
        top = -1;
    }

    bool isEmpty() {
        return (top < 0);
    }

    void push(int x) {
        if (top >= MAX - 1) {
           return;
        }
        arr[++top] =x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "empty";
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack rong";
            return -1;
        }
        return arr[top];
    }
};
