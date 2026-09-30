#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100;

class StaticArray {
private:
    int data[MAX_SIZE];
    int size;

public:
    StaticArray() {
        size = 0;
    }

    //Truy cập phần tử
    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Lỗi: Vị trí không hợp lệ.");
        }
        return data[index];
    }

    //Chèn phần tử vào đầu
    void insertFirst(int value) {
        if (size >= MAX_SIZE) {
            cout << "Lỗi: Mảng đã đầy, không thể chèn thêm." << endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = value;
        size++;
    }

    //Chèn phần tử vào cuối
    void insertLast(int value) {
        if (size >= MAX_SIZE) {
            cout << "Lỗi: Mảng đã đầy, không thể chèn thêm." << endl;
            return;
        }
        data[size] = value;
        size++;
    }

    // Chèn vào vị trí i
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Lỗi: Vị trí không hợp lệ." << endl;
            return;
        }
        if (size >= MAX_SIZE) {
            cout << "Lỗi: Mảng đã đầy, không thể chèn thêm." << endl;
            return;
        }
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    //Xóa phần tử đầu
    void deleteFirst() {
        if (size == 0) {
            cout << "Lỗi: Mảng rỗng, không có gì để xóa." << endl;
            return;
        }
        
        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Xóa phần tử cuối
    void deleteLast() {
        if (size == 0) {
            cout << "Lỗi: Mảng rỗng, không có gì để xóa." << endl;
            return;
        }
        size--;
    }

    //Xóa vị trí i
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Lỗi: Vị trí không hợp lệ." << endl;
            return;
        }
        // Dịch các phần tử từ vị trí i+1 sang trái
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    //Duyệt xuôi
    void traverseForward() {
        cout << "Duyệt xuôi: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Duyệt ngược
    void traverseBackward() {
        cout << "Duyệt ngược: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
