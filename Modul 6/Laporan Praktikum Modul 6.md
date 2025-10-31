# <h1 align="center">Laporan Praktikum Modul 7</h1>
<p align="center">Dimas Ramadhani</p>
<p align="center">103112400065</p>

## Tujuan Praktikum
1. Mahasiswa dapat menggunakan double linked list pada pembuatan kode program.
2. Mahasiswa dapat memahami konsep dari double linked list.
3. Melatiih problem solving mahasiswa dengan mengimplementasikan double linked list.

## Dasar Teori
### Pengertian Doubly Linked List
Doubly linked list merupakan salah satu jenis dari linked list yang memiliki arah maju dan arah mundur. Linked list adalah merupakan struktur data linear yang terdiri dari 1 elemen atau lebih, setiap elemennnya disebut sebagai node. Node ini memiliki dua bagian utama yaitu bagian yang menyimpan value dan bagian yang menyimpan alamat node lainnya.

### Perbedaan Doubly dengan Single Linked List
#### Single Linked List

![Gambar System Single Linked List](<screenshoot/Lampiran laporan/Gambar single linked list bagus.png>)

Pada gambar diatas, single linked list hanya memiliki satu arah saja yaitu maju saja atau mundur saja. Dan untuk pointer pada setiap node nya hanya satu atau setiap node nya hanya menyimpan satu alamat node lain.

#### Doubly Linked List

![Gambar System Doubly Linked List](<screenshoot/Lampiran laporan/Gambar doubly linked list bagus.png>)

Pada gambar diatas, pada doubly linked list terlihat memiliki arah maju dan mundur. Sehingga pada setiap node nya menyimpan 2 alamat node di sebelahnya.

### Kelebihan dan Kekurangan menggunakan Doubly Linked List
Kelebihan:
1. Mengubah arah linked list menjadi lebih mudah.
2. Membuat operasi delete lebih cepat.
3. Mudah menyisipkan sebuah data dalam list.

Kekurangan:
1. Penggunaan memori yang lebih besar dibandingkan dengan array dan single linked list.
2. Implementasi lebih rumit dari single linked list, karena harus mengatur dua pointer dalam satu node.
3. Sama seperti single linked list, doubly linked list tidak mendukung akses langsung ke elemen tertentu (seperti array).

## Guided
### 1. Guided 1
#### DLL INSERT

![guided 1 - code](<screenshoot/guided 1 - code.png>)

**Penjelasan**

#### Bagian 1

```C++
#include <iostream>
#define Nil NULL
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya. Lalu fungsi dari `define Nil NULL` mendefiniskan bawha variabel `Nil` adalah `NULL`.

#### Bagian 2

```C++
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};
```

Disini kita membuat tipe data baru dan struct untuk membuat kerangka dari node nya. `typedef int infotype` artinya membuat tipe data `infotype` bertipekan `int`. `typedef struct elmlist *address` artinya membuat alias tipe data address yang menyimpan alamat ke `struct elmlist`.
Lalu untuk `struct elmlist` untuk membuat node nya yaitu berisi info, next, dan prev. Dan `struct List` untuk membuat head dan juga tail atau first dan juga last yang berfungsi sebagai pointer yang menunjuk dari setiap ujung pada List.

#### Bagian 3

```C++
void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R){
    P -> next = R -> next;
    P -> prev = R;
    if (R -> next != Nil) R -> next -> prev = P;
    else L.last = P;
    R -> next = P;
}
```

Untuk prosedur `insertFirst` berfungsi untuk menyisipkan node `P` sebagai node yang paling pertama. Untuk prosedur `insertLast` berfungsi untuk menyisipkan node `P` sebagai node yang paling terakhir. Dan untuk prosedur `insertAfter` berfungsi untuk menyisipkan node `P` setelah node `R`.

#### Bagian 4

```C++
address alokasi(infotype x){ // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}
```

Ini adalah fungsi `alokasi` yang memiliki tipe data `address` sehingga output dari fungsi ini merupakan sebuah node `P`. `alokasi` bertujuan untuk membuat node baru yang akan memasukkan value `x` ke dalam node baru itu.

#### Bagian 5

```C++
void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}
```

Prosedur `printInfo` berfungsi untuk mencetak semua value yang ada pada list, dimulai dari head sampai tail. Prosedur ini mengambil data dari sebuah list lalu mencetak semua value dari list tersebut.

#### Bagian 6

```C++
int main (){
    List L;
    L.first = Nil;
    L.last = Nil;
    address P1 = alokasi(1);
    insertFirst(L, P1);
    address P2 = alokasi(2);
    insertLast(L, P2);
    address P3 = alokasi(3);
    insertAfter(L, P3, P2);
    printInfo(L);
    return 0;
}
```

Fungsi `main` disini hanya memanggil semua fungsi yang diatas lalu dimasukkan angka nya secara manual.

#### Output:

![guided 1 - output](<screenshoot/guided 1 - output.png>)

**Penjelasan**

Dari output diatas, sesuai dengan program yang telah dibuat. Pertama kita mengalokasikan angka 1 ke sebuah pointer lalu sisipkan di awal. Dan mengalokasikan angka 2 dan menyisipkan di akhir. Dan mengalokasikan angka 3 menyisipkan setelah pointer yang memiliki value 2.

### 2. Guided 2
#### DLL HAPUS/DELETE

![guided 2 - code](<screenshoot/guided 2 - code.png>)

**Penjelasan**

#### Bagian 1

```C++
#include <iostream>
using namespace std;
#define Nil NULL
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya. Lalu fungsi dari `define Nil NULL` mendefiniskan bawha variabel `Nil` adalah `NULL`.

#### Bagian 2

```C++
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};
    
struct List {
    address first;
    address last;
};
```

Disini kita membuat tipe data baru dan struct untuk membuat kerangka dari node nya. `typedef int infotype` artinya membuat tipe data `infotype` bertipekan `int`. `typedef struct elmlist *address` artinya membuat alias tipe data address yang menyimpan alamat ke `struct elmlist`.
Lalu untuk `struct elmlist` untuk membuat node nya yaitu berisi info, next, dan prev. Dan `struct List` untuk membuat head dan juga tail atau first dan juga last yang berfungsi sebagai pointer yang menunjuk dari setiap ujung pada List.

#### Bagian 3

```C++
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}
```

Ini adalah fungsi `alokasi` yang memiliki tipe data `address` sehingga output dari fungsi ini merupakan sebuah node `P`. `alokasi` bertujuan untuk membuat node baru yang akan memasukkan value `x` ke dalam node baru itu. Dan prosedur `dealokasi` untuk menghapus penuh sebuah node menggunakan `delete` untuk membebaskan memori yang sebelumnya dipakai oleh `P` dan membuat isi dari `P` adalah `Nil`.

#### Bagian 4

```C++
void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
}
```

Seperti pada `guided 1`. Fungsi dari `inserFirst` untuk menyisipkan node `P` ke urutan paling pertama. Sedangkan fungsi `printInfo` untuk mencetak semua value dalam list.

#### Bagian 5

```C++
void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = L.first -> next;
    if (L.first != Nil) L.first -> prev = Nil;
    else L.last = Nil;
    P -> next = Nil;
    P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last -> prev;
    if (L.last != Nil) L.last -> next = Nil; 
    else L.first = Nil;
    P -> prev = Nil;
    P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next;
    R -> next = P -> next;
    if (P -> next != Nil) P -> next -> prev = R;
    else L.last = R;
    P -> prev = Nil;
    P -> next = Nil;
}
```

Prosedur-prosedur diatas adalah prosedur untuk memisahkan node `P` dari list. Untk delete yang pertama berfungsi memisahkan node yang paling pertama, lalu yang kedua untuk memisahkan node yang paling terakhir, dan yang terakhir untuk memisahkan node setelah node `R`.

#### Bagian 6

```C++
int main (){
    List L;
    L.first = Nil;
    L.last = Nil;
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    printInfo(L);
    address P;
    deleteFirst(L, P);
    dealokasi(P);
    deleteAfter(L, P, L.first);
    dealokasi(P);
    cout << endl;
    printInfo(L);
    return 0;
}
```

Ini adalah fungsi utama yang memanggil semua fungsi yang sudah dibuat sebelumnya.

#### Output:

![guided 2 - output](<screenshoot/guided 2 - output.png>)

**Penjelasan**

Dilihat dari output yang telah muncul, dapat dikatakan bahwa output sudah sesuai dengan tujuan dari programnya. Pertama menyisipkan node bervalue 1 ke paling awal dari list, lalu menyisipkan node bervalue 2 ke paling awal artinya sebelum node bervalue 1, dan terakhir menyisipkan node bervalue 3 sebelum node bervalue 2. 
Setelah itu akan di hapus elemen pertama dan langsung di dealokasikan, lalu menghapus elemen setelah elemen pertama yang baru. Dan output setelah di hapus ada di baris kedua.

## Unguided
### 1. Unguided 1
#### Modifikasi guided 1 (insertBefore dan printRevers)

![unguided 1 - code](<screenshoot/unguided 1 - code.png>)

#### Bagian 1

```C++
#include <iostream>
#define Nil NULL
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya. Lalu fungsi dari `define Nil NULL` mendefiniskan bawha variabel `Nil` adalah `NULL`.

#### Bagian 2

```C++
typedef int infotype;
typedef struct elmlist *address; 

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};
```

Disini kita membuat tipe data baru dan struct untuk membuat kerangka dari node nya. `typedef int infotype` artinya membuat tipe data `infotype` bertipekan `int`. `typedef struct elmlist *address` artinya membuat alias tipe data address yang menyimpan alamat ke `struct elmlist`.
Lalu untuk `struct elmlist` untuk membuat node nya yaitu berisi info, next, dan prev. Dan `struct List` untuk membuat head dan juga tail atau first dan juga last yang berfungsi sebagai pointer yang menunjuk dari setiap ujung pada List.

#### Bagian 3

```C++
void insertFirst(List &L, address P) {}

void insertLast(List &L, address P) {}

void insertAfter(List &L, address P, address R){}

address alokasi(infotype x){}

void printInfo(List L){}
```

Fungsi dan prosedur diatas sama saja dengan bagian 3, 4, dan 5 di `guided 1`. 

#### Bagian 4

```C++
void insertBefore(List &L, address P, address R){ 
// P untuk data yang dimasukkan, R untuk patokan pemasukan data
    P -> prev = R -> prev;
    P -> next = R;
    if (R -> prev != Nil) R -> prev -> next = P;
    else L.first = P;
    R -> prev = P;
    cout << "Berhasil insert " << P -> info << " sebelum " << R -> info;
    cout << endl; 
} // ini adalah masuk sebeleum, kabalikan dari masuk setelah
```

Prosedur ini bertujuan untuk menyisipkan `P` setelah node `R`. Prosedur ini akan menyisipkan node baru, dan mencetak keterangan dari proses penyisipan.

#### Bagian 5

```C++
void printReverse(List L) {
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> prev;
    }
    cout << endl;
}
```

Prosedur ini adalah kebalikan dari prosedur `printInfo` pada bagian 3. Yang membedakan adalah pointer P yang berawal dari `L.last` yang artinya pointer dimualai dari akhir elemen.

#### Bagian 6

```C++
int main (){
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "TASK 1: INSERT OPERATION\n";
    address P1 = alokasi(1);
    insertFirst(L, P1);
    address P2 = alokasi(3);
    insertLast(L, P2);
    address P3 = alokasi(2);
    insertAfter(L, P3, P2);
    cout << "List awal: \n";
    printInfo(L);
    printReverse(L);

    address P4 = alokasi(4);
    insertBefore(L, P4, P3);
    address P5 = alokasi(5);
    insertBefore(L, P5, P1);

    cout << "List setelah insert before:\n";
    printInfo(L);
    printReverse(L);
    return 0;
}
```

Ini adalah prosedur utama yang memanggil semua fungsi yang ada diatas. Tujuan dari prosedur utama ini memasukkan angka sebagai value dari node dan mencetak info dari pembuatan dan penyisipan node.

#### Output: 

![unguided 1 - output](<screenshoot/unguided 1 - output.png>)

**Penjelasan**

Dari output diatas, dapaat dikatakan bahwa output sudah sesuai dengan program yang telah dibuat.

### 2. Unguided 2
#### Modifikasi guided 2 (deleteByValue dan deleteAll)

![unguided 2 - code](<screenshoot/unguided 2 - code.png>)

#### Bagian 1

```C++
#include <iostream>
#define Nil NULL
using namespace std;
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya. Lalu fungsi dari `define Nil NULL` mendefiniskan bawha variabel `Nil` adalah `NULL`.

#### Bagian 2

```C++
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};
```

Bagian ini merupakan bagian yang sama dengan bagian 2 pada `guided 2`.

#### Bagian 3

```C++
address alokasi(infotype x) {
    address P = new elmlist;
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}
```

Bagian ini merupakan bagian yang sama dengan bagian 3 pada `guided 2`.

#### Bagian 4

```C++
void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = L.first -> next;
    if (L.first != Nil) L.first -> prev = Nil;
    else L.last = Nil;
    P -> next = Nil;
    P -> prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last;
    L.last = L.last -> prev;
    if (L.last != Nil) L.last -> next = Nil; 
    else L.first = Nil;
    P -> prev = Nil;
    P -> next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R -> next;
    R -> next = P -> next;
    if (P -> next != Nil) P -> next -> prev = R;
    else L.last = R;
    P -> prev = Nil;
    P -> next = Nil;
}
```

Bagian ini merupakan bagian yang sama dengan bagian 4 dan 5 pada `guided 2`.

#### Bagian 5

```C++
void deleteByValue(List &L, infotype val) {
    address R;
    bool cekAda = false;
    address P = L.first;
    while (P != Nil && !cekAda) {
        if (P->info == val) {
            if (P = L.first) {
                deleteFirst(L, P);
            } else if (P = L.last) {
                deleteLast(L, P);
            } else {
                R = P->prev;
                deleteAfter(L, P, R);
            }
            cekAda = true;
            cout << "Data " << val << " berhasil di hapus\n";
        }
        P = P->next;
    }
    
    if (!cekAda) {
        cout << "Data " << val << " tidak ditemukan\n";
        cout << "List tetap: ";
        printInfo(L);
    } else {
        dealokasi(P);
    }
}
```

Bagian ini merupakan bagian yang memodifikasi dari `guided 2`. Prosedur ini berfungsi unutuk menghpaus elemen pertama yang dicari melalui parameter `val`. Prosedur ini bekerja menggunakan perulangan dengan mengkombinasikan percabangan untuk membandingkan value dari setiap elemen dengan parameter `val`.

#### Output: 

![unguided 2 - output](<screenshoot/unguided 2 - output.png>)

**Penjelasan**

Output yang ada diatas sudah sesuai dengan program yang dijalankan dan sesuai dengan tujuan dari program ini.

### 3. Unguided 3
#### smartInsert

![unguided 3 - code part 1](<screenshoot/unguided 3 - code part 1.png>)
![unguided 3 - code part 2](<screenshoot/unguided 3 - code part 2.png>)

#### Bagian 1

```C++
#include <iostream>
using namespace std;
#define Nil NULL
```

Jadi fungsi `include <iostream>` untuk menambahkan fitur input ouput kedalam program yang kita ingin berikan. Sedangkan `using namespace std;` berfungsi untuk memudahkan dalam pembuatan kode agar saat kita ingin menggunakan `cin`, `cout`, dan sebagainya dapat langsung tanpa `std` terlebih dahulu pada setiap kode nya. Lalu fungsi dari `define Nil NULL` mendefiniskan bawha variabel `Nil` adalah `NULL`.

#### Bagian 2

```C++
typedef int infotype;
typedef struct dimasList *address;

struct dimasList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};
```
Disini kita membuat tipe data baru dan struct untuk membuat kerangka dari node nya. `typedef int infotype` artinya membuat tipe data `infotype` bertipekan `int`. `typedef struct dimasList *address` artinya membuat alias tipe data address yang menyimpan alamat ke `struct dimasList`.
Lalu untuk `struct dimasList` untuk membuat node nya yaitu berisi info, next, dan prev. Dan `struct List` untuk membuat head dan juga tail atau first dan juga last yang berfungsi sebagai pointer yang menunjuk dari setiap ujung pada List.

#### Bagian 3

```C++
address alokasi(infotype x) {
    address P = new dimasList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &x){
    delete x;
    x = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address cariElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    return P;
}
```

Ini adalah fungsi `alokasi` yang memiliki tipe data `address` sehingga output dari fungsi ini merupakan sebuah node `P`. `alokasi` bertujuan untuk membuat node baru yang akan memasukkan value `x` ke dalam node baru itu. Dan prosedur `dealokasi` untuk menghapus penuh sebuah node menggunakan `delete` untuk membebaskan memori yang sebelumnya dipakai oleh `P` dan membuat isi dari `P` adalah `Nil`.
Fungsi `isEmpty` berguna untuk mengecek apakah list kosong atau tidak dengan cek elemen pertamanya apakah `Nil` atau tidak. Lalu fungsi cariElm berguna untuk mencari elemen tertentu yang memiliki value yang dicari.

#### Bagian 4

```C++
/* ---------- Operasi insert ---------- */
void insertFirst(List &L, infotype D) {
    address P = alokasi(D);
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(List &L, infotype D) {
    address P = alokasi(D);
    if (isEmpty(L)) {
        L.first = L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(List &L, infotype D, address target) {
    if (target == Nil) {
        cout << "Data tidak ditemukan";
        return;
    }
    if (target == L.last) {
        insertLast(L, D);   
        return;
    }
    address P = alokasi(D);
    P->next = target->next;
    P->prev = target;
    target->next->prev = P;
    target->next = P;
}

void insertBefore(List &L, infotype D, address target) {
    if (target == Nil) {
        cout << "Data tidak ditemukan";
        return;
    } else if (target == L.first) {
        insertFirst(L, D);
        return;
    }
    address P = alokasi(D);
    P->prev = target->prev;
    P->next = target;
    target->prev->next = P;
    target->prev = P;
}
```

Dalam program ini digunakan 4 jenis insert yaitu `insertFirts` berguna menyisipkan elemen ke paling pertama, `inserLast` kebalikan dari `insertFirts`, `insertBefore` berguna untuk menyisipkan elemen sebelum elemen target, dan `insertAfter` berguna untuk menyisipkan elemen baru setelah elemen target.

#### Bagian 5

```C++
/* ---------- Cetak ---------- */
void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " "; 
        P = P->next;
    }
    cout << endl;
}

void printReverse(List L) {
    address P = L.last;
    cout << "Backward: ";
    while (P != Nil) {
        cout << P->info << " "; 
        P = P->prev;
    }
    cout << endl;
}
```

Prosedur `printInfo` berfungsi untuk mencetak semua value elemen dimulai dari `L.first` atau elemen pertama dari list, sedangkan `printReverse` kebalikan dari `printInfo`.

#### Bagian 6

```C++
/* ---------- SMART INSERT (≥4 kondisi + edge cases + pesan) ---------- */
void smartInsert(List &L, infotype x){
    cout << "Smart Insert: ";
    if (isEmpty(L)) {
        cout << "list kosong, insert " << x << " di first";
        insertFirst(L, x);
    } else if (x < L.first->info) {
        cout << x <<" < first, insert di first";
        insertFirst(L, x);
    } else if (x % 2 == 0) {
        cout << x << " genap, insert di last";
        insertLast(L, x);
    } else {
        address ada = cariElm(L, x);
        if (ada != Nil) {
            cout << " sudah ada, insert setelah " << x;
            insertAfter(L, x, ada);
        } else {
            address P = L.first;
            address target = Nil;
            while (P != Nil && P->info <= x) {
                P = P->next;
            }
            target = P;
            if (target == Nil) {
                cout << x << " lebih besar dari semua, insert di last";
                insertLast(L, x);
            } else {
                int left = (target->prev ? target->prev->info : -9999);
                cout << x << " di antara " << left << " dan " << target->info;
                insertBefore(L, x, target);
            }
        }
    }
    cout << endl;
}
```

Prosedur ini merupakan yang bertugas untuk menyisipkan elemen secara otomatis tergantung inputan dari pengguna. Jika list kosong maka `insertFirst`, jika inputan lebih kecil dari elemen pertama maka `insertFirst`, jika inputan merupakan bilangan genap maka `insertLast`, dan jika inputan bilangan ganjil jika merupakan angka yang paling besar dari list maka `insertLast` jika tidak maka akan `insertBefore`

#### Bagian 7

```C++
/* ---------- Operasi delete (bantuan) ---------- */
void hapusNode(List &L, address aku) {
    if (aku == Nil) return;
    if (aku == L.first && aku == L.last) {
        L.first = L.last = Nil;
    } else if (aku == L.first) {
        L.first = aku->next;
        if (L.first) L.first->prev = Nil;
    } else if (aku == L.last) {
        L.last = aku->prev;
        if (L.last) L.last->next = Nil;
    } else {
        aku->prev->next = aku->next;
        aku->next->prev = aku->prev;
    }
    dealokasi(aku);
}

/* ---------- DELETION ---------- */
void hapusGanjil(List &L){
    if (isEmpty(L)){
        cout << "Conditional Delete: List kosong, tidak ada yang dihapus\n";
        return;
    }
    int jumlahAngka = 0;
    address P = L.first;
    while (P != Nil) {
        address next = P->next;
        if (P->info%2 != 0) {
            hapusNode(L, P);
            jumlahAngka++;
        }
        P = next;
    } 
    cout << "Contiditional delete: " << jumlahAngka << " elemen ganjil dihapus\n";
}

void hapusByValue(List &L, infotype x) {
    if (L.first == Nil) {
        cout << "Dalam list ini tidak ada data yang tersisa\n";
        return;
    } 
    address P = L.first;
    while (P != Nil && P->info != x) {
        P = P->next;
    }
    if (P == Nil){
        cout << "Nilai " << x << " tidak ditemukan\n";
    } else {
        hapusNode(L, P);
        cout << "Nilai " << x << " berhasil dihapus\n";
    }
}

void hapusSemua(List &L) {
    address P = L.first;
    int jumlahBilangan = 0;
    while (P!=Nil){
        address next = P->next;
        hapusNode(L, P);
        P = next;
        jumlahBilangan++;
    }
    cout << "Semua elemen (" << jumlahBilangan << ") berhasil dihapus";
}
```

Prosedur-prosedur diatas berfungsi untuk menghapus dan membebaskan memori dari elemen yang sudah terhapus.

#### Bagian 8

```C++
int main () {
    List data;
    infotype value;
    data.first = Nil;
    data.last = Nil;
    cout << "ADVANCE OPERATIONS\n" << "SMART INSERT DEMO\n";
    smartInsert(data, 7);
    smartInsert(data, 3);
    smartInsert(data, 5);
    smartInsert(data, 11);
    smartInsert(data, 32);
    smartInsert(data, 9);
    smartInsert(data, 4);

    cout << "\nHasil smart insert\n" << "Forward: ";
    printInfo(data);
    printReverse(data);

    cout << "\nCONDITIONAL DELETE (ANGKA GANJIL)\n" << "Sebelum conditional delete: ";
    printInfo(data);
    hapusGanjil(data);
    cout << "Setelah conditional delete: ";
    printInfo(data);
    
    cout << "\nDELETE BY VALUE DEMO\n";
    hapusByValue(data, 9);
    hapusByValue(data, 5);
    hapusByValue(data, 4);
    cout << "List akhir: ";
    printInfo(data);

    cout << "\nDELETE ALL DEMO\n";
    hapusSemua(data);
}
```

Fungsi main berfungsi untuk memanggil semua prosedur dan fungsi yang telah dibuat dan sebagai tempat untuk mengoperasikan semua perintah.

#### Output: 

![unguided 3 - output](<screenshoot/unguided 3 - output.png>)

**Penjelasan**

Dari output diatas dapat dilihat bahwa sudah sesuai dengan urutan dari yang sudah diprogram

## Kesimpulan

Sebagai praktikan, saya telah mempelajari dan mengimpementasikan doubly linked list ini. Doubly linked list merupakan linked list yang memiliki traversal dua arah (maju atau mundul), sehingga lebih fleksibel dibandingkan dengan single linked list. Melalui praktikum ini, saya menjadi paham bagaimana cara untuk memasukkan, menghapus, atau pencarian data dalam doubly linked list.

## referensi
- https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/#ii-pengertian-linked-list
- https://www.geeksforgeeks.org/dsa/difference-between-singly-linked-list-and-doubly-linked-list/
- https://www.geeksforgeeks.org/dsa/advantages-disadvantages-and-uses-of-doubly-linked-list/