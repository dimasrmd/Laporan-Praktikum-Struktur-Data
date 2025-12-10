
#include "multilist.h"
#include <iostream>
using namespace std;

int main() {
    listinduk L;
    address_anak elmHapus;
    CreateList(L);

    // ====== Induk awal sesuai contohmu ======
    address a = alokasi(10);
    address b = alokasi(20);
    insertFirst(L, a);
    insertLast(L, b);

    // ====== Tambah lebih banyak induk ======
    address c = alokasi(25);
    insertAfter(L, c, b);        // sisip setelah 20

    address d = alokasi(30);
    insertLast(L, d);

    address e = alokasi(40);
    insertLast(L, e);

    address f = alokasi(50);
    insertLast(L, f);

    address g = alokasi(60);
    insertLast(L, g);

    address h = alokasi(70);
    insertLast(L, h);

    address i = alokasi(80);
    insertLast(L, i);

    // ====== Tambahkan banyak anak ke masing-masing induk ======
    // Induk 10: 1..8
    {
        int vals[] = {1,2,3,4,5,6,7,8};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(a->anak, t);
        }
    }

    // Induk 20: 7..10
    {
        int vals[] = {7,8,9,10};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(b->anak, t);
        }
    }

    // Induk 25: 21..24
    {
        int vals[] = {21,22,23,24};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(c->anak, t);
        }
    }

    // Induk 30: (kosong, biarkan tanpa anak)

    // Induk 40: 100..105
    {
        int vals[] = {100,101,102,103,104,105};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(e->anak, t);
        }
    }

    // Induk 50: 999, 1000
    {
        int vals[] = {999,1000};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(f->anak, t);
        }
    }

    // Induk 60: 42..49
    {
        int vals[] = {42,43,44,45,46,47,48,49};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(g->anak, t);
        }
    }

    // Induk 70: 701..703
    {
        int vals[] = {701,702,703};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(h->anak, t);
        }
    }

    // Induk 80: 801..803
    {
        int vals[] = {801,802,803};
        for (int x : vals) {
            address_anak t = alokasiAnak(x);
            insertLastAnak(i->anak, t);
        }
    }

    // ====== Cetak seluruh isi list (banyak data) ======
    printInfo(L);
    cout << endl;
    
    // ====== Operasi ringan sesuai pola kamu (opsional) ======
    // Hapus induk 10 (anak-anaknya ikut dibersihkan di dalam delP)
    cout << "Menghapus induk 10 beserta anak-anaknya menggunakan 'delP(L, 10);'\n";
    delP(L, 10);
    cout << endl;
    printInfo(L);
    cout << endl;
    
    cout << "Menghapus anak pertama pada induk 25 menggunakan 'delFirstAnak(c->anak, elmHapus);'\n";
    delFirstAnak(c->anak, elmHapus);
    
    // Bersihkan semua
    cout << "Menghapus semua elemen list beserta anak-anaknya menggunakan 'delALL(L);" << endl;
    delAll(L);
    printInfo(L);
    cout << endl;

    return 0;
}
