/*
    * Author: Dimas Ramadhani
    * NIM: 103112400065
    * Deskripsi: kode program untuk memasukkan, menghapus berdasarkan nama, menghitung jumlah nama genap dan menampilkan seluruh list.
*/

#include <iostream>
#include <string>
#define Nil NULL
using namespace std;

typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first;
};

void createList (list &L){
    L.first = Nil;
}

address createNode (infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}

void insertLast (list &L, infotype x) {
    address dimas = createNode(x); 
    if (L.first == Nil) L.first = dimas; 
    else {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        P->next = dimas;
    }
}

void deleteFirst(list &L) {
    address P = L.first;
    L.first = Nil;
    delete P;
}

void deleteAntara(list &L, address elemenHapus, address elemenPatokan) {
    elemenPatokan->next = elemenHapus->next;
    elemenHapus->next = Nil;
    delete elemenHapus;
}

void deleteByName (list &L, infotype x) {
    if (L.first == Nil) {
        cout << "Data kosong!. Tidak dapat menghapus.";
    } else {
        address target = L.first;
        address prev;
        bool ada;
        while (target != Nil && target->info != x) {
            prev = target;
            target = target->next;
            if (target->info == x) ada = true;
        }

        if (!ada) {
            cout << "Nama " << x << " tidak ditemukan.\n";    
        } else {
            if (target == L.first) deleteFirst(L);
            else deleteAntara(L, target, prev);
        }

    }
}

void viewList(list &L) {
    if (L.first == Nil) cout << "List kosong!.";
    else {
        address P = L.first;
        cout << "List nama: ";
        while (P != Nil) {
            cout << P->info << " ";
            P = P->next;
        }
    }
    cout << endl;
}

void hitungNamaGenap(list &L) {
    address ramadhani = L.first;
    int nama;
    int jumlahNama = 0;
    while (ramadhani != Nil) {    
        if (ramadhani->info.length()%2 == 0) {
            cout << ramadhani->info  << " ";
            jumlahNama = jumlahNama + 1;
        }
        ramadhani = ramadhani->next;
    }
    cout << "Jumlah nama mahasiswa dengan jumlah genap: " << jumlahNama;
    cout << endl;
}

int main () {
    list L;
    infotype inputNama;
    int inputMenu;
    createList(L);

    do {
        cout << "------------------\n";
        cout << "1. Insert nama.\n";
        cout << "2. Delete nama.\n";
        cout << "3. View seluruh list.\n";
        cout << "4. Banyak nama mahasiswa dengan jumlah huruf genap.\n";
        cout << "0. exit.\n";
        cin >> inputMenu;
        switch (inputMenu)
        {
        case 0:
            break;
        case 1: // insertLast (Insert nama akhir list)
            cout << "Masukkan nama: ";
            cin >> inputNama;
            insertLast(L, inputNama);
            break;
        case 2: // delete spesifik (Delete nama pertama ditemukan)
            cout << "Masukkan nama untuk delete: ";
            cin >> inputNama;
            deleteByName(L, inputNama);
            break;
        case 3: // view seluruh list
            viewList(L);
            break;
        case 4:
            hitungNamaGenap(L);
            break;
        default:
            cout << "Input tidak valid!\n";
            break;
        }
    } while (inputMenu != 0);
    return 0;
}