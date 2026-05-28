#include <iostream>
using namespace std;

// Ham in mang ra man hinh
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Ham vun dong (heapify)
void heapify(int a[], int n, int i) {
    int max_idx = i; // tam thoi coi goc la lon nhat
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    // Kiem tra xem con trai co lon hon goc khong
    if (trai < n && a[trai] > a[max_idx]) {
        max_idx = trai;
    }

    // Kiem tra xem con phai co lon hon max hien tai khong
    if (phai < n && a[phai] > a[max_idx]) {
        max_idx = phai;
    }

    // Neu goc khong phai lon nhat thi doi cho
    if (max_idx != i) {
        // Doi cho dung bien tam (logic cui cui cho giong sinh vien)
        int tam = a[i];
        a[i] = a[max_idx];
        a[max_idx] = tam;

        // Goi de quy de vun dong tiep phan ben duoi
        heapify(a, n, max_idx);
    }
}

void heapSort(int a[], int n) {
    cout << "--- Giai doan 1: Vun dong (Build Heap) ---" << endl;
    // Vun dong tu duoi len tren
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
        cout << "Buoc vun dong i = " << i << ": ";
        inMang(a, n);
    }

    cout << "\n--- Giai doan 2: Sap xep ---" << endl;
    for (int i = n - 1; i > 0; i--) {
        // Doi phan tu lon nhat (a[0]) xuong cuoi mang
        int tam = a[0];
        a[0] = a[i];
        a[i] = tam;

        cout << "Dua max " << a[i] << " xuong cuoi: ";
        inMang(a, n);

        // Vun dong lai phan con lai cua mang (kich thuoc i)
        heapify(a, i, 0);
        cout << "Sau khi vun dong lai:  ";
        inMang(a, n);
    }
}

int main() {
    // Cau nho thay cac so nay bang so tren bang hoac trong slide nhe
    int a[] = {12, 11, 13, 5, 6, 7};
    
    // Tinh so luong phan tu cua mang
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Mang ban dau ne: ";
    inMang(a, n);
    cout << endl;

    // Goi ham sap xep
    heapSort(a, n);

    cout << "\nKet qua cuoi cung: ";
    inMang(a, n);

    return 0;
}
