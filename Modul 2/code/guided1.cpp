#include <iostream>
using namespace std;
int main (){
    int bukuPerHari[7]={2,1,3,1,4,5,1};
    int totalBuku = 0;

    cout << "Laporan Baca Buku Mingguan" << endl;

    // Mengakses setiap elemen array menggunakan loop.
    for (int i=0;i<7;i++) {
        // mencetak nilai dari elemen pada indeks ke-i
        cout << "Hari ke-" << i+1 << ": " << bukuPerHari[i] << " buku." << endl;
        totalBuku += bukuPerHari[i];
    }   

    int *ptr = &bukuPerHari[0];
    cout << "Total buku yang dibaca minggu ini: " << totalBuku << " Buku" << endl;
    cout << ptr << endl << &ptr << endl << *ptr;
}