# <h1 align="center">Laporan Praktikum Modul 13</h1>
<p align="center">Dimas Ramadhani</p>
<p align="center">103112400065</p>

---

## Tujuan Praktikum
1. Praktikan paham dengan konsep dasar struktur data Multi Linked List.
2. Praktikan mampu mengimplementasikan dalam pembuatan program menggunakan Multi Linked List.
3. Praktikan dapat melatih kemampuan dalam menyelesaikan masalah yang menggunakan Multi Linked List.

---

## Dasar Teori
### Pengertian Multi Linked List
Merupakan struktur data yang terdiri dari beberapa list yang saling berhubungan. Setiap elemen pada list induk dapat memiliki list anak sendiri. Konsep ini digunakan untuk mempresentasikan hubungan **one-to_many**, contohnya:
    - List Induk: Pegawai
    - List Anak : Anak dari pegawai tersebut
Dengan kata lain, Multi Linked List adalah pengembangan dari Linked List yang memungkinkan setiap node induk memiliki sublist.

### Ciri Khas
1. Terdapat list induk dan list anak.
2. Setiap node induk memiliki pointer ke list anak.
3. Operasi dasar meliputi:
    - insert induk : Sama seperti pada singly/doubly linked list.
    - insert anak  : Harus mengetahui induk terlebih dahulu.
    - delete induk : Menghapus induk beserta seluruh anaknya.
    - delete_anak  : Menghapus anak dari induk tertentu.

### Representasi
1. Menggunakan **struct** untuk elemen induk dan anak.
2. Elemen induk menyimpan:
    - Info induk.
    - Pointer ke list anak.
    - Pointer ke induk berikutnya dan sebelumnya.
3. Elemen anak menyimpan:
    - Info anak.
    - Pointer ke anak berikutnya dan sebelumnya.

### Operasi Dasar
1. CreateList: Membuat list kosong.
2. Insert:
    - insertFirst untuk induk.
    - insertFirstAnak, insertLastAnak untuk anak.
3. Delete:
    - delFirst untuk induk.
    - delFirstAnak, delLastAnak untuk anak.
4. Find: findElm untuk mencari induk/anak berdasarkan info.
5. Print: printInfo untuk menampilkan semua elemen induk dan anak.

### Kelebihan Multi Linked List
1. Memudahkan representasi data yang memiliki hubungan hierarki.
2. Efisien untuk operasi penambahan dan penghapusan dibandingkan array.

### Kekurangan
1. Kompleksitas impementasi lebih tinggi.
2. Memerlukan manajemen memori yang baik (alokasi dan dealokasi).

---

## Guided
### 1. Guided 1

#### Code C++ Main
![Guided 1 - code_main](<screenshoot/Guided/Guided 1 - code_main.png>)

#### Code C++ multilistInduk
![guided 1 - mulitlistInduk](<screenshoot/Guided/Guided 1 - code_multilistInduk.png>)

#### Code C++ multilistAnak
![Guided 1 - multilistAnak](<screenshoot/Guided/Guided 1 - code_multilistAnak.png>)

#### Header C++ multilist
![Guided 1 - header_multilist](<screenshoot/Guided/Guided 1 - header_multilist.png>)

**Penjelasan**
Program ini mensimulasikan cara membuat, memasukkan, menghapus node (induk/anak) dalam list. Progam ini menggunakan pendekatan multi linked list yang ditandai dengan fungsi insertAnak yang menunjukkan bahwa program ini dapat memasukkan node anak ke list yang ditunjuk oleh induk.

#### Output
![Guided 1 - output](<screenshoot/Guided/Guided 1 - output.png>)

**Penjelasan**
Output pada soal yang diberikan oleh asisten praktikum diatas merupakan hasil dari program multilinked list

---

## Unguided
### 1. multiList

#### Code C++ Main
[Unguided - code_main](<code/Unguided - Multi Linked List/main.cpp>)

#### Code C++ multiList
[Unguided - code_multilist](<code/Unguided - Multi Linked List/multilist.cpp>)

#### Code header multilist
[Unguided - header_multilist](<code/Unguided - Multi Linked List/multilist.h>)

**Penjelasan**
Pada program multilist ini dibagai menjadi 3 bagian yaitu:
- main.cpp
- multilist.cpp
- multilist.h

Pertama untuk `multilist.h` merupakan pendefinisian semua fungsi-fungsi yang akan digunakan, seperti halnya membuat list atau node, menginputkan sebuah node ke list sesuai dengan fungsi yang digunakan(first, after, last), mencari elemen, dan fungsi lainnya.

Kedua untuk `multilist.cpp` merupakan berisi program yang lebih jelas sesuai dengan fungsi-fungsi yang ada pada file `multilist.h`. Dalam beberapa fungsi digunakan percabangan, perulangan, dan lain-lainnya.

Ketiga untuk `main.cpp` merupakan pemanggilan dari semua fungsi pada `multilist.h` yang dimana pada programnya akan beralur seperti:
1. Buat list induk dengan CreateList.
2. Tambah beberapa induk (insertFirst, insertLast).
3. Cari induk tertentu (findElm) → tambahkan anak (insertLastAnak).
4. Cetak isi list (printInfo).
5. Hapus anak atau induk (delPAnak, delP).
6. Akhiri dengan delAll untuk menghapus semua.

#### Output: 
![Unguided - output](<screenshoot/Unguided - Multi Linked List/Unguided - output.png>)

**Penjelasan**
Output diatas merupakan hasil dari program yang telah dibuat, dan sudah sesuai dengan alur yang diharapkan.


### 2. Unguided 2

#### Code C++ Main
[Unguided - code_main](<code/Unguided - Circular Linked List/main.cpp>)

##### Code C++ circularList
[Unguided - code_circularList](<code/Unguided - Circular Linked List/circularlist.cpp>)

##### Code header circularList
[Unguided - header_circularList](<code/Unguided - Circular Linked List/circularlist.h>)

**Penjelasan**
Karena program ini menggunakan tipe linked list yang circular yaitu linked list yang ujung dari listnya mengarah ke elemen pertama pada list (First), maka ada beberapa hal yang membedakan dalam input atu delete node dalam list. Seperti pada fungsi insertFirst.

Pada fungsi insertFirst, kita harus mencari terlebih dahulu node akhir dalam list (node sebelum First) untuk mengrahkan node akhir ini ke node yang ingin diinputkan.

#### Output: 
![Unguided - output](<screenshoot/Unguided - Circular Linked List/Unguided - output.png>)

**Penjelasan**
Pada output yang telah dibuat oleh praktikan sedikit berbeda dari output yang ada pada soal latihan. Pada nama mahasiswa cindi yang seharusnya berada pada list terakhir pada circular linked list. Namun program yang telah praktikan buat sudah sesuai dengan lokiga dan alur yang direncanakan.

---

## Kesimpulan
Multi Linked List adalah struktur data yang digunakan untuk merepresentasikan hubungan hierarki atau one-to-many antara data, misalnya pegawai dan anaknya. Dengan adanya list induk dan list anak, pengelolaan data menjadi lebih terstruktur dan fleksibel dibandingkan array konvensional. Operasi dasar seperti insert, delete, dan search dapat dilakukan baik pada level induk maupun anak, namun implementasinya lebih kompleks karena melibatkan manajemen memori dan pointer ganda.

Struktur ini sangat bermanfaat untuk kasus yang membutuhkan keterhubungan antar data, seperti:
- Representasi organisasi (departemen → karyawan)
- Representasi kategori produk (kategori → produk)
- Representasi graf (node → adjacency list)

Namun, kelemahannya adalah kompleksitas implementasi dan kebutuhan pengelolaan memori yang lebih teliti.

---

## referensi (Benerin lagi referensi nya)
- https://www.cs.mcgill.ca/~akroit/math/compsci/Cormen%20Introduction%20to%20Algorithms.pdf
- https://www.uoitc.edu.iq/images/documents/informatics-institute/Competitive_exam/DataStructures.pdf
- https://www.slideshare.net/slideshow/8-multi-list-struktur-data/114941552 
- https://www.geeksforgeeks.org/cpp/circular-linked-list-in-cpp/
