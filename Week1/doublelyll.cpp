#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Hàm hủy để giải phóng bộ nhớ
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 1. Truy cập phần tử
    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Lỗi: Vị trí không hợp lệ.");
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // 2. Chèn phần tử vào đầu
    void insertFirst(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // 3. Chèn phần tử vào cuối
    void insertLast(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // 4. Chèn vào vị trí i
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Lỗi: Vị trí không hợp lệ." << endl;
            return;
        }
        if (index == 0) {
            insertFirst(value);
            return;
        }
        if (index == size) {
            insertLast(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }

    // 5. Xóa phần tử đầu
    void deleteFirst() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // 6. Xóa phần tử cuối
    void deleteLast() {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    // 7. Xóa vị trí i
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Lỗi: Vị trí không hợp lệ." << endl;
            return;
        }
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == size - 1) {
            deleteLast();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }

    // 8. Duyệt xuôi
    void traverseForward() {
        cout << "Duyệt xuôi: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 9. Duyệt ngược
    void traverseBackward() {
        cout << "Duyệt ngược: ";
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
