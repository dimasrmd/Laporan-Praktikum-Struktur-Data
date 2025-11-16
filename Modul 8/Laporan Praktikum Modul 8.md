# <h1 align="center">Laporan Praktikum Modul 8</h1>
<p align="center">Dimas Ramadhani</p>
<p align="center">103112400065</p>

## Tujuan Praktikum
1. Praktikan paham dengan konsep dasar struktur data queue.
2. Praktikan mampu mengimplementasikan dalam pembuatan program menggunakan queue.
3. Praktikan dapat melatih kemampuan dalam menyelesaikan masalah yang menggunakan queue/

## Dasar Teori
### Pengertian Queue
Queue atau dalam bahasa Indonesia adalah antrean. Menurut Kamus Besar Bahasa Indonesai (KBBI), antrean adalah deretan orang, barang olahan, atau unit yang sedang menunggu giliran untuk dilayani, diolah, dan sebagainya. Dalam pemrogramana, queue adalah struktur data yang menyusun elemen-elemen data dalam urutan linear menggunakan prinsip FIFO.

### Prinsip Kerja FIFO
FIFO merupakan singkatan dari First In First Out, maksudnya adalah setiap kali ada sesuatu yang baru akan masuk ke dalam antrean dan keluar pertama dari antrian. Struktur FIFO pada queue, data pertama yang masuk akan keluar pertama atau data tersebut baru saja ditambahkan dalam queue disebut sebagai front atau head. Namun jika data ada pada urutan terakhir artinya data tersebut baru saja ditambahkan ke dalam queue disebut back, rear, atau tail.

### Operasi Dasar Queue
#### **a. Enqueue**
Ini merupakan operasi untuk menambahkan elemen ke dalam queue. Jika sebelumnya antrean kosong maka elemen akan ada di posisi paling awal, Namun sebaliknya akan berada di paling akhir.
#### **b. Dequeue**
Ini merupakan operasi unutk mengeluarkan elemen paling depan atau head. Karena queue menggunakan prinsip FIFO maka yang akan dilayani dari depan terlebih dahulu
#### **c. Peek**
Ini adalah operasi untuk melihat data atau isi dari suaru elemen.
#### **d. IsEmpty**
Ini adalah operasi untuk mengecek apakah antrean itu kosong. Indikator pengecekannya jika pada array menggunakan head saja atau jumlah elemennya itu kosong.
#### **c. IsFull**
Ini adalah opeasi untuk mengecek apakah antrean itu penuh. Untuk indikator pengecekannya menggunakan tail saja atau jumlah elemennya itu adalah jumlah maksimum tampungan data.

### Jenis-jenis queue
Queue memiliki beberapa jenis yang berbeda, setiap jenisnya memiliki fungsi implementasi yang berbeda-beda pula. Berikut beberapa jenis dari queue:

#### 1. Berdasarkan struktur implementasi
**a. Linear Queue**
Linear queue ada 2 macam yaitu pada saat proses penghapusan atau dequeue headnya diam dan headnya bertambah (bergerak). 

Kelebihan pada head yang diam, strukturnya dapat digunakan secara maksimal. Sedangkan kekurangannya, saat proses dequeu harus memindahkan value dari nya ke elemen sebelumnya pada setiap posisi value. 

Kebalikan dari heaad yang diam, head yang bergerak ini memiliki kelebihan seperti tidak memerlukan proses perulangan untuk memindahkan setiap value elemennya. Namun kekurangnnya saat setelah proses dequeu karena headnya sudah bertambah maka elemen sebelunya yang sudah pernah jadi head tidak bisa digunakan kembali.

**b. Circular Queue**
Circular queue merupakan queue yang lebih baik dari linear queue. Circular secara harfiah artinya melingkar, maka Circular queue adalah queue yang memiliki struktur seperti lingkaran. Maksudnya indeks dapat kembali ke awal jika masih ada ruang kosong.

#### 2. Berdasarkan kegunaan khusus
**a. Priority Queue**
Elemen dalam antrean yang memiliki prioritas. Jika elemen tersebut memiliki poin prioritas tertinggi maka akan langsung dilayani walaupun berada pada paling belakang dalam antrean.

**b. Double Ended Queue (Dequeu)**
Queue ini menawarkan fleksibilitas yang lebih besar karena memungkinkan penambahan dan penghapusan elemen baik dari ujung depan maupun belakang.

### Perbedaan queue dengan stack
Dalam penggunaan prinsipnya, queue menggunakan FIFO (First in First Out) hal pertama akan dikerjakan terlebih dahulua, Sedangkan pada stack menggunakan LIFO (Last in First out) hal terakhir yang masuk akan langsung dikerjakan terlebih dahulua.

Dalam operasi penambahan atau penghapusan elemen. Pada queue, operasi penambahan elemen akan di mulai dari tail, opeasi pengurangan akan diambil dari head, yang artinya memiliki 2 jalur. Berbeda dengan stack hanya memiliki satu jalur saja yaitu sebagai jalur masuk dan jalur keluarnya.

## Guided
### 1. Guided 1

#### Code C++ Main
![guided 1 - code_main](<screenshoot/Guided/Guided 1 - code_main.png>)

#### Code C++ queue
![guided 1 - code_queueCPP](<screenshoot/Guided/Guided 1 - code_queueCPP.png>)

#### Code header queue
![guided 1 - code_queueH](<screenshoot/Guided/Guided 1 - code_queueH.png>)

**Penjelasan**
Program diatas merupakan circular queue karena setiap kali penambahan atau pengurangan indeksnya selalu dimoduluskan dengan max nya. Program ini dibuat menjadi 3 file berbeda dengan tujuan untuk memudahkan dalam memperbaiki dan terlihat rapih, solusi untuk menyatukan ketiga program ini dengan memberikan definisi pada setiap file kecuali main, kemudian untuk terhubung gunakan include (namaFIle). 

#### Output
![guided 1 - output](<screenshoot/Guided/Guided 1 - output.png>)

**Penjelasan**
Dari output diatas, sudah sesuai dengan program yang telah dibuat.

## Unguided
### 1. Unguided 1

#### Code C++ Main
![unguided 1 - code_main](<screenshoot/Unguided 1/Unguided 1 - code_main.png>)

#### Code C++ queue
![unguided 1 - code_queueCPP](<screenshoot/Unguided 1/Unguided 1 - code_queueCPP.png>)

#### Code header queue
![unguided 1 - code_queueH](<screenshoot/Unguided 1/Unguided 1 - code_queueH.png>)

**Penjelasan**
Kode ini dibuat menggunakan linear queue dengan konsep alternatif 1 pada modul 8 (head diam, tail bergerak). Dalam program ini head dibuat diam untuk memaksimalkan pengisian dari queue. Setiap kali melakukan dequeue, mengeluarkan elemen pada head, dan semua elemen kecuali elemen yang baru di keluarkan akan mundur 1 langkah (dalam pemrograman) atau maju 1 langkah (dalam contoh dunia nyata/antrean).

#### Output: 
![Unguided 1 - output](<screenshoot/Unguided 1/Unguided 1 - output.png>)

**Penjelasan**
Dari output diatas, dapaat dikatakan bahwa output sudah sesuai dengan program yang telah dibuat.


### 2. Unguided 2

#### Code C++ Main
![unguided 2 - code_main](<screenshoot/Unguided 2/Unguided 2 - code_main.png>)

##### Code C++ queue
![unguided 2 - code_queueCPP](<screenshoot/Unguided 2/Unguided 2 - code_queueCPP.png>)

##### Code header queue
![unguided 2 - code_queueH](<screenshoot/Unguided 2/Unguided 2 - code_queueH.png>)

**Penjelasan**
Kode ini dibuat menggunakan linear queue dengan konsep alternatif 2 (head dan tail bergerak). Untuk operasi penambahan sama saja seperti pada nomor 1, namun berbeda pada pengurangan/dequeue. Berbeda karena pada saat dequeue menggeeser head ke belakanga (menambahkan nilai head).

#### Output: 
![Unguided 2 - output](<screenshoot/Unguided 2/Unguided 2 - output.png>)

**Penjelasan**
Output yang ada diatas sudah sesuai dengan program yang dijalankan dan sesuai dengan tujuan dari program ini.

### 3. Unguided 3

#### Code C++ Main
![unguided 3 - code_main](<screenshoot/Unguided 3/Unguided 3 - code_main.png>)

#### Code C++ queue
![unguided 3 - code_queueCPP](<screenshoot/Unguided 3/Unguided 3 - code_queueCPP.png>)

#### Code header queue
![unguided 3 - code_queueH](<screenshoot/Unguided 3/Unguided 3 - code_queueH.png>)

**Penjelasan**
Kode ini menggunakan circular queue atau alternatif 3 pada modul 8, konsep circular queue adalah perkembangan dari linear queue (alternatif 2). Jadi pada pemvisualan program head bisa saja poisinya didepan tail, hal ini dikarenakan proses dequeue yang melebihi proses enqueue. Untuk sistem melingkarnya ada pada proses enqueue dan dequeue, yaitu pada indexing setiap kali nilainya bertambah selalu di moduluskan dengan `max` agar jika melebihi nilai `max` dapat mulai dari posisi awal.

#### Output: 
![unguided 3 - output](<screenshoot/Unguided 3/Unguided 3 - output.png>)

**Penjelasan**
Dari output diatas dapat dilihat bahwa sudah sesuai dengan urutan dari yang sudah diprogram

## Kesimpulan
Pada praktikum kali ini, praktikan telah menguasai dasar dari konsep queue (antrean) yang memiliki 2 jalur yaitu masuk yaitu tail dan keluar yaitu head. Praktikan juga dapat mengimplementasikan konsep tersebut ke dalam soal yang telah diberikan sekaligus untuk melatih cara berpikir kritis dalam pemrograman.

## referensi
- https://kbbi.web.id/antre
- https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
- https://bit.telkomuniversity.ac.id/queue-pengertian-fungsi-dan-jenisnya/