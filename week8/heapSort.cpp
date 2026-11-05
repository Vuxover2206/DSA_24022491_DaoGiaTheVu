#include<bits/stdc++.h>

using namespace std;

void sink (vector<int>& arr, int n, int k) {
    while(2*k + 1 < n) {
        int j = 2*k+1; //vi tri left
        
        // con trai con phai solo
        if (j + 1 < n && arr[j] < arr[j+1]) {
            j++
        }

        // solo voi cha
        if (arr[k] >= arr[j]) {
            break;
        }

        swap(arr[j],arr[k]);

        k = j;
    }

}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    //  Xây dựng Max-Heap từ dưới lên trên
    for (int k = n / 2 - 1; k >= 0; k--) {
        sink(arr, n, k);
    }

    // Bước 2: Trích xuất từng phần tử ra khỏi heap
    for (int i = n - 1; i > 0; i--) {
        // Đưa phần tử lớn nhất (root) về cuối mảng
        swap(arr[0], arr[i]);

        // "Chìm" phần tử mới ở root xuống để khôi phục Max-Heap.
        // Kích thước heap lúc này thu hẹp lại chỉ còn i
        sink(arr, i, 0);
    }
}