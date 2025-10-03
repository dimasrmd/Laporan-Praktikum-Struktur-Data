#include <iostream>
using namespace std;
int main (){
    float hargaProduk = 50000.0f; // 0f artinya tidak ada angka belakang koma
    // Deklarasi Pointer.
    float* ptrHarga; 
    ptrHarga = &hargaProduk; // memberikan alamat kepada variabel pointer

    cout << "Harga awal produk: Rp " << hargaProduk << endl;
    cout << "Alamat memori harga: " << ptrHarga << endl;

    cout << "\n...Memberikan diskon 20% melalui pointer..." << endl;
    *ptrHarga= *ptrHarga * 0.8;
    cout << "Harga setelah diskon: Rp " << hargaProduk << endl;
    cout << hargaProduk;
    return 0;
}