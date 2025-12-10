#include "circularlist.h"

void CreateList(list &L) {
    L.first = Nil;
}

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    address P;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    P = alokasi(x);
    return P;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info.nama = x.nama;
    P->info.nim = x.nim;
    P->info.jenis_kelamin = x.jenis_kelamin;
    P->info.ipk = x.ipk;
    P->next = Nil;
    return P;
}

void dealokasi(list &L, address P) {
    P->next = Nil;
    delete P;
}

void insertFirst(list &L, address P) {
    if (P == Nil) return;
    if (L.first == Nil) {
        L.first = P;
        P->next = P; 
    } else {
        address nodeAkhir = L.first;
        while (nodeAkhir->next != L.first) {
            nodeAkhir = nodeAkhir->next;
        }
        P->next = L.first; // Arahkan pointer next P ke elemen pertama
        nodeAkhir->next = P; // Arahkan node paling akhir dalam list ke node P
        L.first = P; // jadikan P sebagai elemen pertama
    }
}

void insertAfter(list &L, address prec, address P) {
    if (prec == Nil || P == Nil) return;
    if (L.first == Nil) {
        L.first = P;
        P->next = P;
        return;
    }

    P->next = prec->next;
    prec->next = P;
}

void insertLast(list &L, address P) {
    if (P == Nil) return;
    if (L.first == Nil) {
        L.first = P;
        P->next = P;
    } else {
        address nodeAkhir = L.first;
        while (nodeAkhir->next != L.first) {
            nodeAkhir = nodeAkhir->next;
        }
        P->next = L.first; // Arahkan pointer next P ke elemen pertama
        nodeAkhir->next = P; // Arahkan node paling akhir dalam list ke node P
    }
}

void deleteFirst(list &L, address &P) {
    if (L.first == Nil) return;
    P = L.first;
    if (P->next == L.first) {
        L.first = Nil;
    } else {
        address nodeAkhir = L.first;
        while (nodeAkhir->next != L.first) {
            nodeAkhir = nodeAkhir->next;
        }
        nodeAkhir->next = P->next;
        L.first = P->next;
    }

    P->next = Nil;
}

void deleteAfter(list &L, address prec, address &P) {
    if (L.first == Nil || !adaNodeList(L, prec)) return;
    P = prec->next;
    if (P == L.first && P->next == P) {
        L.first = Nil;
        P->next = Nil;
        return;
    }

    if (P == L.first) {
        L.first = L.first->next;
    }

    prec->next = P->next;
    P->next = Nil;
    dealokasi(L, P);
}

void deleteLast(list &L, address &P) {
    if (L.first == Nil) return;
    P = L.first;
    address prec;
    if (P->next == P) {
        L.first = Nil;
    }
    while (P->next != L.first) {
        prec = P;
        P = P->next;
    }
    prec->next = P->next;
    P->next = Nil;
    dealokasi(L, P);
}

address findElm(list &L, infotype x) {
    if (L.first == Nil) return Nil;
    address target = L.first;
    do {
        if (target->info.nim == x.nim) return target;
        target = target->next;
    } while (target != L.first);
    return Nil;
}

bool adaNodeList(list L, address P) {
    if (L.first == Nil || P == Nil) return false;
    address target = L.first;
    do {
        if (target == P) return true;
        target = target->next;
    } while (target != L.first);
    return false;
}

void printInfo(list &L) {
    if (L.first == Nil) {
        cout << "(list kosong)\n";
        return;
    }
    address p = L.first;
    do {
        cout << "Nama : " << p->info.nama << endl 
             << "NIM  : " << p->info.nim << endl
             << "L/P  : " << p->info.jenis_kelamin << endl
             << "IPK  : " << p->info.ipk << "\n\n";
        p = p->next;
    } while (p != L.first);
}
