#include <iostream>
using namespace std;
int main(){
    string makan;
    cout<<"Masukkan makanan kamu:";
    getline(cin, makan); //Untuk inputan dengan spasi agar bisa ke detect atau membaca inputan dalam satu baris
    cout<<"Makanan kesukaannya adalah"<<makan<<endl;
    return 0;
}