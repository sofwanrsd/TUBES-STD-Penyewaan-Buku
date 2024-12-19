#include <iostream>
#include "tubes.h"

using namespace std;

void createListBuku(ListBuku &LB){
/* IS: List kosong atau belum memiliki elemen.
   PROSES: Fungsi ini akan menginisialisasi list buku L.
   FS: List L telah diinisialisasi sebagai list kosong.
   PIC: Faizal
*/
    first(LB) = NULL;
};
void createListPeminjam(ListPeminjam &LP){
/* IS: List kosong atau belum memiliki elemen.
   PROSES: Fungsi ini akan menginisialisasi list peminjam L.
   FS: List L telah diinisialisasi sebagai list kosong.
   PIC: Sofwan
*/
    first(LP) = NULL;
    last(LP) = NULL;
};
void createListRelation(ListRelation &LR){
/* IS: List kosong atau belum memiliki elemen.
   PROSES: Fungsi ini akan menginisialisasi list relation L.
   FS: List L telah diinisialisasi sebagai list kosong.
   PIC: Faizal
*/
    first(LR) = NULL;
};

adrBuku createNewElemenBuku(infotype_buku X){
/* IS: X berisi informasi yang valid untuk sebuah buku.
   PROSES: Fungsi ini akan membuat elemen baru untuk buku.
   FS: Pointer adrBuku baru telah dibuat, diisi dengan data X.
   PIC: Faizal
*/
    adrBuku B;
    B = new elmBuku;
    info(B) = X;
    next(B) = NULL;
    createListRelation(relation(B));
    return B;
};

adrPeminjam createNewElemenPeminjam(infotype_peminjam X){
/* IS: X berisi informasi yang valid untuk sebuah peminjam.
   PROSES: Fungsi ini akan membuat elemen baru untuk peminjam.
   FS: Pointer adrPeminjam baru telah dibuat, diisi dengan data X.
   PIC: Sofwan
*/
    adrPeminjam P;
    P = new elmPeminjam;
    info(P) = (X);
    next(P) = NULL;
    prev(P) = NULL;
    return P;
};

adrRelation createNewElemenRelation(adrPeminjam P){
 /* IS: X berisi informasi yang valid untuk sebuah relation.
   PROSES: Fungsi ini akan membuat elemen baru untuk relation.
   FS: Pointer adrRelation baru telah dibuat, diisi dengan data X.
   PIC: Sofwan
*/
    adrRelation R = new elmRelation;
    nextRelation(R) = NULL;
    nextPeminjam(R) = P;
    return R;
};

void InsertBuku_first(ListBuku &LB, adrBuku B){
/* IS: List buku kosong atau sudah berisi beberapa elemen.
   PROSES: Tambahkan elemen baru ke List buku di posisi pertama.
   FS: Elemen baru berhasil ditambahkan ke List buku.
   PIC: Faizal
*/
    if (first(LB) == NULL) {
        first(LB) = B;
        next(B) = NULL;
        relation(B).first = NULL;
    } else {
        next(B) = first(LB);
        first(LB) = B;
        relation(B).first = NULL;
    }
};

void InsertBuku_last(ListBuku &LB, adrBuku B){
/* IS: List buku kosong atau sudah berisi beberapa elemen.
   PROSES: Tambahkan elemen baru ke List buku di posisi terakhir.
   FS: Elemen baru berhasil ditambahkan ke List buku.
   PIC: Faizal
*/
    if (first(LB) == NULL) {
        first(LB) = B;
        next(B) = NULL;
        relation(B).first = NULL;
    } else {
        adrBuku P = first(LB);
        while (next(P) != NULL) {
            P = next(P);
        }
        next(P) = B;
        next(B) = NULL;
        relation(B).first = NULL;
    }
};

void InsertBuku_after(ListBuku &LB, adrBuku B, adrBuku prec){
/* IS: List buku berisi elemen-elemen dan terdapat elemen referensi prec.
   PROSES: Tambahkan elemen B setelah elemen prec dalam List buku.
   FS: Elemen baru berhasil ditambahkan setelah elemen prec.
   PIC: Faizal
*/
    if (first(LB) == NULL) {
        cout << "List kosong, tidak bisa menyisipkan setelah elemen tertentu." << endl;
        relation(B).first = NULL;
    } else if (prec == NULL) {
        cout << "Elemen prec tidak boleh NULL." << endl;
        relation(B).first = NULL;
    } else {
        next(B) = next(prec);
        next(prec) = B;
        relation(B).first = NULL;
    }
};

void InsertPeminjam_first(ListPeminjam &L, adrPeminjam P){
/* IS: List peminjam kosong atau sudah berisi beberapa elemen.
   PROSES: Tambahkan elemen baru ke List peminjam di posisi pertama.
   FS: Elemen baru berhasil ditambahkan ke List peminjam.
   PIC: Sofwan
*/
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
        prev(P) = NULL;
    }
};

void InsertPeminjam_last(ListPeminjam &L, adrPeminjam P){
/* IS: List peminjam kosong atau sudah berisi beberapa elemen.
   PROSES: Tambahkan elemen baru ke List peminjam di posisi terakhir.
   FS: Elemen baru berhasil ditambahkan ke List peminjam.
   PIC: Sofwan
*/
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
};

void InsertPeminjam_after(ListPeminjam &L, adrPeminjam P, adrPeminjam prec){
/* IS: List peminjam berisi elemen-elemen dan terdapat elemen referensi prec.
   PROSES: Tambahkan elemen P setelah elemen prec dalam List peminjam.
   FS: Elemen baru berhasil ditambahkan setelah elemen prec.
   PIC: Sofwan
*/
    if (prec == last(L)) {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    } else {
        next(P) = next(prec);
        prev(next(prec)) = P;
        next(prec) = P;
        prev(P) = prec;
    }
};


void InsertRelation_first(ListBuku &L, adrBuku B, adrRelation R){
/* IS: List buku berisi satu atau lebih elemen, dan ada elemen buku yang terkait dengan relation.
   PROSES: Tambahkan relation baru R di posisi pertama dalam List relation yang terkait dengan buku B.
   FS: Relation baru berhasil ditambahkan di awal List relation untuk buku B.
   PIC: Sofwan
*/
    if (relation(B).first == NULL) {
        relation(B).first = R;
        nextRelation(R) = NULL;
    } else {
        nextRelation(R) = relation(B).first;
        relation(B).first = R;
    }
};

void InsertRelation_last(ListBuku &L, adrBuku B, adrRelation R){
/* IS: List relation kosong atau sudah berisi beberapa elemen.
   PROSES: Tambahkan elemen baru ke List relation di posisi terakhir.
   FS: Elemen baru berhasil ditambahkan ke List relation.
   PIC: Sofwan
*/
    if (relation(B).first == NULL) {
        relation(B).first = R;
        nextRelation(R) = NULL;
    } else {
        adrRelation P = relation(B).first;
        while (nextRelation(P) != NULL) {
            P = nextRelation(P);
        }
        nextRelation(P) = R;
        nextRelation(R) = NULL;
    }
};

void InsertRelation_after(ListBuku &L, adrBuku B, adrRelation R, adrRelation prec){
/* IS: List buku berisi satu atau lebih elemen, dan terdapat elemen referensi prec pada List relation.
   PROSES: Tambahkan relation baru R setelah elemen relation prec dalam List relation yang terkait dengan buku B.
   FS: Relation baru berhasil ditambahkan setelah elemen prec dalam List relation untuk buku B.
   PIC: Sofwan
*/
    if (prec == NULL) {
        cout << "Gagal Menambahkan!" << endl;
        nextRelation(R) = NULL;
    } else {
        nextRelation(R) = nextRelation(prec);
        nextRelation(prec) = R;
    }
};

void DeleteBuku_first(ListBuku &L, adrBuku &B){
/* IS: List buku berisi satu atau lebih elemen.
   PROSES: Hapus elemen buku pertama dalam List buku.
   FS: Elemen buku pertama berhasil dihapus dari List buku.
   PIC: Faizal
*/
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
        B = NULL;
    } else {
        // Jika list hanya memiliki satu elemen
        if (next(first(L)) == NULL) {
            B = first(L);
            first(L) = NULL;
        } else {
            // Jika list memiliki lebih dari satu elemen
            B = first(L);
            first(L) = next(first(L));
        }
        next(B) = NULL;
        relation(B).first = NULL;
        delete B;
        cout << "Elemen pertama berhasil dihapus." << endl;
    }
};

void DeleteBuku_last(ListBuku &L, adrBuku &B){
/* IS: List buku berisi satu atau lebih elemen.
   PROSES: Hapus elemen buku terakhir dalam List buku.
   FS: Elemen buku terakhir berhasil dihapus dari List buku.
   PIC: Faizal
*/
    if (first(L) == NULL) {
        // Jika list kosong
        B = NULL;
        cout << "Error: List kosong, tidak ada elemen yang bisa dihapus." << endl;
    } else if (next(first(L)) == NULL) {
        // Jika list hanya memiliki satu elemen
        B = first(L);
        first(L) = NULL;
        next(B) = NULL;
        relation(B).first = NULL;
    } else {
        // Jika list memiliki lebih dari satu elemen
        adrBuku P = first(L);
        while (next(next(P)) != NULL) {
            P = next(P);
        }
        B = next(P);
        next(P) = NULL;
        relation(B).first = NULL;
    }
};

void DeleteBuku_after(ListBuku &L, adrBuku &B, adrBuku prec){
/* IS: List buku berisi elemen-elemen dan terdapat elemen referensi prec.
   PROSES: Hapus elemen buku setelah elemen prec dalam List buku.
   FS: Elemen buku setelah prec berhasil dihapus dari List buku.
   PIC: Faizal
*/
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
        B = NULL;  // Tidak ada elemen yang dapat dihapus
    } else if (prec == NULL || next(prec) == NULL) {
        // Jika elemen prec tidak valid atau tidak ada elemen setelah prec
        B = NULL;
        cout << "Elemen prec tidak valid atau tidak ada elemen setelahnya." << endl;
    } else {
        // Jika elemen setelah prec ada
        B = next(prec);
        next(prec) = next(B);
        next(B) = NULL;
        relation(B).first = NULL;
        delete B;
        cout << "Elemen setelah prec berhasil dihapus." << endl;
    }
};

void DeletePeminjam_first(ListPeminjam &LP, ListBuku &LB, adrPeminjam &P){
/* IS: List peminjam berisi satu atau lebih elemen.
   PROSES: Hapus elemen peminjam pertama dalam List peminjam.
   FS: Elemen peminjam pertama berhasil dihapus dari List peminjam.
   PIC: Sofwan
*/
    // Cek jika list kosong
    if (first(LP) == NULL) {
        cout << "Daftar Peminjam kosong!" << endl;
    } else {
        P = first(LP);
        adrBuku B = first(LB);
        while (B != NULL) {
            adrRelation RelasiTerhubung = NULL;
            adrRelation R = relation(B).first;

            while (R != NULL) {
                if (nextPeminjam(R) == P) {
                    if (RelasiTerhubung == NULL) {
                        relation(B).first = nextRelation(R);
                    } else {
                        nextRelation(RelasiTerhubung) = nextRelation(R);
                    }
                    adrRelation tempRel = R;
                    R = nextRelation(R);
                    delete tempRel;
                } else {
                    RelasiTerhubung = R;
                    R = nextRelation(R);
                }
            }
            B = next(B);
        }

        if (first(LP) == last(LP)) {
            first(LP) = NULL;
            last(LP) = NULL;
        } else {
            first(LP) = next(P);
            prev(first(LP)) = NULL;
        }
        next(P) = NULL;
        prev(P) = NULL;
        delete P;
        cout << "Peminjam berhasil dihapus dari daftar pertama." << endl;
    }
};

void DeletePeminjam_last(ListPeminjam &L, ListBuku LB, adrPeminjam &P){
/* IS: List peminjam berisi satu atau lebih elemen.
   PROSES: Hapus elemen peminjam terakhir dalam List peminjam.
   FS: Elemen peminjam terakhir berhasil dihapus dari List peminjam.
   PIC: Sofwan
*/
    adrBuku B = first(LB);
    while (B != NULL) {
        adrRelation RelasiTerhubung = NULL;
        adrRelation R = relation(B).first;
        while (R != NULL) {
            if (nextPeminjam(R) == P) {
                if (RelasiTerhubung == NULL) {
                    relation(B).first = nextRelation(R);
                } else {
                    nextRelation(RelasiTerhubung) = nextRelation(R);
                }
                adrRelation tempRel = R;
                R = nextRelation(R);
                delete tempRel;
            } else {
                RelasiTerhubung = R;
                R = nextRelation(R);
            }
        }
        B = next(B);
    }
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List Peminjam kosong, tidak ada elemen yang bisa dihapus." << endl;
    } else {
        // Jika list hanya memiliki satu elemen
        if (first(L) == last(L)) {
            P = last(L);
            first(L) = NULL;
            last(L) = NULL;
        } else {
            // Jika list memiliki lebih dari satu elemen
            P = last(L);
            last(L) = prev(P);
            next(last(L)) = NULL;
        }
        prev(P) = NULL;
        next(P) = NULL;
        delete P;
        cout << "Elemen Dihapus menggunakan Delete-last." << endl;
    }
};

void DeletePeminjam_after(ListPeminjam &L,ListBuku LB, adrPeminjam &P, adrPeminjam prec){
/* IS: List peminjam berisi elemen-elemen dan terdapat elemen referensi prec.
   PROSES: Hapus elemen peminjam setelah elemen prec dalam List peminjam.
   FS: Elemen peminjam setelah prec berhasil dihapus dari List peminjam.
   PIC: Sofwan
*/
    adrBuku B = first(LB);
    while (B != NULL) {
        adrRelation R = relation(B).first;
        adrRelation RelasiTerhubung = NULL;
        while (R != NULL) {
            if (nextPeminjam(R) == P) {
                if (RelasiTerhubung == NULL) {
                    relation(B).first = nextRelation(R);
                } else {
                    nextRelation(RelasiTerhubung) = nextRelation(R);
                }
                adrRelation tempRel = R;
                R = nextRelation(R);
                delete tempRel;
            } else {
                RelasiTerhubung = R;
                R = nextRelation(R);
            }
        }
        B = next(B);
    }

    // Cek jika next(prec) NULL, artinya tidak ada elemen setelah prec
    if (next(prec) == NULL) {
        cout << "Tidak ada elemen lagi!" << endl;
    } else {
        P = next(prec);
        //  jika elemen setelah prec adalah elemen terakhir
        if (next(P) == NULL) {
            last(L) = prec;
            next(prec) = NULL;
        } else {
            // Jika elemen setelah prec berada di tengah list
            next(prec) = next(P);
            prev(next(P)) = prec;
        }
        next(P) = NULL;
        prev(P) = NULL;
        delete P;
        cout << "Elemen Dihapus menggunakan Delete-After." << endl;
    }
};

void DeleteRelation_first(ListRelation &L, adrRelation &R){
/* IS: List relation berisi satu atau lebih elemen.
   PROSES: Hapus elemen relation pertama dalam List relation.
   FS: Elemen relation pertama berhasil dihapus dari List relation.
   PIC: Faizal
*/
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List Relation kosong!" << endl;
        R = NULL;
    } else {
        // Jika hanya ada satu elemen
        if (nextRelation(first(L)) == NULL) {
            R = first(L);
            first(L) = NULL;
        } else {
            // Jika list memiliki lebih dari satu elemen
            R = first(L);
            first(L) = nextRelation(first(L));
        }
        nextRelation(R) = NULL;
        delete R;
        cout << "Berhasil Mengembalikan Buku, Relation berhasil dihapus." << endl;
    }
};

void DeleteRelation_last(ListRelation &L, adrRelation &R){
/* IS: List relation berisi satu atau lebih elemen.
   PROSES: Hapus elemen relation terakhir dalam List relation.
   FS: Elemen relation terakhir berhasil dihapus dari List relation.
   PIC: Faizal
*/
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List Relation kosong, tidak ada elemen yang bisa dihapus." << endl;
        R = NULL;
    } else {
        // Jika hanya ada satu elemen
        if (nextRelation(first(L)) == NULL) {
            R = first(L);
            first(L) = NULL;
        } else {
            // Jika ada lebih dari satu elemen
            adrRelation P = first(L);
            while (nextRelation(nextRelation(P)) != NULL) {
                P = nextRelation(P);
            }
            R = nextRelation(P);
            nextRelation(P) = NULL;
        }
        delete R;
        cout << "Elemen terakhir pada ListRelation berhasil dihapus." << endl;
    }
};

void DeleteRelation_after(ListRelation &L, adrRelation &R, adrRelation prec){
/* IS: List relation berisi elemen-elemen dan terdapat elemen referensi prec.
   PROSES: Hapus elemen relation setelah elemen prec dalam List relation.
   FS: Elemen relation setelah prec berhasil dihapus dari List relation.
   PIC: Faizal
*/
    // Cek jika prec tidak valid atau tidak ada elemen setelah prec
    if (prec == NULL || nextRelation(prec) == NULL) {
        cout << "Elemen prec tidak valid atau tidak ada elemen setelahnya." << endl;
        R = NULL;
    } else {
        R = nextRelation(prec);
        nextRelation(prec) = nextRelation(R);
        nextRelation(R) = NULL;
        delete R;
        cout << "Elemen setelah prec berhasil dihapus." << endl;
    }
};

void findBuku(ListBuku L, string penulis, string judul){
/* IS: List buku berisi satu atau lebih elemen.
   PROSES: Cari elemen buku berdasarkan penulis atau judul.
   FS: Elemen buku ditemukan jika ada yang sesuai, atau tidak ditemukan jika tidak ada.
   PIC: Faizal
*/
    if (first(L) == NULL) {
        cout << "List buku kosong, tidak ada buku yang dapat dicari." << endl;
        return;
    }

    adrBuku P = first(L);
    bool found = false;

    cout << "Mencari buku dengan judul '" << judul << "' oleh penulis '" << penulis << "'..." << endl;
    while (P != NULL) {
        if (info(P).penulis == penulis && info(P).judul == judul) {
            found = true;
            cout << "Buku ditemukan:" << endl;
            cout << "Kode Buku: " << info(P).KodeBuku << endl;
            cout << "Judul: " << info(P).judul << endl;
            cout << "Penulis: " << info(P).penulis << endl;
            cout << "Status: " << info(P).status << endl;
        }
        P = next(P);
    }

    if (!found) {
        cout << "Buku dengan judul '" << judul << "' oleh penulis '" << penulis << "' tidak ditemukan." << endl;
    }
};

void findPeminjam(ListPeminjam L, string IDPeminjam){
/* IS: List peminjam berisi satu atau lebih elemen.
   PROSES: Cari elemen peminjam berdasarkan ID peminjam.
   FS: Elemen peminjam ditemukan jika ada yang sesuai, atau tidak ditemukan jika tidak ada.
   PIC: Sofwan
*/
    // Cek jika list kosong
    if (first(L) == NULL) {
        cout << "List peminjam kosong, tidak ada peminjam yang dapat dicari." << endl;
        return;
    }

    adrPeminjam P = first(L);
    bool found = false;

    cout << "Mencari peminjam dengan ID '" << IDPeminjam << "'..." << endl;
    while (P != NULL) {
        if (info(P).IDPeminjam == IDPeminjam) {
            found = true;
            cout << "Peminjam ditemukan:" << endl;
            cout << "ID Peminjam: " << info(P).IDPeminjam << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Tanggal Pinjam: " << info(P).TanggalPinjam << endl;
            cout << "Tanggal Kembali: " << info(P).TanggalKembali << endl;
        }
        P = next(P);
    }

    if (!found) {
        cout << "Peminjam dengan ID '" << IDPeminjam << "' tidak ditemukan." << endl;
    }
};

void findRelation_BukudanPeminjam(ListBuku L, adrBuku B, adrPeminjam P){
/* IS: Relation antara buku dan peminjam ada atau tidak ada.
   PROSES: Cari relation antara buku dan peminjam.
   FS: Relation ditemukan jika ada yang sesuai, atau tidak ditemukan jika tidak ada.
   PIC: Sofwan
*/
    // Cek apakah list buku kosong
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        adrBuku PencarianBuku = first(L);
        bool ditemukanBuku = false;

        while (PencarianBuku != NULL) {
            if (info(PencarianBuku).penulis == info(B).penulis && info(PencarianBuku).judul == info(B).judul) {
                ditemukanBuku = true;
                // Jika buku ditemukan
                adrRelation PencarianRelasi = relation(PencarianBuku).first;
                bool ditemukanRelasi = false;

                while (PencarianRelasi != NULL) {
                    // Jika peminjam ditemukan
                    if (nextPeminjam(PencarianRelasi) == P) {
                        ditemukanRelasi = true;
                        cout << "Relasi ditemukan:" << endl;
                        cout << "Buku: " << info(PencarianBuku).judul << " oleh " << info(PencarianBuku).penulis << endl;
                        cout << "Peminjam: " << info(P).nama << " (" << info(P).IDPeminjam << ")" << endl;
                    }
                    PencarianRelasi = nextRelation(PencarianRelasi);
                }

                if (!ditemukanRelasi) {
                    cout << "Relasi dengan peminjam ini tidak ditemukan." << endl;
                }
            }
            PencarianBuku = next(PencarianBuku);  // Pindah ke buku berikutnya
        }

        if (!ditemukanBuku) {
            cout << "Buku tidak ditemukan dalam list." << endl;
        }
    }
};

void showAllBuku(ListBuku L){
/* IS: List buku berisi satu atau lebih elemen.
   PROSES: Tampilkan semua elemen di List buku.
   FS: Semua elemen List buku ditampilkan.
   PIC: Faizal
*/
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        adrBuku P = first(L);
        cout << "Menampilkan semua data buku:" << endl;

        while (P != NULL) {
            cout << "Kode Buku: " << info(P).KodeBuku << endl;
            cout << "Judul: " << info(P).judul << endl;
            cout << "Penulis: " << info(P).penulis << endl;
            cout << "Status: " << info(P).status << endl;
            cout << "---------------------------------" << endl;
            P = next(P);
        }
    }
};

void showAllPeminjam(ListPeminjam L){
/* IS: List peminjam berisi satu atau lebih elemen.
   PROSES: Tampilkan semua elemen di List peminjam.
   FS: Semua elemen List peminjam ditampilkan.
   PIC: Sofwan
*/
    if (first(L) == NULL) {
        cout << "List Peminjam kosong!" << endl;
    } else {
        adrPeminjam P = first(L);
        cout << "Menampilkan semua data peminjam:" << endl;

        while (P != NULL) {
            cout << "ID Peminjam: " << info(P).IDPeminjam << endl;
            cout << "Nama Peminjam: " << info(P).nama << endl;
            cout << "Tanggal Pinjam: " << info(P).TanggalPinjam << endl;
            cout << "Tanggal Kembali: " << info(P).TanggalKembali << endl;
            cout << "---------------------------------" << endl;
            P = next(P);
        }
    }
};

void ShowDataPeminjam_DariBuku(ListBuku L, string judul, string penulis) {
/* IS: List buku berisi satu atau lebih elemen yang memiliki relation ke peminjam.
   PROSES: Tampilkan data peminjam yang meminjam buku tertentu.
   FS: Data peminjam terkait buku target berhasil ditampilkan.
   PIC: Sofwan
*/
    // jika ListBuku kosong
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        // jika judul atau penulis kosong
        if (judul == "" || penulis == "") {
            cout << "Input tidak valid! Judul dan Penulis harus diisi." << endl;
        } else {
            adrBuku P = first(L);
            bool foundBuku = false;

            // Mencari buku dengan judul dan penulis yang sesuai
            while (P != NULL) {
                if (info(P).judul == judul && info(P).penulis == penulis) {
                    foundBuku = true;
                    cout << "=========================================" << endl;
                    cout << "Buku ditemukan:" << endl;
                    cout << "Kode Buku: " << info(P).KodeBuku << endl;
                    cout << "Judul: " << info(P).judul << endl;
                    cout << "Penulis: " << info(P).penulis << endl;
                    cout << "Status: " << info(P).status << endl;
                    cout << endl;

                    // Menampilkan data peminjam yang berelasi dengan buku
                    adrRelation R = relation(P).first;
                    bool foundRelation = false;

                    while (R != NULL) {
                        cout << "Peminjam: " << info(nextPeminjam(R)).nama << endl;
                        cout << "ID Peminjam: " << info(nextPeminjam(R)).IDPeminjam << endl;
                        cout << "Tanggal Pinjam: " << info(nextPeminjam(R)).TanggalPinjam << endl;
                        cout << "Tanggal Kembali: " << info(nextPeminjam(R)).TanggalKembali << endl;
                        cout << endl;
                        R = nextRelation(R);
                        foundRelation = true;
                    }
                    cout << "=========================================" << endl;

                    if (!foundRelation) {
                        cout << "Tidak ada peminjam yang berelasi dengan buku ini." << endl;
                    }
                }
                P = next(P);
            }

            if (!foundBuku) {
                cout << "Buku dengan judul '" << judul << "' oleh penulis '" << penulis << "' tidak ditemukan." << endl;
            }
        }
    }
}

void showDataBukuBesertaPeminjamnya(ListBuku L){
/* IS: List buku dan peminjam berisi elemen dengan relation.
   PROSES: Tampilkan semua buku beserta peminjam yang berelasi dengannya.
   FS: Semua buku dan peminjam terkait berhasil ditampilkan.
   PIC: Faizal
*/
    // Cek jika List Buku kosong
    if (first(L) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        adrBuku P = first(L);

        // Loop untuk menampilkan semua data buku
        while (P != NULL) {
            cout << "Buku ditemukan:" << endl;
            cout << "Kode Buku: " << info(P).KodeBuku << endl;
            cout << "Judul: " << info(P).judul << endl;
            cout << "Penulis: " << info(P).penulis << endl;
            cout << "Status: " << info(P).status << endl;

            // Pembatas untuk buku
            cout << "---------------------------------" << endl;

            // Tampilkan peminjam-peminjam yang berelasi dengan buku
            adrRelation R = relation(P).first;
            bool foundRelation = false;

            while (R != NULL) {
                cout << "  Peminjam: " << info(nextPeminjam(R)).nama << endl;
                cout << "  ID Peminjam: " << info(nextPeminjam(R)).IDPeminjam << endl;
                cout << "  Tanggal Pinjam: " << info(nextPeminjam(R)).TanggalPinjam << endl;
                cout << "  Tanggal Kembali: " << info(nextPeminjam(R)).TanggalKembali << endl;
                R = nextRelation(R);
                foundRelation = true;
            }

            if (!foundRelation) {
                cout << "  Tidak ada peminjam yang berelasi dengan buku ini." << endl;
            }

            // Pembatas untuk setiap buku
            cout << "=============================" << endl;
            cout << endl;
            P = next(P);
        }
    }
};
void showDataPeminjamBesertaBukuYangDiPinjam(ListPeminjam &LP, ListBuku &LB){
/* IS: List peminjam dan buku berisi elemen dengan relation.
   PROSES: Tampilkan semua peminjam beserta buku yang berelasi dengannya.
   FS: Semua peminjam dan buku terkait berhasil ditampilkan.
   PIC: Sofwan
*/
    if (first(LP) == NULL) {
        cout << "List Peminjam kosong!" << endl;
    } else if (first(LB) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        adrPeminjam P = first(LP);
        while (P != NULL) {
            bool found = false;
            cout << "Peminjam ID: " << info(P).IDPeminjam << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Tanggal Pinjam: " << info(P).TanggalPinjam << endl;
            cout << "Tanggal Kembali: " << info(P).TanggalKembali << endl;

            adrBuku B = first(LB);
            while (B != NULL) {
                adrRelation R = relation_first(B);
                while (R != NULL) {
                    if (nextPeminjam(R) == P) {
                        found = true;
                        cout << "  Buku Kode: " << info(B).KodeBuku << endl;
                        cout << "  Judul: " << info(B).judul << endl;
                        cout << "  Penulis: " << info(B).penulis << endl;
                        cout << "  Status: " << info(B).status << endl;
                    }
                    R = nextRelation(R);
                }
                B = next(B);
            }

            if (!found) {
                cout << "  Peminjam ini tidak memiliki buku yang dipinjam." << endl;
            }
            //pembatas anatara peminjam
            cout << "================================" << endl;
            P = next(P);
        }
    }
};
void showDataBukuDariListPeminjam(ListPeminjam &LP, ListBuku &LB, string IDPeminjam){
/* IS: List peminjam berisi satu atau lebih elemen, dengan relation ke buku tertentu.
   PROSES: Tampilkan semua data buku yang berelasi dengan peminjam tertentu.
   FS: Data buku terkait peminjam target berhasil ditampilkan.
   PIC: Faizal
*/
    if (first(LP) == NULL) {
        cout << "List Peminjam kosong!" << endl;
    } else if (first(LB) == NULL) {
        cout << "List Buku kosong!" << endl;
    } else {
        adrPeminjam P = first(LP);
        bool found = false;
        while (P != NULL) {
            if (info(P).IDPeminjam == IDPeminjam) {
                found = true;
                cout << "Peminjam ID: " << info(P).IDPeminjam << endl;
                cout << "Nama: " << info(P).nama << endl;
                cout << "Tanggal Pinjam: " << info(P).TanggalPinjam << endl;
                cout << "Tanggal Kembali: " << info(P).TanggalKembali << endl;

                bool hasBooks = false;

                adrBuku B = first(LB);
                while (B != NULL) {
                    adrRelation R = relation_first(B);
                    while (R != NULL) {
                        if (nextPeminjam(R) == P) {
                            hasBooks = true;
                            cout << "  Buku Kode: " << info(B).KodeBuku << endl;
                            cout << "  Judul: " << info(B).judul << endl;
                            cout << "  Penulis: " << info(B).penulis << endl;
                            cout << "  Status: " << info(B).status << endl;
                        }
                        R = nextRelation(R);
                    }
                    B = next(B);
                }

                if (!hasBooks) {
                    cout << "  Peminjam ini tidak memiliki buku yang dipinjam." << endl;
                }
            }
            P = next(P);
        }

        if (!found) {
            cout << "Peminjam dengan ID " << IDPeminjam << " tidak ditemukan." << endl;
        }
    }
};

void hitungRelationDariSetiapBuku(ListBuku L){
/* IS: List buku berisi elemen dengan relation ke peminjam.
   PROSES: Hitung jumlah relation yang dimiliki oleh setiap buku.
   FS: Jumlah relation untuk setiap buku berhasil dihitung.
   PIC: Faizal

*/
    if (first(L) == NULL) {
        cout << "Tidak ada buku dalam daftar." << endl;
        return;
    }

    adrBuku currentBuku = first(L);
    while (currentBuku != NULL) {
        int count = 0;

        adrRelation currentRelation = relation_first(currentBuku);
        while (currentRelation != NULL) {
            count++;
            currentRelation = nextRelation(currentRelation);
        }
        cout << "Buku: " << info(currentBuku).judul
             << " oleh " << info(currentBuku).penulis
             << " memiliki " << count << " relasi." << endl;

        currentBuku = next(currentBuku);
    }
};

void hitungRelationYangDimilikiPeminjam(ListPeminjam LP ,ListBuku LB,  string IDPeminjamTarget){
/* IS: List peminjam berisi satu atau lebih elemen, dengan relation ke buku.
   PROSES: Hitung jumlah relation yang dimiliki oleh peminjam tertentu.
   FS: Jumlah relation untuk peminjam target berhasil dihitung.
   PIC: Sofwan
*/
    adrPeminjam P = first(LP);
    bool found = false;

    while (P != NULL && !found) {
        if (info(P).IDPeminjam == IDPeminjamTarget) {
            found = true;
        } else {
            P = next(P);
        }
    }

    if (found) {
        int count = 0;

        adrBuku bukuSaatIni = first(LB);
        while (bukuSaatIni != NULL) {
            adrRelation R = relation_first(bukuSaatIni);

            while (R != NULL) {
                if (nextPeminjam(R) == P) {
                    count++;
                }
                R = nextRelation(R);
            }

            bukuSaatIni = next(bukuSaatIni);
        }

        cout << "Peminjam dengan ID " << IDPeminjamTarget
             << " memiliki " << count << " relasi." << endl;
    } else {
        cout << "Peminjam dengan ID " << IDPeminjamTarget
             << " tidak ditemukan di dalam daftar." << endl;
    }
};

void hitungPeminjamYangTidakBerrelasi(ListPeminjam LP, ListBuku LB){
/* IS: List peminjam berisi elemen, baik yang memiliki relation maupun tidak.
   PROSES: Hitung jumlah peminjam yang tidak memiliki relation dengan buku mana pun.
   FS: Jumlah peminjam yang tidak berrelation berhasil dihitung.
   PIC: Sofwan
*/
    adrPeminjam P = first(LP);
    int count = 0;
    while (P != NULL) {
        bool Rel = false;
        adrBuku B = first(LB);
        while (B != NULL && !Rel) {
            adrRelation R = relation_first(B);

            while (R != NULL) {
                if (nextPeminjam(R) == P) {
                    Rel = true;
                    break;
                }
                R = nextRelation(R);
            }
            B = next(B);
        }

        if (!Rel) {
            count++;
        }
        P = next(P);
    }
    cout << "Jumlah peminjam yang tidak memiliki relasi: " << count << endl;
};

void editRelasiDariParent(ListBuku &LB, ListPeminjam &LP, string kodeBuku, string idPeminjamBaru) {
    adrBuku B = first(LB);
    while (B != NULL && info(B).KodeBuku != kodeBuku) {
        B = next(B);
    }
    // Jika buku ditemukan
    if (B != NULL) {
        adrPeminjam P = first(LP);
        while (P != NULL && info(P).IDPeminjam != idPeminjamBaru) {
            P = next(P);
        }
        // Jika peminjam baru ditemukan
        if (P != NULL) {
            adrRelation R = relation_first(B);
            while (R != NULL) {
                nextPeminjam(R) = P;

                R = nextRelation(R);
            }
        } else {
            cout << "Peminjam baru tidak ditemukan." << endl;
        }
    } else {
        cout << "Buku tidak ditemukan." << endl;
    }
};
