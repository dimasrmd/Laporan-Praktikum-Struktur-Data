#include <iostream>
using namespace std;
int main () {
    int masookan;
    cin >> masookan;
    for (int i = 0; i <= masookan; i++) { // untuk mengatur seberapa tinggi segitiga / berapa banyak baris yang dibuat sebanyak masukan
        for (int j = 0; j <= masookan*2; j++){ // untuk mengatur seberapa banyak angka tercetak 
            if (masookan - j == 0) { // untuk membuat bagian setelah tanda bintang
                cout << "* "; // membuat tanda bintangnya
                for (int k = 0; k < j; k++) {  // membuat segitiga sebelah kanan tanda bintang
                    if (k+1 <= masookan-i) { // untuk membatasi pencetakan angka di setiap barisnya
                        cout << k + 1 << " ";
                    }
                }
            } else if (j <= masookan) { // untuk segitiga sebelah kiri tanda bintang
                if (j+1 <= i) { // untuk membatasi pencetakan angka setiap barisnya
                    cout << "  ";
                } else { // untuk mencetak angka, setiap baris berkurang 1
                    cout << masookan-j << " ";
                }
            }
        }
        cout << endl;
    }
    
}