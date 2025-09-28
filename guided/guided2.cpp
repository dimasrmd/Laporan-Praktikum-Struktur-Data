#include <iostream>
#include <string> //Jangan lupa sertakan headar <string>
#include <vector> //Disarankan untuk penggunaan lebih lanjut (for-loop)
int main(){
    std::string kampus[]={"Universitas Telkom","Universitas Indonesia",
    "Institut Teknologi Bandung", "Universitas Gadjah Mada", "Universitas Airlangga"};
    std::cout<<"Daftar Nama Kampus"<<std::endl;

    // Menggunakan range-based for loop untuk menampilkan setiap elemen
    for(const std::string&namaKampus:kampus){
        std::cout<<"-"<<namaKampus<<std::endl;
    }

    return 0;
}