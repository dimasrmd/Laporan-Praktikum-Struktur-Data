#include <iostream>
using namespace std;

void cetakStok(int arr[], int jumlah, int *ptr = nullptr) { 
// nullptr disini artinya ptr tidak menunjukkan alamat manapun, 
// kecuali jika fungsi diberikan parameter ketiga yang memiliki alamat memori
    for (int i=0; i<jumlah;i++){
        cout << "Jenis Buku ke-" << i+1 << " ada " << arr[i] << " buku";

        if (&arr[i] == ptr) { // untuk menyamakan alamat stok buku dalam array dengan stok buku paling sedikit
            cout << " << jenis buku ini yang dikasih bonus";
        }
        cout << endl;
    }
}

int hitungJumlahBuku(int arr[], int jumlah) {
    int total = 0; // deklarasi variabel total dengan nilai 0.
    for (int i=0; i<jumlah; i++){
        total+=arr[i]; // akan sellau menambahkan setiap elemen array ke variabel total.
    }
    return total; // mengembalikan nilai total.
}

int *bukuPalingDikit( int arr[], int jumlah) {
    int *ptrBukuDikit = &arr[0]; // memilih alamat array pertama atau indeks 0 sebagai jumlah buku paling sedikit.
    for (int i=1; i<jumlah; i++ ) { // array dimulai dari indeks 1 karena indeks 0 sudah menjadi patokan awal.
        if (arr[i] < *ptrBukuDikit){
            ptrBukuDikit = &arr[i]; // jika kondisi benar, perubahan alamat variabel
        }
    }
    return ptrBukuDikit; // memberikan alamat variabel array yang memiliki nilai paling sedikit
}

int main (){
    int arrStok[10] = {67,9,10,3,19,56,31}; // Deklarasi integer array berisi 10 data
    int banyakJenisBuku = 7;
    
    cout << "Jumlah saat ini: \n";
    cetakStok(arrStok, banyakJenisBuku);
    int jumlahBuku = hitungJumlahBuku(arrStok, banyakJenisBuku);
    cout << "Maka jumlah buku saat ini " << jumlahBuku << " buku\n";
    
    cout << "\nsehubung ada acara buku sedunia, Maka buku paling sedikit akan ditambahkan bonus 10 buku\n";
    int *dimasramadhani = bukuPalingDikit(arrStok, banyakJenisBuku); // variabel dimasramadhani menyimpan alamat dari nilai array paling kecil
    *dimasramadhani+=10;
    cetakStok(arrStok, banyakJenisBuku, dimasramadhani);
    
    jumlahBuku = hitungJumlahBuku(arrStok, banyakJenisBuku);
    cout << "Maka jumlah buku setelah diberikan bonus  " << jumlahBuku << " buku\n";
}








// Dimas Ramadhani
// 103112400065
// IF-12-05