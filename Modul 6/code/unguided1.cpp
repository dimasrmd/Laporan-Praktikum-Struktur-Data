/* 
Unguided 1: 
Memodifikasi kode guided 1 dengan menambahkan
fungsi insertBefore dan printReverse
*/
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // membuat tipe data baru yang memiliki tipe data dasar integer
typedef struct elmlist *address; // membuat tipe data struct yang menunjuk elemenlist (pointer)

struct elmlist {
    infotype info;
    address next;
    address prev;
}; // ini adalah isi dari node atau elemen list nya

struct List {
    address first;
    address last;
}; // ini adalah pointer yang menunjukkan elemen pertama dan terakhir

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R){
    P -> next = R -> next;
    P -> prev = R;
    if (R -> next != Nil) R -> next -> prev = P;
    else L.last = P;
    R -> next = P;
}

address alokasi(infotype x){ // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void printInfo(List L){
    address P = L.first;
    cout << "Forward: ";
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

/* Bagian modifikasi atau penyelesaian soalnya */

void insertBefore(List &L, address P, address R){ 
// P untuk data yang dimasukkan, R untuk patokan pemasukan data
    P -> prev = R -> prev;
    P -> next = R;
    if (R -> prev != Nil) R -> prev -> next = P;
    else L.first = P;
    R -> prev = P;
    cout << "Berhasil insert " << P -> info << " sebelum " << R -> info;
    cout << endl; 
} // ini adalah masuk sebeleum, kebalikan dari masuk setelah

void printReverse(List L) {
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> prev;
    }
    cout << endl;
}

/* ------------------------------------------------- */

int main (){
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "TASK 1: INSERT OPERATION\n";
    address P1 = alokasi(1);
    insertFirst(L, P1);
    address P2 = alokasi(3);
    insertLast(L, P2);
    address P3 = alokasi(2);
    insertAfter(L, P3, P2);
    cout << "List awal: \n";
    printInfo(L);
    printReverse(L);

    address P4 = alokasi(4);
    insertBefore(L, P4, P3);
    address P5 = alokasi(5);
    insertBefore(L, P5, P1);

    cout << "List setelah insert before:\n";
    printInfo(L);
    printReverse(L);
    return 0;
}