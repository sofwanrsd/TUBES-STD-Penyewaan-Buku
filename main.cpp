#include <iostream>
#include "tubes.h"

using namespace std;

int main() {
    ListBuku LB;
    ListPeminjam LP;
    createListBuku(LB);
    createListPeminjam(LP);

/* ======================= DATA DUMMY BER-RELASI ======================= */
// DATA INSERT BUKU
adrBuku B1 = createNewElemenBuku({"B1", "Tere_Liye", "Bumi", "Tersedia"});
adrBuku B2 = createNewElemenBuku({"B2", "Tere_Liye", "Komet Minor", "Tersedia"});
adrBuku B3 = createNewElemenBuku({"B3", "Tere_Liye", "Bulan", "Tersedia"});
adrBuku B4 = createNewElemenBuku({"B4", "Tere_Liye", "Matahari", "Tersedia"});
adrBuku B5 = createNewElemenBuku({"B5", "Tere_Liye", "Komet", "Tersedia"});
adrBuku B6 = createNewElemenBuku({"B6", "Tere_Liye", "Pulang", "Tersedia"});
adrBuku B7 = createNewElemenBuku({"B7", "Tere_Liye", "Pergi", "Tersedia"});
adrBuku B8 = createNewElemenBuku({"B8", "Tere_Liye", "Hujan", "Tersedia"});
adrBuku B9 = createNewElemenBuku({"B9", "Tere_Liye", "Rindu", "Tersedia"});

InsertBuku_first(LB, B1);
InsertBuku_first(LB, B2);
InsertBuku_first(LB, B3);
InsertBuku_last(LB, B4);
InsertBuku_last(LB, B5);
InsertBuku_last(LB, B6);
InsertBuku_after(LB, B7, B6);
InsertBuku_after(LB, B8, B7);
InsertBuku_after(LB, B9, B8);

// DATA INSERT PEMINJAM
adrPeminjam P1 = createNewElemenPeminjam({"P1", "Sofwan", "2022-01-01", "2022-01-15"});
adrPeminjam P2 = createNewElemenPeminjam({"P2", "Faizal", "2022-02-01", "2022-02-15"});
adrPeminjam P3 = createNewElemenPeminjam({"P3", "Alya", "2022-03-01", "2022-03-15"});
adrPeminjam P4 = createNewElemenPeminjam({"P4", "Rizky", "2022-04-01", "2022-04-15"});
adrPeminjam P5 = createNewElemenPeminjam({"P5", "Luna", "2022-05-01", "2022-05-15"});
adrPeminjam P6 = createNewElemenPeminjam({"P6", "Mira", "2022-06-01", "2022-06-15"});
adrPeminjam P7 = createNewElemenPeminjam({"P7", "Anto", "2022-07-01", "2022-07-15"});
adrPeminjam P8 = createNewElemenPeminjam({"P8", "Nina", "2022-08-01", "2022-08-15"});
adrPeminjam P9 = createNewElemenPeminjam({"P9", "Fajar", "2022-09-01", "2022-09-15"});

InsertPeminjam_first(LP, P1);
InsertPeminjam_first(LP, P2);
InsertPeminjam_first(LP, P3);
InsertPeminjam_last(LP, P4);
InsertPeminjam_last(LP, P5);
InsertPeminjam_last(LP, P6);
InsertPeminjam_after(LP, P7, P6);
InsertPeminjam_after(LP, P8, P7);
InsertPeminjam_after(LP, P9, P8);

// DATA UNTUK RELASI
adrRelation R1 = createNewElemenRelation(P1);
adrRelation R2 = createNewElemenRelation(P2);
adrRelation R3 = createNewElemenRelation(P3);
adrRelation R4 = createNewElemenRelation(P4);
adrRelation R5 = createNewElemenRelation(P5);
adrRelation R6 = createNewElemenRelation(P6);
adrRelation R7 = createNewElemenRelation(P7);
adrRelation R8 = createNewElemenRelation(P8);
adrRelation R9 = createNewElemenRelation(P9);

InsertRelation_first(LB, B1, R1);
info(B1).status = "Dipinjam";
InsertRelation_first(LB, B2, R2);
info(B2).status = "Dipinjam";
InsertRelation_first(LB, B3, R3);
info(B3).status = "Dipinjam";
InsertRelation_last(LB, B4, R4);
info(B4).status = "Dipinjam";
InsertRelation_last(LB, B5, R5);
info(B5).status = "Dipinjam";
InsertRelation_last(LB, B6, R6);
info(B6).status = "Dipinjam";
InsertRelation_after(LB, B7, R7, R6);
info(B7).status = "Dipinjam";
InsertRelation_after(LB, B8, R8, R7);
info(B8).status = "Dipinjam";
InsertRelation_after(LB, B9, R9, R8);
info(B9).status = "Dipinjam";

/*======================= DATA DUMMY BER-RELASI ======================= */
/*======================= DATA DUMMY NON-RELASI =======================*/
//BUKU
adrBuku B10 = createNewElemenBuku({"B10", "Andrea Hirata", "Laskar pelangi", "Tersedia"});
adrBuku B11 = createNewElemenBuku({"B11", "Andrea Hirata", "Sang Pemimpi", "Tersedia"});
adrBuku B12 = createNewElemenBuku({"B12", "Andrea Hirata", "Ayah", "Tersedia"});

InsertBuku_first(LB,B10);
InsertBuku_last(LB,B11);
InsertBuku_after(LB, B12,B11);

//Peminjam
adrPeminjam P10 = createNewElemenPeminjam({"P10", "Dimas", "2022-10-01", "2022-11-15"});
adrPeminjam P11 = createNewElemenPeminjam({"P11", "Sofwan", "2022-11-01", "2022-12-15"});
adrPeminjam P12 = createNewElemenPeminjam({"P12", "Faizal", "2022-12-01", "2023-1-15"});

InsertPeminjam_first(LP, P10);
InsertPeminjam_last(LP,P11);
InsertPeminjam_after(LP,P12,P11);
/* ======================= DATA DUMMY NON-RELASI =======================*/

    int pilihan;
    do {
        cout << "=========================================" << endl;
        cout << "       PROGRAM PENGELOLAAN PERPUSTAKAAN  " << endl;
        cout << "=========================================" << endl;
        cout << "1.  Tambah Buku" << endl;
        cout << "2.  Tambah Peminjam" << endl;
        cout << "3.  Pinjam Buku" << endl;
        cout << "4.  Hapus Buku" << endl;
        cout << "5.  Kembalikan Buku" << endl;
        cout << "6.  Hapus Peminjam" << endl;
        cout << "7.  Cari Buku" << endl;
        cout << "8.  Cari Relasi" << endl;
        cout << "9.  Cari Peminjam" << endl;
        cout << "10. Tampilkan Semua Buku" << endl;
        cout << "11. Tampilkan Semua Peminjam" << endl;
        cout << "12. Tampilkan Semua Peminjam dari Buku Tertentu" << endl;
        cout << "13. Tampilkan Semua Buku Beserta Peminjamnya" << endl;
        cout << "14. Tampilkan Semua Peminjam Beserta Buku yang dipinjamnya" << endl;
        cout << "15. Tampilkan Semua Buku dari Peminjam Tertentu" << endl;
        cout << "16. Hitung Relasi Dari Setiap Buku" << endl;
        cout << "17. Hitung Relasi Dari Peminjam Tertentu" << endl;
        cout << "18. Hitung Child yang Tidak Memiliki Relasi" << endl;
        cout << "19. Edit Relasi Dari Buku Tertentu" << endl;

        cout << "0. Keluar" << endl;
        cout << "=========================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Tambah Buku
            infotype_buku bukuBaru;
            cout << "Masukkan Kode Buku: ";
            cin >> bukuBaru.KodeBuku;
            cout << "Masukkan Judul Buku: ";
            cin.ignore();
            getline(cin, bukuBaru.judul);
            cout << "Masukkan Penulis Buku: ";
            getline(cin, bukuBaru.penulis);
            bukuBaru.status = "Tersedia";

            adrBuku B = createNewElemenBuku(bukuBaru);

            int metode;
            cout << "Tambahkan buku di: 1. Awal 2. Akhir 3. Setelah Buku Lain: ";
            cin >> metode;

            if (metode == 1) {
                InsertBuku_first(LB, B);
            } else if (metode == 2) {
                InsertBuku_last(LB, B);
            } else if (metode == 3) {
                string kodePrec;
                cout << "Masukkan Kode Buku Sebelumnya: ";
                cin >> kodePrec;
                adrBuku prec = first(LB);
                while (prec != NULL && info(prec).KodeBuku != kodePrec) {
                    prec = next(prec);
                }
                if (prec != NULL) {
                    InsertBuku_after(LB, B, prec);
                } else {
                    cout << "Buku dengan kode tersebut tidak ditemukan!" << endl;
                }
            }
            cout << "Buku berhasil ditambahkan!" << endl;
        } else if (pilihan == 2) {
            // Tambah Peminjam
            infotype_peminjam peminjamBaru;
            cout << "Masukkan ID Peminjam: ";
            cin >> peminjamBaru.IDPeminjam;
            cout << "Masukkan Nama Peminjam: ";
            cin.ignore();
            getline(cin, peminjamBaru.nama);
            cout << "Masukkan Tanggal Pinjam (YYYY-MM-DD): ";
            cin >> peminjamBaru.TanggalPinjam;
            cout << "Masukkan Tanggal Kembali (YYYY-MM-DD): ";
            cin >> peminjamBaru.TanggalKembali;

            adrPeminjam P = createNewElemenPeminjam(peminjamBaru);

            int metode;
            cout << "Tambahkan peminjam di: " << endl;
            cout << "1. Awal" << endl;
            cout << "2. Akhir " << endl;
            cout << "3. Setelah Peminjam Lain " << endl;
            cout << "Masukan Opsi : ";
            cin >>  metode;

            if (metode == 1) {
                InsertPeminjam_first(LP, P);
            } else if (metode == 2) {
                InsertPeminjam_last(LP, P);
            } else if (metode == 3) {
                string IDPrec;
                cout << "Masukkan ID Peminjam Sebelumnya: ";
                cin >> IDPrec;
                adrPeminjam prec = first(LP);
                while (prec != NULL && info(prec).IDPeminjam != IDPrec) {
                    prec = next(prec);
                }
                if (prec != NULL) {
                    InsertPeminjam_after(LP, P, prec);
                } else {
                    cout << "Peminjam dengan ID tersebut tidak ditemukan!" << endl;
                }
            }
            cout << "Peminjam berhasil ditambahkan!" << endl;
        } else if (pilihan == 3) {
            // Pinjam Buku
            string kodeBuku, IDPeminjam;
            cout << "Masukkan Kode Buku yang Ingin Dipinjam: ";
            cin >> kodeBuku;
            cout << "Masukkan ID Peminjam: ";
            cin >> IDPeminjam;

            adrBuku B = first(LB);
            while (B != NULL && info(B).KodeBuku != kodeBuku) {
                B = next(B);
            }

            adrPeminjam P = first(LP);
            while (P != NULL && info(P).IDPeminjam != IDPeminjam) {
                P = next(P);
            }

            if (B != NULL && P != NULL) {
                if (info(B).status == "Tersedia") {
                    adrRelation R = createNewElemenRelation(P);
                    InsertRelation_first(LB, B, R);
                    info(B).status = "Dipinjam";
                    cout << "Buku berhasil dipinjam!" << endl;
                } else {
                    cout << "Buku sedang dipinjam, menambahkan ke antrian peminjam..." << endl;
                    adrRelation R = createNewElemenRelation(P);
                    InsertRelation_last(LB, B, R);
                }
            } else {
                cout << "Buku atau peminjam tidak ditemukan!" << endl;
            }
        } else if (pilihan == 4) {
            // Delete Buku
            string kodeBuku;
            cout << "Masukkan Kode Buku yang Akan Dihapus: ";
            cin >> kodeBuku;

            adrBuku B = first(LB);
            adrBuku prec = NULL;

            while (B != NULL && info(B).KodeBuku != kodeBuku) {
                prec = B;
                B = next(B);
            }

            if (B != NULL) {
                if (B == first(LB)) {
                    DeleteBuku_first(LB, B);
                } else if (next(B) == NULL) {
                    DeleteBuku_last(LB, B);
                } else {
                    DeleteBuku_after(LB, B, prec);
                }
                cout << "Buku berhasil dihapus!" << endl;
            } else {
                cout << "Buku dengan kode tersebut tidak ditemukan!" << endl;
            }
        } else if (pilihan == 5) {
            // Kembalikan Buku
            string kodeBuku;
            cout << "Masukkan Kode Buku yang Dikembalikan: ";
            cin >> kodeBuku;

            adrBuku B = first(LB);
            while (B != NULL && info(B).KodeBuku != kodeBuku) {
                B = next(B);
            }

            if (B != NULL) {
                if (relation(B).first != NULL) {
                    adrRelation R = relation(B).first;
                    DeleteRelation_first(relation(B),R);

                    if (relation(B).first == NULL) {
                        info(B).status = "Tersedia";
                    }
                    cout << "Buku berhasil dikembalikan!" << endl;
                } else {
                    cout << "Buku tidak sedang dipinjam!" << endl;
                }
            } else {
                cout << "Buku tidak ditemukan!" << endl;
            }
        } else if (pilihan == 6) {
            // Delete Peminjam
            string IDPeminjam;
            cout << "Masukkan ID Peminjam yang Akan Dihapus: ";
            cin >> IDPeminjam;

            adrPeminjam P = first(LP);
            adrPeminjam prec = NULL;

            while (P != NULL && info(P).IDPeminjam != IDPeminjam) {
                prec = P;
                P = next(P);
            }

            if (P != NULL) {
                if (P == first(LP)) {
                    DeletePeminjam_first(LP, LB, P);
                } else if (P == last(LP)) {
                    DeletePeminjam_last(LP,LB, P);
                } else {
                    DeletePeminjam_after(LP,LB, P, prec);
                }
                cout << "Peminjam berhasil dihapus!" << endl;
            } else {
                cout << "Peminjam dengan ID tersebut tidak ditemukan!" << endl;
            }
        } else if (pilihan == 7) {
            // Cari Buku
            string judul, penulis;
            cout << "Masukkan Judul Buku: ";
            cin.ignore();
            getline(cin, judul);
            cout << "Masukkan Penulis Buku: ";
            getline(cin, penulis);
            findBuku(LB, penulis, judul);
        } else if (pilihan == 8) {
            // Cari Relasi
            string kodeBuku, IDPeminjam;
            cout << "Masukkan Kode Buku: ";
            cin >> kodeBuku;
            cout << "Masukkan ID Peminjam: ";
            cin >> IDPeminjam;

            adrBuku B = first(LB);
            while (B != NULL && info(B).KodeBuku != kodeBuku) {
                B = next(B);
            }

            adrPeminjam P = first(LP);
            while (P != NULL && info(P).IDPeminjam != IDPeminjam) {
                P = next(P);
            }

            if (B != NULL && P != NULL) {
                findRelation_BukudanPeminjam(LB, B, P);
            } else {
                cout << "Relasi Tidak DiTemukan" << endl;
            }
        } else if (pilihan == 9) {
            // Cari Peminjam
            string IDPeminjam;
            cout << "Masukkan ID Peminjam: ";
            cin >> IDPeminjam;
            findPeminjam(LP, IDPeminjam);
        } else if (pilihan == 10) {
            // Tampilkan Semua Buku
            showAllBuku(LB);
        } else if (pilihan == 11) {
            // Tampilkan Semua Peminjam
            showAllPeminjam(LP);
        } else if (pilihan == 12) {
            // Tampilkan Buku dan Peminjamnya
            string InJudul, inPenulis;
            cout << "Masukkan Judul: ";
            cin >> InJudul;
            cout << "Masukkan Penulis: ";
            cin >> inPenulis;
            ShowDataPeminjam_DariBuku(LB, InJudul, inPenulis);
        } else if (pilihan == 13) {
            // Tampilkan Peminjam dan Buku yang Dipinjam
            showDataBukuBesertaPeminjamnya(LB);
        } else if (pilihan == 14) {
            // Tampilkan Semua Peminjam Beserta Buku yang dipinjamnya
            showDataPeminjamBesertaBukuYangDiPinjam(LP,LB);
        } else if (pilihan == 15) {
            // Tampilkan Semua Buku dari Peminjam Tertentu
            string InIDPeminjam;
            cout << "Masukkan ID Peminjam: ";
            cin >> InIDPeminjam;
            showDataBukuDariListPeminjam(LP,LB,InIDPeminjam);
        } else if (pilihan == 16) {
            // Hitung Relasi Dari Setiap Buku
            hitungRelationDariSetiapBuku(LB);
        } else if (pilihan == 17) {
            // Hitung Relasi Dari Peminjam Tertentu
            string IDTargetP;
            cout << "Masukkan ID Peminjam: ";
            cin >> IDTargetP;
            hitungRelationYangDimilikiPeminjam(LP,LB,IDTargetP);
        } else if (pilihan == 18) {
            // Hitung Child yang Tidak Memiliki Relasi
            hitungPeminjamYangTidakBerrelasi(LP,LB);
        } else if (pilihan == 19) {
            // Edit Relasi Dari Buku Tertentu
            string kodeBuku, idPeminjamBaru;
            cout << "Masukkan Kode Buku: ";
            cin >> kodeBuku;
            cout << "Masukkan ID Peminjam Baru: ";
            cin >> idPeminjamBaru;
            editRelasiDariParent(LB, LP, kodeBuku, idPeminjamBaru);
            cout << "Relasi berhasil diedit" << endl;
        } else if (pilihan == 0) {
            cout << "Terima kasih telah menggunakan program ini!" << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
