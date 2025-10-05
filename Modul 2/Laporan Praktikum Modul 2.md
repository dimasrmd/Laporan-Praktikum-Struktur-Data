# <h1 align="center">Laporan Praktikum Modul 2</h1>
<p align="center">Dimas Ramadhani</p>
<p align="center">103112400065</p>

## Tujuan Praktikum
1. Mahasiswa dapat menggunakan array pada pembuatan kode program.
2. Mahasiswa dapat menggunakan fungsi dan prosdeut pada pembuatan kode program.
3. Mahasiswa dapat menggunakan pointer dalam menunjukkan alamt suatu variabel. 

## Dasar Teori
### Array
Array adalah sekumpulan data atau elemen yang memiliki tipe data yang sama. Elemen-elemenn itu disimpan didalam memori secara berurutan, dengan cara mengaksesnya melalui indeks array. Array ini sangat penting dalam mengolah data besar yang memiliki tipe yang sama.

```C++
int arr[5]={2, 5, 3, 3, 7};
```
Dari contoh diatas merupakan array bertipe integer dengan banyak data 5. Karena array tersebut memiliki 5 data maka indeks pada array dimulai dari 0 sampai 4, dalam array indeks selalu dimulai dari 0.

Array memiliki 3 jenis yaitu:
**1. Array 1 Dimensi**
Array 1 dimensi adalah sekumpulan array yang memilik 1 baris saja yang ditandai dengan 1 parameter saja. Contoh:

```C++
int arr[5]={2, 5, 3, 3, 7};
```

**2. Array 2 Dimensi**
Array ini dapat digambarkan seperti tabel yaitu memiliki kolom dan baris. Jenis ini ditandai dengan 2 parameter dengan urutan baris dan kolom. Contohnya:

```C++
int nilai[3][4] = {
    {80, 75, 90, 85},  
    {70, 60, 65, 75},  
    {88, 92, 80, 86}
};
```

**3. Array Multidimensi**
Array ini merupakan array yang memiliki dimensi yang lebih dari 2, jadi paramaternya selalu diatas 2. Contohnya:

```C++
int nilai[2][3][4] = {
    { 
        {80, 75, 90, 85},   
        {70, 60, 65, 75},   
        {88, 92, 80, 86}    
    },
    {  
        {90, 85, 88, 92},   
        {77, 69, 80, 73},   
        {84, 90, 79, 95}    
    }
};
```

Manfaat adanya array seperti:
1. Memudahkan dalam mengolah data yang banyak dengan tipe yang sama.
2. Akses yang cepat dan efisien karena menggunakan indeks array.
3. Mendukung multidimensi

### Pointer
Pointer adalah variabel khusus untuk menyimpan alamat memori dari variabel lain, yang secara tidak langsung dapat mengkases nilai dari alamat variabel yang disimpan.

Dalam pointer memiliki beberapa simbol yang dapat digunakan, seperti:
1. Ampersand (&), Digunakan untuk mengambil alamat memori dari variabel yang memiliki simbol ini.
2. Arteris (*), digunakan untuk memunculkan nilai dari alamat yang disimpan dalam pointer.

Cara mendeklarasi pointer:

```C++
int *ptr = &x;
// Artinya variabel ptr adalah pointer bertipe integer akan mendapatkan alamat dari variabel x.
```

Pointer memiliki beberapa jenis, namun saya akan berikan 3 jenis saja yaitu:
#### 1. Pointer dengan Array
Jika suatu pointer diberikan nama variabel array nya saja pada program, maka nilai atau value dari pointer tersebut adalah alamat dari array pertama atau indeks 0. Untuk penulisan dalam kode seperti dibawah:

```C++
int arr[10];
int *ptr = arr; // isi ptr adalah alamat pertama dari array
```

#### 2. Pointer dengan fungsi
Pointer ini yang sering digunakan dalam pemanggilan suatu fungsi. Jenis ini digunakan agar fungsi dapat mengubah nilai dari variabel diluar fungsi atau dikenal sebagai pass by reference. 

```C++
void ubahNilai(int *p) {
    *p = 50;
}

int main() {
    int x = 10;
    ubahNilai(&x);
    cout << x; // hasil: 50
}
```

#### 3. Nullptr 
Artinya adalah pointer kosong, ini berhubungan dengan fungsi. Dalam fungsi, jika pointer diberikan nilai nullptr maka pointer tersebut tidak menunjukkan alamat manapun alias 0. Pointer akan memiliki alamat jika diberikan alamat melalui pemanggilan fungsi pada fungsi utama.

```C++
#include <iostream>
using namespace std;

void tampilkanNilai(int *p) {
    if (p == nullptr)
        cout << "Pointer tidak berisi alamat valid.\n";
    else
        cout << "Nilai yang ditunjuk pointer: " << *p << endl;
}

int main() {
    int a = 42;
    int *ptr = &a;
    int *kosong = nullptr; // value nya 0

    tampilkanNilai(ptr);     // menunjuk ke a
    tampilkanNilai(kosong);  // tidak menunjuk ke apa pun
}
```

### Fungsi
Fungsi adalah sekumpulan kode yang mengembalikan nilai. Biasany fungsi digunakan untuk hal-hal yang membutuhkan perulangan kode yang digunakan secara berkali-kali.

cara penulisan fungsi pada C++ yaitu:
```C++
<tipe data> <nama fungsi> (<parameter>) {
    // isi dari kumpulan kode
    return <nilai>;
}
```

Contoh Program menggunakan fungsi:
```C++
#include <iostream>
using namespace std;

int tambah(int a, int b) {
    return a + b;
}

int main() {
    cout << tambah(3, 5);
}
```

Dengan adanya fungsi dapat memudahkan dalam pembacaan kode dan menjadi terorganisir, memudahkan dalam menangani masalah kode, dan dapat digunakan kembali hanya dengan memanggil fungsinya dan patameter yang ingin di berikan.

### Prosedur
Prosedur dalam C++ itu adalah fungsi yang tipe data void, hal yang membedakannya adalah prosedur menjalankan beberapa output sekaligus tidak hanya mengembalikan nilai.

Cara penulisan prosedur pada C++ yaitu:
```C++
void <nama fungsi> (<parameter>) {
    // Kode-kode yang ingin dikerjakan oleh prosedur
}
```

Contoh Program menggunakan fungsi:
```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Halo, selamat datang di program C++!" << endl;
}

int main() {
    sapa(); // memanggil prosedur
    return 0;
}
```

Karena prosedur adalah fungsi yang bertipe void maka manfaat yang ada juga sama halnya denga fungsi, salah satunya agar mudah dalam memperbaiki baris kode yang bermasalah.

## Guided
### 1. Guided 1
#### Laporan Baca Buku

![guided 1 - code](<screenshoot/guided 1 - code.png>)

**Penjelasan**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    int bukuPerHari[7]={2,1,3,1,4,5,1};
    int totalBuku = 0;
    ...
    int *ptr = &bukuPerHari[0];
    ...
}
```

Ini adalah bagian mendeklarasikan. Jadi pada program yang telah dibuat memiliki 3 buah variabel dengan tipe integer yaitu array `bukuPerHari` untuk mendata buku yang telah dibaca dalam 7 hari, lalu `totalBuku` sebagai tempat total semua buku yang telah dibaca, dan `*ptr` pointer untuk menunjuk alamat dari array indeks 0. 

#### Bagian 3

```C++
int main () {
    ...
     for (int i=0;i<7;i++) {
        // mencetak nilai dari elemen pada indeks ke-i
        cout << "Hari ke-" << i+1 << ": " << bukuPerHari[i] << " buku." << endl;
        totalBuku += bukuPerHari[i];
    }   
    ...
}
```

Bagian ini adalah algoritma yang digunakan yaitu perulangan dengan kondisi. Perulangan ini berfungsi untuk mencetak kembali array yang ada dan menjumlahkan seluruh elemen didalam array sampai batas array nya.

#### Bagian 4

```C++
int main () {
    ...
    cout << "Total buku yang dibaca minggu ini: " << totalBuku << " Buku" << endl;
    cout << ptr << endl << &ptr << endl << *ptr;
}
```

Bagian ini adalah akhir dari program. Jadi program akan mencetak hasil dari algoritma tadi yang mencari total seluruh buku yang telah dibaca.

#### Output:

![guided 1 - output](<screenshoot/guided 1 - output.png>)

**Penjelasan**

Darioutput diatas, dapat dilihat bahwa output sudah sesuai dengan tujuan pembuatan kode.

### 2. Guided 2
#### Diskon

![guided 2 - code](<screenshoot/guided 2 - code.png>)

**Penjelasan**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    float hargaProduk = 50000.0f; // 0f artinya tidak ada angka belakang koma
    // Deklarasi Pointer.
    float* ptrHarga; 
    ptrHarga = &hargaProduk; // memberikan alamat kepada variabel pointer
    ...
}
```

Bagian ini adalah proses pendeklarasian variabel. Dalam program ini dimiliki dua buah variabel bertipe float yaitu variabel `hargaProduk` dan `ptrHarga` yang menunjuk alamat `hargaProduk`.

#### Bagian 3

```C++
int main () {
    ...
    cout << "Harga awal produk: Rp " << hargaProduk << endl;
    cout << "Alamat memori harga: " << ptrHarga << endl;

    cout << "\n...Memberikan diskon 20% melalui pointer..." << endl;
    *ptrHarga= *ptrHarga * 0.8;
    ...
}
```

Bagian ini adalah output awal untuk memberi tahu beberapa hal dan ini merupakan perubahan nilai dari variabel `hargaProduk` melalui `ptrHarga`.

#### Bagian 4

```C++
int main () {
    ...
    cout << "Harga setelah diskon: Rp " << hargaProduk << endl;
    cout << hargaProduk;
    return 0;
}
```

Ini merupakan output akhir setelah value dari `hargaProduk` berubah.

#### Output:

![guided 2 - output](<screenshoot/guided 2 - output.png>)

**Penjelasan**

Dapat dilihat bahwa output diatas sudah sesuai dengan harapan dan perhitungan algoritma.

### 3. Guided 3
#### Laporan Baca Buku

![guided 3 - code](<screenshoot/guided 3 - code.png>)

**Penjelasan**

#### Bagian 1

```C++
float hitungRataRata (int nilaiTugas, int nilaiUTS) { // Buat fungsi
    return (nilaiTugas + nilaiUTS) / 2.0f;
}
```
Ini adalah fungsi tipe float yang bertujuan untuk menghitung nilai rata-rata. Fungsi ini memiliki dua parameter yaitu `nilaiTugas` bertipe integer dan `nilaiUTS` bertipe integer.


#### Bagian 2

```C++
void cetakProfil(string nama, float nilai) { // Buat prosedur
    cout << "Nama: " << nama << endl;
    cout << "Nilai: " << nilai << endl;
}
```

Ini adalah prosedur untuk mencetak profil dari mahasiswa. Prosedur ini menggunakan dua parameter yaitu `nama` tipe string dan `nilai` tipe float. Selanjutnya mengoutputkan kedua variabel/parameter tersebut.

#### Bagian 3

```C++
void beriNilaiBonus(float &nilai) { // Membuat prosedur, ampersand buat akses variabel nilai
    nilai += 5.0f;
}
```

Prosedur ini bertujuan untuk mengubah value variabel `nilai`.

#### Bagian 4

```C++
int main () {
    string namaSiswa = "Asep";
    int tugas = 80, uts = 90;

    float nilaiAkhir = hitungRataRata(tugas, uts); // paramater ini mengambil nilai tugas 80 dan uts 90
    ...
}
```

Bagian ini adalah pendeklarasian beberapa variabel diantaranya `namaSiswa` tipe data string, `tugas` dan `uts` tipe data integer dan `nilaiAkhir` tipe data float.

#### Bagian 5

```C++
int main () {
    ...
    cout << "Profil Awal" << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    cout << "\nMemberikan nilai bonus..." << endl; 
    beriNilaiBonus(nilaiAkhir); // Bonus setelah dihitung rata-rata nya

    cout << "\nProfil setelah bonus"  << endl;
    cetakProfil(namaSiswa, nilaiAkhir);

    return 0;
}
```

Bagian ini adalah proses algoritma dan output yang dihasilkan pada setiap kode. Jadi tugas dari fungsi utama hanya mencetak dan memanggil fungsi lain.

#### Output:

![guided 3 - output](<screenshoot/guided 3 - output.png>)

**Penjelasan**

Dapat dilihat bahwa output sudah benar dan sesuai dengan tujuan pembuatan kode.

## Unguided
### 1. Unguided 1
#### Bonus Buku

![unguided 1 - code](<screenshoot/unguided 1 - code.png>)

#### Bagian 1

```C++
void cetakStok(int arr[], int jumlah, int *ptr = nullptr) { 
    for (int i=0; i<jumlah;i++){
        cout << "Jenis Buku ke-" << i+1 << " ada " << arr[i] << " buku";

        if (&arr[i] == ptr) {
            cout << " << jenis buku ini yang dikasih bonus";
        }
        cout << endl;
    }
}
```

Prosedur ini berfungsi untuk mencetak semua elemen yang ada dalam array, memiliki 3 parameter yaitu variabel `arr[]` tipe data integer, `jumlah` tipe data integer, dan `*ptr` tipe data integer diberikan nilai 0 jika tidak diberikan nilai/value. Algoritma dari prosedur ini menggunakan perulangan sampai dengan `jumlah`, pada percabangan dalam itu berfungsi untuk menandai bahwa buku itu yang diberikan bonus dengan menyamakan alamat pointer dengan alamat array yang memiliki value paling kecil.

#### Bagian 2

```C++
int hitungJumlahBuku(int arr[], int jumlah) {
    int total = 0; // deklarasi variabel total dengan nilai 0.
    for (int i=0; i<jumlah; i++){
        total+=arr[i]; // akan sellau menambahkan setiap elemen array ke variabel total.
    }
    return total; // mengembalikan nilai total.
}
```

Fungsi ini bertujuan untuk menghitung total buku. Fungsi yang bertipe integer ini memiliki 2 parameter yaitu `arr[]` tipe integer dan `jumlah` tipe integer. Algoritma yang digunakan adalah perulangan sampai dengan `jumlah` akan terus menambahkan variabel `total` dengan value array sampai semua array telah dijumlahkan. Dan mengembalikan variabel `total`.

#### Bagian 3

```C++
int *bukuPalingDikit( int arr[], int jumlah) {
    int *ptrBukuDikit = &arr[0]; // memilih alamat array pertama atau indeks 0 sebagai jumlah buku paling sedikit.
    for (int i=1; i<jumlah; i++ ) { // array dimulai dari indeks 1 karena indeks 0 sudah menjadi patokan awal.
        if (arr[i] < *ptrBukuDikit){
            ptrBukuDikit = &arr[i]; // jika kondisi benar, perubahan alamat variabel
        }
    }
    return ptrBukuDikit; // memberikan alamat variabel array yang memiliki nilai paling sedikit
}
```

Fungsi ini merupakan pencarian alamat dalam array yang paling sedikit. Memiliki 2 parameter yaitu `arr[]` tipe integer dan `jumlah` tipe integer. Algoritma yang digunakan adalah perulangan, pertama mendeklarasikan alamat array pertama adalah yang terkecil dengan perulangan akan diperiksa sampai `jumlah`. Fungsi ini mengembalikan alamat dari array melalui pointer `ptrBukuDikit`.

#### Bagian 4

```C++
int main () {
    int arrStok[10] = {67,9,10,3,19,56,31}; // Deklarasi integer array berisi 10 data
    int banyakJenisBuku = 7;
    ...
    int jumlahBUku = hitungJumlahBuku(arrstok, banyakJenisBuku);
    ...
    int *dimasramadhani = bukuPalingDikit(arrStok, banyakJenisBuku);
}
```

Bagian ini adalah fungsi utama dengan proses pendeklarasian 4 variabel yaitu array `arrstok` dengan tipe integer sebanyak 10 data, `banyakJenisBuku` tipe integer, `jumlahBuku` tipe integer dengan memanggil fungsi `hitungJumlahBuku`, dan `*dimasramadhani` merupakan pointer yang menyimpan alamat array yang memiliki value paling kecil melalui pemanggilan fungsi `bukuPalingDikt`.

#### Bagian 5

```C++
int main () {
    ...
    cout << "Jumlah saat ini: \n";
    cetakStok(arrStok, banyakJenisBuku);
    ...
    cout << "Maka jumlah buku saat ini " << jumlahBuku << " buku\n";
    
    cout << "\nsehubung ada acara buku sedunia, Maka buku paling sedikit akan ditambahkan bonus 10 buku\n";
    ...
    *dimasramadhani+=10;
    cetakStok(arrStok, banyakJenisBuku, dimasramadhani);
    
    jumlahBuku = hitungJumlahBuku(arrStok, banyakJenisBuku);
    cout << "Maka jumlah buku setelah diberikan bonus  " << jumlahBuku << " buku\n";
}
```

Bagian ini adalah proses output, pemanggilan fungsi, dan sedikit perhitungan. pada bagian `*dimasramadhani+=10` bertujuan untuk menambahkan value dari alamat yang disimpan dalam pointer bertambah.

#### Output: 

![Unguided 1 - output](<screenshoot/unguided 1 - output.png>)

Dapat dilihat dari output yang diberikan bahwa kode dan output sudah sesuai dengan tujuan pembuatan kode. Diberikan penandaan bonus buku agar dapat mengetahui secara langsung buku mana yang telah diberikan bonus.

## Kesimpulan

Pada praktikum ini telah dipelajari beberapa materi yaitu tentang array, pointer, fungsi dan prosedur. Dengan adanya latihan ini, penulis dapat langsung mengaplikasikan materi yang telah dipelajari dan menyadari bahwa keempat hal ini sangat penting dalam pembuatan kode kedepannya agar lebih terstruktur, mudah dibaca dan tidak terlalu banyak kode yang sama berulang kali.

## referensi
- https://www.youtube.com/watch?v=yKT_Rwx4lsQ
- https://www.codepolitan.com/blog/apa-itu-array-dalam-pemrograman-pengertian-dan-contoh-coding/
- https://www.exabytes.co.id/blog/array/#Manfaat-Array
- https://cplusplus.com/doc/tutorial/pointers/
- https://codingzap.com/pointers-in-c-plus-plus/
- https://sko.dev/wiki/fungsi/