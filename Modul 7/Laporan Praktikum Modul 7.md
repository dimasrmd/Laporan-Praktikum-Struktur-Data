# <h1 align="center">Laporan Praktikum Modul 7</h1>
<p align="center">Dimas Ramadhani</p>
<p align="center">103112400065</p>

## Tujuan Praktikum
1. Mahasiswa dapat menggunakan stack pada pembuatan kode program.
2. Mahasiswa dapat memahami konsep dari stack.
3. Melatiih problem solving mahasiswa dengan mengimplementasikan stack.

## Dasar Teori
### Pengertian Stack
Stack adalah Abstract Data Type (ADT) atau sekumpulan data linear yang bekerja berdasarkan prinsip tertentu. Secara harfiah stack artinya adalah tumpukan, dalam dunai pemrograman stack adalah tumpukan data-data yang menyimpan suatu objek atau variabel.
Stack memiliki beberapa komponen didalamnya:
1. `Top` (Puncak), menandakan posisi pertama atau paling atas dalam stack.
2. `Data`, yang berisi kumpulan elemen data sesuai kebutuhan program.
3. `Bottom` (Dasar), kebalikan dari `Top` yaitu berada paling bawah atau elemen paling terakhir dalam stack.
4. `pointer`, posisi yang selalu menunjuk puncak.

### Prinsip Kerja LIFO (Last-In, First-Out)
LIFO merupakan metode pengolahan data yang memiliki konsep terakhir masuk dapat keluar pertama kali. LIFO ini sering digunakan dalam Linked List, dan salah satunya adalah stack.
Misalkan kita memiliki sebuah rantang susun seperti ini:
![rantang - ilustrasi stack](<../Modul 7/screenshoot/Lampiran/rantang - ilustrasi stack.jpeg>)
Sekarang bayangkan rantang itu belum kita susun atau masih menyiapkan makanannya. Jika kita selesai menyiapkan semua makanan pada tempat rantangnya, maka kita perlu memasukkan satu persatu rantangnya. Nah rantang pertama yang kita masukkan akan berada di paling bawah sedangkan rantang yang paling terakhir kita masukkan berada di paling atas. Jika kita ingin mengambil rantang paling bawah maka kita perlu mengeluarkan semua rantang dari atas secara berurutan. Konsep ini disebut sebagai LIFO yang digunakan dalam stack.

### Operasi-Operasi Dasar Stack
Stack memiliki beberapa jenis operasi yang sering digunakan yaitu:
- push, merupakan operasi yang memasukkan elemen baru ke dalam stack dan menjadi TOP atau puncak yang baru.
- pop, merupakan operasi yang menghilangkan atau mengeluarkan elemen TOP (paling atas) dari stack.
- peek (atau top), untuk melihat atau mendapatkan nilai elemen diatas stack tanpa menghapusnya.
- isEmpty, merupakan operasi boolean untuk memeriksa apakah termausk stack kosong atau tidak.
- isFull, operasi boolean yang digunakan untuk memeriksa apakah stack sudah penuh atau belum.

### Perbedaan Stack dan Queue
Dari pengertian stack diatas dia menerapkan konsep LIFO yaitu terakhir masuk pertama kali keluar, sedangkan untuk Queue menggunakan konsep FIFO yaitu pertama kali masuk pertama kali keluar. Maka perbedaannya ada di konsep atau metode nya saja.

## Guided
### 1. Guided 1

#### Code C++ Main
![guided 1 - code_main](<screenshoot/stackCode/guided 1 - code_main.png>)

##### Bagian 1

```C++
#include "stack.h" 
#include <iostream>
using namespace std;
```

pada file main ini mengimport file `stack.h` dan `<iostream>`. Lalu menggunakan juga fungsi `standar` yang dipakai untuk `cout` dan `cin` agar dapat lebih simple dalam menuliskannya.

##### Bagian 2

```C++
int main() {
    Stack S; 
    CreateStack(S); 

    Push(S, 3); 
    Push(S, 4); 
    Push(S, 8); 
    Pop (S);     
    Push(S, 2); 
    Push(S, 3); 
    Pop (S);    
    Push(S, 9); 

    cout << "Stack awal: " << endl;
    printInfo(S); 

    cout << " Balik Stack: " << endl;
    balikStack(S); 

    cout << "Stack setelah dibalik: " << endl;
    printInfo(S); 

    return 0;
}
```

Ini adalah pemanggilan semua fungsi yang ada dengan value yang berbeda-beda.

#### Code C++ Stack
![guided 1 - code_stackCPP](<screenshoot/stackCode/guided 1 - code_stackCPP.png>)

##### Bagian 1

```C++
#include "stack.h" 
using namespace std;
```

Pada `stack.cpp` mengimport `stack.h` dan menggunakan `std` seabagai arahan kepada kompiler C++ agar tidak perlu menggunakan `std` pada setiap `cout`, `cin`, dan `endl`.

##### Bagian 2

```C++
void CreateStack(Stack &S) {
    S.TOP = Nil; 
}

bool IsEmpty(Stack S) {
    return S.TOP == Nil; 
}

bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}
```

Prosedur `CreateStack` untuk membuat stack kosong dengan inisiasi `TOP = Nil` atau bernilai -1. Lalu Fungsi `IsEmpty` untuk cek apakah stack kosong menggunakan perbandingan `S.TOP == Nil`. Fungsi `IsFull` digunakan untuk mengecek apakah stack sudah penuh atau belum menggunakan `S.TOP == MaxEl - 1`.

##### Bagian 3

```C++
void Push(Stack &S, infotype X) {
    if (!IsFull(S)) { 
        S.TOP++; 
        S.info[S.TOP] = X; 
    } else {
        cout << "Stack is full. Cannot push " << X << endl; 
    }
}


infotype Pop(Stack &S) {
    infotype X = -999;
    if (!IsEmpty(S)) { 
        X = S.info[S.TOP];
        S.TOP--; 
    }else {
        cout << "Stack Kosong. Gabisa pop." << endl; 
    }
    return X; 
}
```

Prosedur `Push` digunakan untuk memasukkan elemen baru ke dalam stack yang di letakkan pada posisi puncak atau paling atas, didalamnya ada dua kondisi saat stack tidak full maka prosedur akan memasukkann elemen baru, jika penuh prosedur akan memberitahu bahwa stack penuh. Dan ada fungsi `Pop` berguna untuk memindahkan elemen paling atas ke variabel `x` dan merubah elemen paling atas menjadi elemen dibawahnya.

##### Bagian 4

```C++
void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack Kosong" << endl; // pesan jika stack kosong
    } else {
        cout << "[TOP] "; // Tampilkan penanda TOP
        for (int i = S.TOP; i >= 0; i--) { // iterasi dari TOP ke bawah
            cout << S.info[i] << " "; // tampilkan elemen
        }
        cout << endl;
    }
}
```

Prosedur `printInfo` berguna untuk mencetak semua elemen pada stack yaitu dari elemen palling atas sampai paling bawah.

##### Bagian 5

```C++
void balikStack(Stack &S) {
    if (!IsEmpty(S)) { // Cek apakah stack tidak kosong
        Stack temp1, temp2; // deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2); // inisialisasi kedua stack temporary

        while (!IsEmpty(S)) { // Pindahkan semua elemen dari S ke temp1 (urutan terbalik)
            Push(temp1, Pop(S));
        }

        while (!IsEmpty(temp1)) { // Pindahkan semua elemen dari temp1 ke temp2 (urutan terbalik lagi)
            Push(temp2, Pop(temp1));
        }

        while (!IsEmpty(temp2)) { // Pindahkan semua elemen dari temp2 kembali ke S (urutan sudah benar)
            Push(S, Pop(temp2));
        }
    }
}
```

Prosedur `balikStack` berguna untuk membalikkan urutan dari elemen pada stack, ini dapat kita bayangkan seperti menumpahkan gelas berisi bola ke gelas lainnya. Yang tadinya paling atas sekarang paling bawah dan sebaliknya.

#### Code header stack
![guided 1 - code_stackHeader](<screenshoot/stackCode/guided 1 - code_stackHeader.png>)

##### Bagian 1

```C++
#ifndef STACK_H
#define STACK_H
...
#endif
```

Ini berguna untuk mencegah file header ini di-include oleh `namaFile.cpp` lebih dari sekali yang akan menyebabkan file eror.

##### Bagian 2

```C++
#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;
```

Program ini menggunakn `iostream` untuk mencetak atau menginput suatu variabel. Mendefinisikan variabel `maxEl` adalah 20. Mendefinisikan variabel `Nil` adalah -1. Membuat alias tipedata integer untuk variabel `infotype`.

##### Bagian 3

```C++
struct Stack {
    infotype info[MaxEl];
    int TOP;
};
```

Bertujuan mendefinisikan tipe data baru yaitu `stack` sebagai struktur. `stack` memiliki dua bagian yaitu `info[]` bertipe `infotype` merupakan array yang menyimpan `MaxEl`, dan `TOP` bertipe integer yang befungsi sebagai penanda elemen paling atas.

##### Bagian 4

```C++
void CreateStack(Stack &S);
bool IsEmpty(Stack S);
bool IsFull(Stack S);
void Push(Stack &S, infotype X); 
infotype Pop(Stack &S); 
void printInfo(Stack S); 
void balikStack(Stack &S); 
```

Bagian ini hanya memberitahu compiler bahwa "ada" fungsi-fungsi yang ada didalam file header.

#### Output

![guided 1 - output](<screenshoot/stackCode/guided 1 - output.png>)

**Penjelasan**

Dari output diatas, sudah sesuai dengan program yang telah dibuat.

## Unguided
### 1. Unguided 1

##### Code C++ Main
![Unguided 1 - code_main](<screenshoot/Unguided 1/Unguided 1 - code_main.png>)

File `main` ini sama saja dengan kode main pada file `guided 1`. Yang membedakan hanya pada value inputan saja

##### Code C++ Stack**
![Unguided 1 - code_stackCPP](<screenshoot/Unguided 1/Unguided 1 - code_stackCPP.png>)

File `main` ini juga sama saja dengan kode stack untuk cpp pada file `guided 1`.

##### Code header stack
![Unguided 1 - code_stackHeader](<screenshoot/Unguided 1/Unguided 1 - code_stackHeader.png>)

File `main` ini juga sama saja dengan kode stack untuk header pada file `guided 1`.

#### Output: 

![Unguided 1 - output](<screenshoot/Unguided 1/Unguided 1 - output.png>)

**Penjelasan**

Dari output diatas, dapaat dikatakan bahwa output sudah sesuai dengan program yang telah dibuat.

### 2. Unguided 2
#### Menambahkan pushAscending

##### Code C++ Main
![Unguided 2 - code_main](<screenshoot/Unguided 2/Unguided 2 - code_main.png>)

File `main` pada `unguided 2` ini merupakan penambahan file main pada `unguided 1`. Yaitu prosedur `pushAscending`, yang dimana fungsi dari prosedur ini dapat membuat setiap inputan terurut dalam stack. Dalam fungsi `main` ini hanya untuk pemanggilan setiap fungsi.

##### Code C++ Stack
![Unguided 2 - code_stackCPP](<screenshoot/Unguided 2/Unguided 2 - code_stackCPP.png>)

Dalam file ini, kita hanya menambahkan prosedur baru yaitu `pushAscending`.

```C++
void pushAscending(stack &S, infotype x) {
    if (penuh(S)) {
        cout << "Stack penuh!" << x << "tidak di-input ke stack." << endl;
    } else {
        stack temp1;
        createStack(temp1);
        while (!kosong(S) && S.info[S.TOP] <= x) {
            push(temp1, pop(S));
        }
        push(S, x);
        while(!kosong(temp1)) {
            push(S, pop(temp1));
        }
    }
}
```

Algoritma utama prosedur ini dapat berjalan jika stack tidak penuh, perulangan pertama akan terjadi sampai stack `S` kosong dan `S.info[S.TOP]` <=  `x` atau inputan user. Algortima utama berisi pemindahan stack dari stack `S` ke stack sementara, yang berpindah hanya angka yang lebih kecil dari `x` saja. setelah perulangan pertama selesai maka lakukan sebaliknya untuk menaruh kembali value yang ada di `temp1` ke `S`.

##### Code header stack
![Unguided 2 - code_stackHeader](<screenshoot/Unguided 2/Unguided 2 - code_stackHeader.png>)

Pada header untuk `Unguided 2` ini, ada penambahan seperti sebelumnya yaitu prosedur `pushAscending`. 

```C++
void pushAscending(stack &S, infotype x);

```

Prosedur ini memilik 2 parameter, variabel `S` sebagai input dan outputnya dan variabel `x` sebagai input dari user.

#### Output: 

![Unguided 2 - output](<screenshoot/Unguided 2/Unguided 2 - output.png>)

**Penjelasan**

Output yang ada diatas sudah sesuai dengan program yang dijalankan dan sesuai dengan tujuan dari program ini.

### 3. Unguided 3
#### Menambahkan getInputStream

##### Code C++ Main
![Unguided 3 - code_main](<screenshoot/Unguided 3/Unguided 3 - code_main.png>)

Pada fungsi `main` ini, ada pemanggilan prosedur `getInputString`. Jika program dijalankan maka, system akan selalu membaca inputan dari user sampai kondisi tertentu, dalam program ini sampai user menekan tombol enter.

##### Code C++ Stack
![Unguided 3 - code_stackCPP](<screenshoot/Unguided 3/Unguided 3 - code_stackCPP.png>)

File ini ada penambaha yaitu prosedur `getInputStream`. 

```C++
void getInputStream(stack &S) {
    char input;
    cout << "Masukkan deret angka (akhiri dengan enter): ";

    input = cin.get();
    while (input != '\n') {
        infotype value = input - '0'; // konversi char ke int
        // misal char '4' (ASCII 52) - char '0' (ASCII 48) = int 4

        push(S, value);

        input = cin.get();
    }
}
```

Setiap kali user memasukkan angka maka akan terbaca oleh program sebagai variabel tipe `char`, maka cara mengubah ke `int` menggunakan `infotype value = input - '0';` misal char '4' (ASCII 52) - char '0' (ASCII 48) = int 4. Setelah konversi ke `int` akan `push` dan meminta input user kembali, smapai user input `enter`.

##### Code header stack
![Unguided 3 - code_stackHeader](<screenshoot/Unguided 3/Unguided 3 - code_stackHeader.png>)

Dalam file ini hanya ditambahakan prosedur `getInputStream` saja untuk.

```C++
void getInputStream(stack &S);
```

Prosedur ini hanya menggunakan satu parameter sebagai input dan outputnya yaitu `S` atau stack nya.

#### Output: 

![Unguided 3 - output](<screenshoot/Unguided 3/Unguided 3 - output.png>)

**Penjelasan**

Dari output diatas dapat dilihat bahwa sudah sesuai dengan urutan dari yang sudah diprogram

## Kesimpulan

Pada praktikum kali ini, praktikan telah mempelajari dan sedikit menguasai materi dari stack. Stack merupakan Abstract Data Type (ADT) atau sekumpulan data linear yang bekerja berdasarkan prinsip tertentu. Stack menggunakan sistem LIFO yang artinya elemen terakhir yang masuk akan keluar pertama kali.

## referensi
- https://id.jobstreet.com/id/career-advice/article/stack-adalah#TOC1
- https://fikti.umsu.ac.id/pengertian-algoritma-lifo-last-in-first-out/
- https://glints.com/id/lowongan/stack-adalah/