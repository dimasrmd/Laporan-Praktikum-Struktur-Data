# <h1 align="center">Laporan Praktikum Modul 1</h1>
<p align="center">Dimas Ramadhani</p>
<p align="Center">103112400065</p>

## Tujuan Praktikum

1. Mengulas Kembali dasar-dasar algoritma dari yang telah dipelajari pada semester 1 dan 2
2. Melatih problem solving dalam menyelesaikan masalah 
3. Mempelajari dasar-dasar dari bahasa C++

## Dasar Teori

C++ merupakan peningkatan fitur dan pengoperasian dalam perkodean dari bahasa C. peningkatan ini ditandai dengan ++, tanda tersebut merupakan bentuk pertambahan nilai dari suatu variabel pada bahasa C.
C++ Adalah bahasa yang menggunakan pemrograman berorientasi objek (OOP). Object Oriented Programming atau disingkat OOP merupakan model pemrograman yang menggunakan objek untuk pengembangan perangkat lunak yang meliputi kelas, objek, metode dan atribut.
Karena C++ menggunakan pemrograman berorientasi objek, C++ dapat digunakan dalam pengembangan perangkat lunak, pengembangan game, web browser dan banyak bidang lainnya.

## Guided
### 1. Guided 1
#### Perbelanjaan

![Code Guided 1](<Screenshoot/guided1 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    double total_pembelian, diskon;
    ...
}
```

`int main () {}` adalah tempat dimana seluruh kode algoritma berada. Lalu hal pertama di dalam itu adalah pembuatan variabel, variabel total_pembelian dan variabel diskon bertipekan double.

#### Bagian 3

```C++
int main () {
    ...
    cout << "Berapa kamu belanja: Rp. ";
    cin >> total_pembelian;
    ... 
}
```

Pada bagian ini program mencetak kalimat menggunakan `cout` dan akan mendapatkan inputan menggunakan `cin` kedalam variabel `total_pembelian`.

#### Bagian 4

```C++
int main () {
    ...
     if (total_pembelian >= 30000){
        diskon = 0.1 * total_pembelian;
        cout << "Kamu dapat diskon sebesar " << diskon << " orang kaya lu tong";
    } else {
        cout << "Kamu belanjanya masih dikit, tambahin lah, biar gua kaya";
    }
}
```

Ini adalah algoritma yang digunakan menggunakan percabangan. Jadi jika inputan lebih dari `30000` akan mendapatkan diskon, namun jika dibawah `30000` tidak mendapatkan diskon.

#### Ouput :

![Output Guided 1](<Screenshoot/guided1- ouput.png>)

**Penjelasan:**

Dari output diatas dapat tergambarkan bahwa program berjalan sesuai dengan algoritma dan tujuan, yang dimana jika kita berbelanja dengan harga lebih dari `30000` maka akan mendapatkan diskon sebesar `10%` dan jika kurang dari `30000` tidak mendapatkan diskon tersebut.

### 2. Guided 2
#### Increment

![Code Guided 2](<Screenshoot/guided2 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    int r=20;
    int s;
    ...
}
```

Disini kita mendeklarasikan dua variabel bertipekan integer yaitu `r` dan `s`. Yang dimana `r` diberi nilai 20.

#### Bagian 3

```C++
int main () {
    ...
    s=20+ ++r;//r=20 --> r++ = 20+1 ==> s + 21 = 41
    cout << "Nilai r saat ini "<<r<<endl;
    cout<<"Nilai s saat ini "<<s<<endl;
    return 0;
}
```

Ini adalah algoritma nya sekaligus ouput yang akan dikelauarkan menggunakan `cout`. Jadi algoritma disini akan memberikan nilai pada `s` yaitu `20 + ++r` yang dimana tanda `++` disebelah kiri variabel artinya variabel tersebut akan bertambah `1` nilai dari aslinya.

#### Ouput :

![Output Guided 2](<Screenshoot/guided2 - output.png>)

**Penjelasan:**

Dari output tersebut artinya nilai `r` bertambah `1` karena pada algoritma variabel `r` memiliki `++`. Lalu variabel `s` merupakan penjumlahan dari `20 + ++r`.

### 3. Guided 3
#### Konversi Suhu

![Code Guided 3](<Screenshoot/guided3 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    float celcius, fahrenheit;
    ...
}
```

Bagian ini merupakan pendeklarasian variabel, yaitu `celcius` dan `fahrenheit` bertipe float.

#### Bagian 3

```C++
int main () {
    ...
    cout << "Tulis sedingin apa gebetan lu: ";
    cin >> celcius;
    ...
}
```

Bagian ini merupakan interaksi awal program dengan pengguna, yaitu program akan mencetak kalimat menggunakan `cout` dan program akan meminta atau membaca input dari pengguna menggunakan `cin` ke dalam variabel celcius.

#### Bagian 4

```C++
int main () {
    ...
    fahrenheit=(9.0/5.0)*celcius+32;
    cout<<"Kalau di fahrenheit itu " << fahrenheit <<" derajat"<<endl;
    cout<<"Itu dingin banget sih, saran gua jauhin aja";
    return 0;
}
```

Ini adalah algoritma sekaligus output atau hasil dari perhitungan algoritmanya. Jadi disini variabel `fahrenheit` diberikan nilai dari hasil rumus konversi suhu celcius ke fahrenheit. Lalu program akan mencetak hasil dari perhitungan sebelumnya beserta beberapa keterangan kecil.

#### Output :

![output Guided 3](<Screenshoot/guided3 - output.png>)

**Penjelasan:**

Dari output diatas, dapat kita lihat hasil dari koversi suhu celcius ke fahrenheit bekerja sesuai dengan rumus yang diberikan.

## Unguided
### 1. Unguided 1
#### Matematika Dasar

![Code Unguided 1](<Screenshoot/unguided1 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    float inp1, inp2, penjumlahan, pengurangan, perkalian, pembagian;
    ...
}
```

Bagian ini merupakan proses pendeklarasian variabel, seperti `inp1` dan `inp2` untuk inputan dari pengguna, `penjumlahan` sebagai tempat hasil penjumlahan dari dua inputan user, `pengurangan`, `perkalian`, dan `pemabgian` pun mengoperasikan perhitungan matematika sesuai nama variabelnya.

#### Bagian 3

```C++
int main () {
    ...
    cout << "--------- Input --------" << endl;
    cout << "Masukkan angka pertama: ";
    cin >> inp1; // inputan angka pertama
    cout << "Masukkan angka kedua: ";
    cin >> inp2; // inputan angka kedua
    cout << endl; // untuk memisahkan input dengan output
    cout << "-------- Output --------" << endl;
    ...
}
```

Bagian ini merupakan proses input dari pengguna. Di dalam kode-kode ini program akan mencetak menggunakan `cout` dan membaca inputan menggunakan `cin` kepada variabel yang dituju.

#### Bagian 4

```C++
int main () {
    ...
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
```

Bagian ini adalah alogritma program dan output hasilnya. Pertama program akan mencetak hasil dari `penjumlahan` yang berasal dari `inp1 + inp2` dan membuat baris baru menggunakan `endl`. Lalu program mencetak hasil dari `pengurangan` lalu `perkalian`. Dan untuk pembagian menggunakan percabangan karena jika penyebut 0 maka hasilnya `tak terdefinisi`.

#### Output :

![Output Unguided 1](<Screenshoot/unguided1 - output.png>)

**Penjelasan:**

Dapat dilihat dari output diatas bahwa dua inputan dari pengguna telah dihitung oleh program menggunakan rumus-rumus yang sesuai dengan kategorinya dan khusus untuk pembagian jika inputan kedua / penyebut adalah 0 maka hasilnya menjadi tak terdefinisi.

### 2. Unguided 2
#### Pengejaan angka

![Code Unguided 2](<Screenshoot/unguided2 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", 
        "enam", "tujuh", "delapan", "sembilan"}; // berisi kalimat angka satuan
    string puluhan[] = {"", "sepuluh", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", 
        "tujuh puluh", "delapan puluh", "sembilan puluh"}; // berisi kalimat angka puluhan
    int masukan; // Sebagai inputan pengguna
    int digitKe1; // digitKe1 sebagai tempat untuk digit pertama/satuan
    int digitKe2; // digitKedua sebagai tempat untuk digit kedua/puluhan
    ...
}
```

Bagian ini adalah pendeklarasian beberapa variabel. Untuk tipe data string berbentuk array seperti `satuan` dan  `puluhan`, variabel `satuan` berisi angka `0-9` sedangkan `puluhan` berisi semua angka kelipatan 10 dari `10 sampai 90`. Lalu variabel bertipe integer seperti `masukan` sebagai inputan pengguna, `digitKe1` sebagai tempat untuk digit pertama, dan `digitKe2` sebagai tempat untuk digit kedua.

#### Bagian 3

```C++
int main () {
    ...
    cout << "Masukkan angka dari 0 s.d 100: ";
    cin >> masukan; // Pengguna menginputkan angka
    ...
}
```

Bagian ini akan mencetak kalimat menggunakan `cout` dan membaca inputan dari pengguna berupa angka kedalam variabel `masukan`.

#### Bagian 4

```C++
int main () {
    ...
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
```
Bagian ini merupakan algoritma sekaligus output dari hasil algoritma nya. Algoritma ini menggunakan beberapa percabangan. Yang intinya algoritma percabangan ini akan mengarahkan inputan sesuai dengan kondisi yang berlaku. Sebelum masuk ke percabangan kedua, dilakukan perhitungan modulo dan pembagian untuk mendapatkan digit ke 1 dan digit kedua dari `masukan`. 

#### Output :

![Output Unguided 2](<Screenshoot/unguided2 - output.png>)

**penjelasan:**

Dapat dilihat dari output, jika kita memasukkan angka dari 0 sampai dengan 100 maka program akan mengenali angka tersebut melalui algoritma yang telah dibuat dan mengejakannya dengan mencetak kalimat di akhir program.

### 3. Unguided 3
#### Segitiga terbalik

![Code Unguided 3](<Screenshoot/unguided3 - code.png>)

**Penjelasan:**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya.

#### Bagian 2

```C++
int main () {
    int masookan;
    cout << "Mau seberapa tinggi segitiga nya (inputan kamu + 1)? ";
    cin >> masookan;
}
```

Bagian ini merupakan pendeklarasian dan pemasukan input dari pengguna. Variabel yang dideklarasi yaitu `masookan` tipe integer sebagai tempat inputan pengguna. Lalu program akan membaca inputan menggunakan `cin` ke variabel `masookan`. variabel `masookan` ini berfungsi untuk mengatur seberapa tinggi segitiga yang diinginkan.

#### Bagian 3

```C++
int main () {
    ...
    for (int i = 0; i <= masookan; i++) { // untuk mengatur seberapa tinggi segitiga / berapa banyak baris yang dibuat sebanyak masukan
        ...
        cout << endl;
    }
}
```

Pada program utama ini digunakan algoritma perulangan, ini adalah perulangan terluar atau perulangan pertama yang berfungsi untuk mengatur seberapa tinggi segitiga sesuai dengan `masookan`.

#### Bagian 4

```C++
int main () {
    ..
        for (int j = 0; j <= masookan*2; j++){ // untuk mengatur seberapa banyak angka tercetak 
            ...
        }
    ...
}
```

Ini adalah perulangan kedua dengan didalamnya ada beberapa percabangan. Jadi perulangan ini berfungsi untuk mengatur lebar nya angka yang tercetak.

#### Bagian 5

```C++
int main () {
    ...
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
    ...
}
```

Didalam perulangan kedua terdapat beberapa percabangan untuk membuat tanda bintang agar berada ditengah. Percabangan pertama untuk memastikan kondisi yang benar untuk membuat segitiga sebelah kanan bintang, sedangkan selain itu untuk memastikan untuk dapat membuat segitiga sebelum tanda bintang. Dalam percabangan pertama, terdapat perulangan yang berfungsi untuk membuat segiitga sebelah kanan bintang. Pada percabangan kedua, didalamnya terdapat algoritma yang berfungsi untuk mencetak segitiga sebelah kiri tanda bintang.

#### Output :

![Output Unguided 3](<Screenshoot/unguided3 - output.png>)

**Penjelasan:**

Dari output diatas, dapat terlihat bahwa jika kita menginputkan angka 6 maka angka awal dimulai dari angka 6 dan akan berkurang di setiap barisnya sampai dengan 0.

## Kesimpulan

Pada praktikum kali ini, kita diajarkan kembali algoritma dasar dari pemrograman seperti mencetak, membaca inputan, menggunakan percabangan, menggunakan perulangan, dan beberapa tipe data untuk membuat variabel namun menggunakan bahasa C++.
Dengan adanya praktikum ini mahasiswa dapat mengasah kembali skill problem solving pada pemrograman algoritma ini.

## Referensi
https://www.revou.co/id/kosakata/bahasa-cpp
https://www.petanikode.com/cpp-untuk-pemula/#:~:text=Apa%20itu%20C++?,yang%20dibuat%20oleh%20Bjarne%20Stroustrup%20.&text=Seperti%20namanya%2C%20Simbol%20%E2%80%9C%20++%20%E2%80%9D,Mengapa%20bisa%20begitu?
https://www.techtarget.com/searchapparchitecture/definition/object-oriented-programming-OOP
https://www.gamelab.id/news/2677-bahasa-pemrograman-c-sejarah-fitur-kelebihan-dan-pengembangannya-dalam-industri#:~:text=C++%20digunakan%20secara%20luas%20dalam,lunak%20grafis%2C%20dan%20aplikasi%20desktop.