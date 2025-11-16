#include "queue.h"
#include <iostream>

using namespace std;

//Definisi prosedur untuk membuat queue kosong
void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0; // Set jumlah elemen ke 0
}

// Definisi fungsi untuk mengecek apakah queue kosong
bool isEmpty(Queue Q) {
    return Q.count == 0; // Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // kembalikan true jika jumlah elmen sama dengan maks
}

void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { // jika queue tidak penuh
        Q.info[Q.tail] = x; // masukkan data (x) ke posisi ekor (tail)
        //Piindahkan ekor secara particular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++; // tambah jumlah elemen
    } else { // jika queue penuh
        cout << "Antrian Penuh!" << endl; // tampilkan pesan eror
    }
}

int dequeue(Queue &Q) {
    if (!isEmpty(Q)) {
        int x = Q.info[Q.head]; // Ambil data di posisi kepala
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // kurangi jumlah elemen
        return x; // kembalikan data yang diambil
    } else { // jika queue kosong
        cout << "Antrean Kosong!" << endl; // tampilkan pesan eror
        return -1; // kembalikan nilai -1 sebagai tanda eror
    }
}

void printInfo(Queue Q) {
    cout << "Isi queue: [ ";
    if (!isEmpty(Q)) { // Jika data tidak kosong
        int i = Q.head; // mulai dari kepala
        int n = 0; // penghitung elemen yang sudah dicetak
        while (n < Q.count) { // ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // cetak
            i = (i + 1) % MAX_QUEUE; // geser 'i' secara circular
            n++; // tambah penghitung;
        }
        cout << "]" << endl;
    } else { // jika kosong
        cout << "Antrean Kosong! ]" << endl; // menampilkan pesan data kosong
    }
}