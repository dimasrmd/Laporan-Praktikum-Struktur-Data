#include "stack.h"
#include <iostream>
using namespace std;

int main () {
    stack S;
    createStack(S);

    // 1. Mengambil input dari user
    //    Fungsi ini sudah berisi prompt/pesan untuk user
    getInputStream(S);

    // 2. Menampilkan isi stack awal
    cout << "\n--- Hasil Stack Awal (Urutan LIFO) ---" << endl;
    printInfo(S);

    // 3. Membalik isi stack
    cout << "\n... Memproses balik stack ..." << endl;
    balikStack(S);

    // 4. Menampilkan hasil stack setelah dibalik
    cout << "\n--- Hasil Stack Setelah Dibalik ---" << endl;
    printInfo(S);

    cout << "\n===== Program Selesai =====\n" << endl;
    
    return 0;
}