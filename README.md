# TUBES-STD-Penyewaan-Buku
TUGAS BESAR STRUKTUR DATA KELOMPOK 5 : PEMINJAMAN BUKU TIPE A SLL - DLL

JUDUL : PEMINJAMAN BUKU PENYEDIA BUKU X
TIPE MLL : A
Jenis List Parent : Single Linked List
Jenis List Child : Double Linked List
Model MLL :
 
Data Buku :
1.	KodeBuku
2.	Penulis
3.	Judul
4.	Status
Data Peminjam  :
1.	IDPeminjam
2.	nama
3.	TanggalPinjam
4.	TanggalKembali
Cerita : Aplikasi digunakan untuk meminajm sebuah buku dari perpustakaan, yang mana satu buku hanya bisa dipinjam oleh satu orang, jika ada lagi yang ingin meminjam akan di masukan ke dalam waiting list (yang merupakan next dari relation), jika buku sudah dikembalikan maka buku tsb bisa dipinjam lagi dengan status tersedia.

Fitur – Fitur Program :
1.	Tambah Buku (Insert Buku )
2.	Tambah Peminjam (Insert Peminjam)
3.	Pinjam Buku (Insert Relasi)
4.	Hapus Buku (Delete Buku)
5.	Kembalikan Buku (Delete Relation)
6.	Hapus Peminjam (Delete Peminjam)
7.	Cari Buku
8.	Cari Relasi
9.	Cari Peminjam
10.	Tampilkan Semua Buku
11.	Tampilkan Semua Peminjam
12.	Tampilkan Semua Peminjam dari Buku Tertentu
13.	Tampilkan Semua Buku Beserta Peminjamnya
14.	Tampilkan Semua Peminjam Beserta buku Yang Dipinjamnya
15.	Tampilkan Semua Buku dari peminjam tertentu
16.	Hitung ralasi Dari Setiap Buku
17.	Hitung relasi dari peminjam Tertentu
18.	Hitung Child yang tidak memiliki relasi
19.	Edit relasi dari buku tertentu
20.	Keluar

Pembagian Tugas :
List Buku/Perpustakaan – Ahmad Faizal Hanif
List Peminjam – Sofwan Rosidi
List Relation – Dikerjakan bersama-sama (Bagi 2)

Spesifikasi Program	:
1.	createListBuku
PIC : Faizal
Penjelasan : Fungsi createListBuku menginisialisasi ListBuku sebagai list kosong dengan mengatur pointer first ke NULL.
2.	createListPeminjam
PIC : Sofwan
Penjelasan : Fungsi ini menginisialisasi ListPeminjam sebagai list kosong dengan mengatur pointer first ke NULL.
3.	createListRelation
PIC : Faizal
Penjelasan : Fungsi ini akan menginisialisasi list relation L.
4.	adrBuku createNewElemenBuku
PIC : Faizal
Penjelasan : Fungsi ini akan membuat elemen baru untuk buku.
5.	adrPeminjam createNewElemenPeminjam
PIC : Sofwan
Penjelasan : Fungsi createNewElemenPeminjam mengalokasikan dan mengembalikan elemen baru untuk list peminjam, siap untuk diisi dan ditambahkan ke list.
6.	adrRelation createNewElemenRelation
PIC : Sofwan 
Penjelasan :
7.	void InsertBuku_first
PIC : Faizal
Penjelasan : Tambahkan elemen baru ke List buku di posisi pertama.
8.	void InsertBuku_last
PIC : Faizal
Penjelasan : Tambahkan elemen baru ke List buku di posisi terakhir.
9.	void InsertBuku_after
PIC : Faizal
Penjelasan : Tambahkan elemen B setelah elemen prec dalam List buku.
10.	void InsertPeminjam_first
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan elemen baru sebagai elemen pertama dalam list peminjam.
11.	void InsertPeminjam_last
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan elemen baru sebagai elemen terakhir dalam list peminjam.
12.	void InsertPeminjam_after
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan elemen baru setelah elemen tertentu yang sudah ada dalam list peminjam.
13.	void InsertRelation_first
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan relasi baru sebagai elemen pertama dalam list relasi
14.	void InsertRelation_last
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan relasi baru sebagai elemen terakhir dalam list relasi
15.	void InsertRelation_after
PIC : Sofwan
Penjelasan : Fungsi ini menambahkan relasi baru setelah elemen tertentu yang sudah ada dalam list relasi
16.	void DeleteBuku_first
PIC : Faizal
Penjelasan : Hapus elemen buku pertama dalam List buku.
17.	void DeleteBuku_last
PIC : Faizal
Penjelasan : Hapus elemen buku terakhir dalam List buku.
18.	void DeleteBuku_after
PIC : Faizal
Penjelasan : Hapus elemen buku setelah elemen prec dalam List buku.
19.	void DeletePeminjam_first
PIC : Sofwan
Penjelasan : Fungsi ini menghapus elemen pertama dari list peminjam
20.	void DeletePeminjam_last
PIC : Sofwan
Penjelasan : Fungsi ini menghapus elemen terakhir dari list peminjam
21.	void DeletePeminjam_after
PIC : Sofwan
Penjelasan : Fungsi ini menghapus elemen yang berada tepat setelah elemen tertentu dalam list peminjam
22.	void DeleteRelation_first
PIC : Faizal
Penjelasan : Hapus elemen relation pertama dalam List relation.
23.	void DeleteRelation_last
PIC : Faizal
Penjelasan : Hapus elemen relation terakhir dalam List relation.
24.	void DeleteRelation_after
PIC : Faizal
Penjelasan : Hapus elemen relation setelah elemen prec dalam List relation.
25.	void findBuku
PIC : Faizal
Penjelasan : Cari elemen buku berdasarkan penulis atau judul.
26.	void findPeminjam
PIC : Sofwan
Penjelasan : Fungsi ini mencari dan mengembalikan referensi ke elemen peminjam berdasarkan kriteria tertentu dalam list peminjam.
27.	void findRelation_BukudanPeminjam
PIC : Sofwan
Penjelasan : Fungsi ini mencari dan mengidentifikasi hubungan antara buku dan peminjam, memberikan detail tentang buku yang dipinjam oleh peminjam tertentu
28.	void showAllBuku
PIC : Faizal
Penjelasan : Tampilkan semua elemen di List buku.
29.	void showAllPeminjam
PIC : Sofwan
Penjelasan : Fungsi ini menampilkan semua informasi tentang peminjam yang terdaftar dalam list peminjam
30.	void ShowDataPeminjam_DariBuku
PIC : Sofwan
Penjelasan : Fungsi ini menampilkan informasi tentang peminjam berdasarkan buku yang mereka pinjam, memberikan detail khusus mengenai peminjaman tersebut
31.	void showDataBukuBesertaPeminjamnya
PIC : Faizal
Penjelasan : Tampilkan semua buku beserta peminjam yang berelasi dengannya.
32.	void showDataPeminjamBesertaBukuYangDiPinjam
PIC : Sofwan
Penjelasan : Fungsi ini menampilkan informasi tentang peminjam bersama dengan detail buku yang dipinjam oleh mereka, menyediakan tinjauan komprehensif mengenai transaksi peminjaman buku
33.	void showDataBukuDariListPeminjam
PIC : Faizal
Penjelasan : Tampilkan semua data buku yang berelasi dengan peminjam tertentu.
34.	void hitungRelationDariSetiapBuku
PIC : Faizal
Penjelasan : Hitung jumlah relation yang dimiliki oleh setiap buku.
35.	void hitungRelationYangDimilikiPeminjam
PIC : Sofwan
Penjelasan : Fungsi ini menghitung jumlah relasi yang dimiliki oleh setiap peminjam, memberikan statistik tentang seberapa banyak buku yang telah atau sedang dipinjam oleh masing-masing peminjam
36.	void hitungPeminjamYangTidakBerrelasi
PIC : Sofwan
Penjelasan : Fungsi ini menghitung jumlah peminjam yang tidak memiliki relasi peminjaman aktif, yaitu mereka yang saat ini tidak meminjam buku apa pun
37.	void editRelasiDariParent
PIC : Faizal
Penjelasan : Edit relation dari parent tertentu.
