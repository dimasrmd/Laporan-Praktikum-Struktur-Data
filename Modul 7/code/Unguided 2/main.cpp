#include "stack.h"
#include <iostream>
using namespace std;

int main () {
    stack S;
    createStack(S);

    cout << "--- 1. Pengujian pushAscending ---" << endl;
    cout << "Menambahkan 17, 5, 42, 12, 9, dan 23" << endl;

    // Kumpulan nilai acak
    pushAscending(S, 17);
    pushAscending(S, 5);  // Ini akan menjadi TOP jika stack terurut descending (kecil di atas)
    pushAscending(S, 42); // Ini akan menjadi elemen paling bawah
    pushAscending(S, 12);
    pushAscending(S, 9);
    pushAscending(S, 23);

    cout << "\nHasil stack setelah pushAscending:" << endl;
    printInfo(S); 
    // Output yang diharapkan (tergantung logika ascending/descending Anda):
    // [TOP] 5 9 12 17 23 42 
    // atau
    // [TOP] 42 23 17 12 9 5 

    cout << "\n--- 2. Pengujian balikStack ---" << endl;
    balikStack(S);

    cout << "Hasil stack setelah dibalik (urutan terbalik):" << endl;
    printInfo(S);
    // Output yang diharapkan (kebalikan dari hasil printInfo pertama):
    // [TOP] 42 23 17 12 9 5 
    // atau
    // [TOP] 5 9 12 17 23 42 

    cout << "\n--- 3. Pengujian pop dan push setelah dibalik ---" << endl;
    cout << "Melakukan pop" << endl;
    infotype dataKeluar = pop(S);
    cout << "Data yang keluar: " << dataKeluar << endl;
    
    cout << "Stack setelah di-pop:" << endl;
    printInfo(S);

    cout << "\nMenambahkan 50 (Push Biasa):" << endl;
    push(S, 50); // Menggunakan push biasa (jika ada) untuk menguji
    printInfo(S);
    
    cout << "\nPengujian Selesai." << endl;
    return 0;
}