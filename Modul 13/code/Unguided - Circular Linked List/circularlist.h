#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct elmList *address;
typedef struct mahasiswa infotype;

struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

struct elmList {
    infotype info;
    address next;
};

struct list {
    address first;
};

// Membuat list baru
void CreateList(list &L);

// Membuat node baru dengan parameter sekumpulan data
address createData(string nama, string nim, char jenis_kelamin, float ipk);

// mengalokasikan data ke memori
address alokasi(infotype x);

// menghapus node dari memori
void dealokasi(list &L, address P);

// Input node P ke posisi awal pada list
void insertFirst(list &L, address P);

// Input node P ke posisi setelah node prec
void insertAfter(list &L, address prec, address P);

// Input node P ke posisi akhir pada list
void insertLast(list &L, address P);

// Hapus node pertama pada list
void deleteFirst(list &L, address &P);

// Hapus node P setelah node prec
void deleteAfter(list &L, address prec, address &P);

// Hapus node terakhir dalam list
void deleteLast(list &L, address &P);

// Mencari node yang memiliki info tertentu
address findElm(list &L, infotype x);

// Mencari apakah ada node P didalam list
bool adaNodeList(list L, address P);

// Mencetak semua node dalam list
void printInfo(list &L);

#endif