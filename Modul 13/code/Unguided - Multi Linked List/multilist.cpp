#include "multilist.h"
#include <iostream>
using namespace std;

bool ListEmpty(listinduk L) {
    return L.first == Nil;
}

bool ListEmptyAnak(listanak L) {
    return L.first == Nil;
}

void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk x) {
    address P = new elemen_list_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

address_anak alokasiAnak(infotypeanak x) {
    address_anak P = new elemen_list_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address P) {
    // P->info = Nil;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    delete P;
}

void dealokasiAnak(address_anak P) {
    // P->info = Nil;
    P->next = Nil;
    P->prev = Nil;
    delete P;
}

address findElm(listinduk L, infotypeinduk x) {
    if (L.first == Nil) {
        return Nil;
    }

    address P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

address_anak findElm(listanak L, infotypeanak x) {
    if (L.first == Nil) {
        return Nil;
    }

    address_anak P = L.first;
    while (P != Nil) {
        if (P->info == x) return P;
        P = P->next;
    }
    return Nil;
}

bool fFindElm(listinduk L, address P) {
    address Q = L.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

bool fFindElmAnak(listanak L, address_anak P) {
    address_anak Q = L.first;
    while (Q != Nil) {
        if (Q == P) return true;
        Q = Q->next;
    }
    return false;
}

address findBefore(listinduk L, address P) {
   if (L.first == Nil || !fFindElm(L, P)) return Nil;
   return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeinduk x, address_anak P) {
    if (L.first == Nil || P == Nil || L.first == P) return Nil;
    address_anak Q = L.first;
    address_anak prec = Nil;
    while (Q != Nil) {
        if (Q == P && P->info == x) return Q->prev;
        prec = Q;
        Q = Q->next;
    }
    return Nil;
}

void insertFirst(listinduk &L, address P) {
    if (P == Nil) return;
    if (ListEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (P == Nil) return;
    if (ListEmpty(L)) {
        insertFirst(L, P);
        return;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }

}

void insertAfter(listinduk &L, address P, address prec) {
    if (P == Nil || prec == Nil || (!fFindElm(L, prec))) return;
    if (prec == L.last) {
        insertLast(L, P);
        return;
    }
    P->next = prec->next;
    P->prev = prec;
    prec->next->prev = P;
    prec->next = P;
}

void insertFirstAnak(listanak &L, address_anak P){
    if (P == Nil) return;
    if (ListEmptyAnak(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (P == Nil) return;
    if (ListEmptyAnak(L)) {
        insertFirstAnak(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak prec) {
    if (P == Nil || prec == Nil || !fFindElmAnak(L, prec)) return;
    if (prec == L.last) {
        insertLastAnak(L, P);
    } else {
        P->next = prec->next;
        P->prev = prec;
        prec->next->prev = P;
        prec->next = P;
    }
}

void delFirst(listinduk &L, address &P) {
    P = Nil;
    if (ListEmpty(L)) return;
    P = L.first;
    address Q = P->next;
    L.first = Q;
    
    if (Q == Nil) {
        L.last = Nil;
    } else {
        Q->prev = Nil;
    }

    P->next = Nil;
    P->prev = Nil;
}

void delLast(listinduk &L, address &P) {
    P = Nil;
    if (ListEmpty(L)) return;
    P = L.last;
    address Q = P->prev;
    L.last = Q;
    if (Q == Nil) {
        L.first = Nil;
    } else {
        Q->next = Nil;
    }
    P->prev = Nil;
}

void delAfter(listinduk &L, address &P, address prec) {
    P = Nil;
    if(ListEmpty(L) || prec == Nil || !fFindElm(L, prec) || prec == L.last) return;
    address Q = prec->next;
    P = Q; // elemen hapus disimpan ke P
    if (Q->next == Nil) {
        L.last = prec;
    } else {
        prec->next = Q->next;
        Q->next->prev = prec;
    }

    P->next = Nil;
    P->prev = Nil;    
}

void delP(listinduk &L, infotypeinduk x) {
    address P = findElm(L, x);
    if (P == Nil) return; // cek kondisi list kosong atau P tidak ada.
    address_anak anak;
    if (!ListEmptyAnak(P->anak)) {
        delFirstAnak(P->anak, anak);
        dealokasiAnak(anak);
    }
    if (P == L.first) {
        delFirst(L, P);
    } else if (P == L.last) {
        delLast(L, P);
    } else {
        address X;
        delAfter(L, X, P->prev);
        P = X;
    }


    delete P;
}

// delete untuk linkedlist anak
void delFirstAnak(listanak &L, address_anak &P) {
    P = Nil;
    if (ListEmptyAnak(L)) return;
    P = L.first;
    if (P->next == Nil) {
        L.first = L.last = Nil;
    } else {
        L.first = P->next;
        L.first->prev = Nil;
    }

    P->next = Nil;
}

void delLastAnak(listanak &L, address_anak &P) {
    P = Nil;
    if (ListEmptyAnak(L)) return;
    P = L.last;
    if (P->prev == Nil) {
        L.first = L.last = Nil;
    } else {
        L.last = P->prev;
        L.last->next = Nil;
    }

    P->prev = Nil;
}

void delAfterAnak(listanak &L, address_anak &P, address_anak prec) {
    P = Nil;
    if(ListEmptyAnak(L) || prec == Nil || !fFindElmAnak(L, prec) || prec == L.last) return;
    address_anak Q = prec->next;
    P = Q; // elemen hapus disimpan ke P
    if (Q->next == Nil) {
        L.last = prec;
    } else {
        prec->next = Q->next;
        Q->next->prev = prec;
    }

    P->next = Nil;
    P->prev = Nil;    

}

void delPAnak(listanak &L, infotypeanak x) {
    address_anak P = findElm(L, x);
    if (P == Nil) return; // cek kondisi list kosong atau P tidak ada.
    if (P == L.first) {
        delFirstAnak(L, P);
    } else if (P == L.last) {
        delLastAnak(L, P);
    } else {
        address_anak X;
        delAfterAnak(L, X, P->prev);
        P = X;
    }

    delete P;
}

// print seluruh infonya
void printInfo(listinduk L) {
    if (ListEmpty(L)) {
        cout << "List induk kosong." << endl;
       return;
    }
    address P = L.first;
    while (P != Nil) {
        cout << "Induk: " << P->info;
        printInfoAnak(P->anak);
        cout << endl;
        P = P->next;
    }
}

int nbList(listinduk L) {
    int n = 0;
    address P = L.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}
/* mengembalikan jumlah elemen pada list */ 
 
void printInfoAnak(listanak anak) {
    if (ListEmptyAnak(anak)) {
        cout << " List anak kosong.";
       return;
    }
    cout << " anak : ";
    address_anak P = anak.first;
    while (P != Nil) {
        cout << P->info << ", ";
        P = P->next;
    }
}
 
int nbListAnak(listanak anak) {
    int n = 0;
    address_anak P = anak.first;
    while (P != Nil) {
        n++;
        P = P->next;
    }
    return n;
}
 
void delAll(listinduk &L) {
    address P;
    while (!ListEmpty(L)) {
        delFirst(L, P);
        address_anak anak;
        while (!ListEmptyAnak(P->anak)) {
            delFirstAnak(P->anak, anak);
            dealokasiAnak(anak);
        }
        dealokasi(P);
    }
}