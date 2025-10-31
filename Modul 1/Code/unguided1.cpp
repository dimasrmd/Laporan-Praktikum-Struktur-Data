#include <iostream>
using namespace std;
int main (){
    float inp1, inp2, penjumlahan, pengurangan, perkalian, pembagian;
    cout << "--------- Input --------" << endl;
    cout << "Masukkan angka pertama: ";
    cin >> inp1; // inputan angka pertama
    cout << "Masukkan angka kedua: ";
    cin >> inp2; // inputan angka kedua
    cout << endl; // untuk memisahkan input dengan output
    cout << "-------- Output --------" << endl;
    cout << "Hasil penjumlahan " << inp1 << " + " << inp2 << " adalah " << inp1 + inp2 << endl;
    cout << "Hasil pengurangan " << inp1 << " - " << inp2 << " adalah " << inp1 - inp2 << endl;
    cout << "Hasil perkalian " << inp1 << " x " << inp2 << " adalah " << inp1 * inp2 << endl;
    if (inp2 != 0) { //untuk mengindetifikasi penyebut 0 atau tidak
        cout << "Hasil pembagian " << inp1 << " / " << inp2 << " adalah " << inp1 / inp2 << endl;
    } else { // jika 0 maka hasilnya tak terdefinisi
        cout << "Karena penyebut 0, maka hasilnya tak terdefinisi" << endl;
    }
    return 0;
}








// Dimas Ramadhani
// 103112400065
// IF-12-05