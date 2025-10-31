/* Modifiasi dari guided 2 atau dll_hapus */
#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = L.first -> next;
    if (L.first != Nil) L.first -> prev = Nil;
    else L.last = Nil;
    P -> next = Nil;
    P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last -> prev;
    if (L.last != Nil) L.last -> next = Nil; 
    else L.first = Nil;
    P -> prev = Nil;
    P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next;
    R -> next = P -> next;
    if (P -> next != Nil) P -> next -> prev = R;
    else L.last = R;
    P -> prev = Nil;
    P -> next = Nil;
}

/* Bagian modifikasi atau penyelesaian masalah pada soal */
void deleteByValue(List &L, infotype val) {
    address R;
    bool cekAda = false;
    address P = L.first;
    while (P != Nil && !cekAda) {
        if (P->info == val) {
            if (P = L.first) {
                deleteFirst(L, P);
            } else if (P = L.last) {
                deleteLast(L, P);
            } else {
                R = P->prev;
                deleteAfter(L, P, R);
            }
            cekAda = true;
            cout << "Data " << val << " berhasil di hapus\n";
        }
        P = P->next;
    }
    
    if (!cekAda) {
        cout << "Data " << val << " tidak ditemukan\n";
        cout << "List tetap: ";
        printInfo(L);
    } else {
        dealokasi(P);
    }
}

void deleteAll(List &L){
    address P;
    int x;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
        x++;
    }
    cout << "semua elemen (" << x << ") berhasil dihapus";
}

int main (){
    List L;
    address P;
    L.first = Nil;
    L.last = Nil;
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(17));
    insertFirst(L, alokasi(67));
    insertFirst(L, alokasi(99));
    cout << "List awal: ";
    printInfo(L);
    
    deleteFirst(L, P);
    dealokasi(P);
    deleteAfter(L, P, L.first);
    dealokasi(P);
    cout << "List setelah penghapusan awal: ";
    printInfo(L);
    
    deleteByValue(L, 1);
    cout << "List setelah deleteByValue(1): ";
    printInfo(L);
    deleteByValue(L, 5);
    
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(9));
    insertFirst(L, alokasi(10));
    cout << "List setelah penambahan data: ";
    printInfo(L);
    deleteAll(L);
    printInfo(L);
    return 0;
}