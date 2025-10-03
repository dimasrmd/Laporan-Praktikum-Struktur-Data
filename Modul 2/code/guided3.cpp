#include <iostream>
using namespace std;

float hitungRataRata (int nilaiTugas, int nilaiUTS) { // Buat fungsi
    return (nilaiTugas + nilaiUTS) / 2.0f;
}

void cetakProfil(string nama, float nilai) { // Buat prosedur
    cout << "Nama: " << nama << endl;
    cout << "Nilai: " << nilai << endl;
}

void beriNilaiBonus(float &nilai) { // Membuat prosedur, ampersand buat akses variabel nilai
    nilai += 5.0f;
}
int main (){
    string namaSiswa = "Asep";
    int tugas = 80, uts = 90;

    float nilaiAkhir = hitungRataRata(tugas, uts); // paramater ini mengambil nilai tugas 80 dan uts 90

    cout << "Profil Awal" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout << "\nMemberikan nilai bonus..." << endl; 
    beriNilaiBonus(nilaiAkhir); // Bonus setelah dihitung rata-rata nya

    cout << "\nProfil setelah bonus"  << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    return 0;
}