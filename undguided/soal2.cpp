#include <iostream>
using namespace std;
int main () {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
        "enam", "tujuh", "delapan", "sembilan"}; // berisi kalimat angka satuan
    string puluhan[] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", 
        "delapan puluh", "sembilan puluh"}; // berisi kalimat angka puluhan
    int masukan; // Sebagai inputan pengguna
    int digitKe1; // digitKe1 sebagai tempat untuk digit pertama/satuan
    int digitKe2; // digitKedua sebagai tempat untuk digit kedua/puluhan
    cout << "Masukkan angka dari 0 s.d 100: ";
    cin >> masukan; // Pengguna menginputkan angka
    if (masukan >= 0 && masukan <= 100) { // untuk memastikan inputan berkisar 0 sampai dengan 100
        digitKe1 = masukan % 10; // untuk mendapatkan satuan
        digitKe2 = masukan / 10; // untuk mendapatkan puluhan
        if (digitKe2 == 10) {
            cout << "seratus";
        } else if (digitKe2 > 0 && digitKe1 == 0) {
            cout << puluhan[digitKe2];
        } else if  (digitKe2 > 0 && digitKe1 > 0) {
            cout << puluhan[digitKe2] << " " << satuan[digitKe1];
        } else if (digitKe1 > 0 && digitKe2 == 0) {
            cout << satuan[digitKe1];
        }
    } else {
        cout << "Harap masukkan antara 0 sampai dengan 100";
    }
    return 0;
}