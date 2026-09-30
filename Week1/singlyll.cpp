#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail; 
    int size;

    void printBackward(Node* node) {
        if (node == nullptr) return;
        printBackward(node->next);
        cout << node->data << " ";
    }

public:
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~SinglyLinkedList() {
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
            head = newNode;
        }
        size++;
    }

    // 3. Chèn phần tử vào cuối
    void insertLast(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
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
        temp->next = newNode;
        size++;
    }

    // 5. Xóa phần tử đầu
    void deleteFirst() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail) { // Chỉ có 1 phần tử
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
        size--;
    }

    // 6. Xóa phần tử cuối
    void deleteLast() {
        if (head == nullptr) return;

        if (head == tail) { // Chỉ có 1 phần tử
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            // Tìm phần tử kế cuối
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
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
        // Tìm phần tử đứng trước vị trí cần xóa
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
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
        printBackward(head); // Gọi hàm đệ quy
        cout << endl;
    }
};
