#include<bits/stdc++.h>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap; 

    
    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1; // left
            
            // Tìm con lớn nhất để solo
            if (j + 1 < n && heap[j] < heap[j + 1]) {
                j++; 
            }
            
            // Nếu cha đã lớn hơn con lớn nhất -> dừng
            if (heap[k] >= heap[j]) break;
            
            // Đổi chỗ cha cho con và tiếp tục chìm
            swap(heap[k], heap[j]);
            k = j;
        }
    }

    void swim(int k) {
        while (k > 0 && heap[(k - 1) / 2] < heap[k]) {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

public:
    // Kích thước hàng đợi
    int size() {
        return heap.size();
    }

    // Kiểm tra hàng đợi có rỗng không
    bool empty() {
        return heap.empty();
    }

    // Lấy phần tử lớn nhất (Tổng giám đốc)
    int top() {
        if (heap.empty()) throw runtime_error("Hang doi rong!");
        return heap[0]; // Luôn nằm trên đỉnh
    }

    // Thêm phần tử mới
    void push(int value) {
        heap.push_back(value);   
        swim(heap.size() - 1);
    }

    // Xóa phần tử lớn nhất
    void pop() {
        if (heap.empty()) return;
        
    
        heap[0] = heap.back(); 

        heap.pop_back();       
        
        if (!heap.empty()) {
            sink(0);
        }
    }
};


