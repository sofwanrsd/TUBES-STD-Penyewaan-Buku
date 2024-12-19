#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;


/*
APLIKASI INI DIBUAT UNTUK MEMENUHI TUGAS BESAR STRUKTUR DATA!
DIBUAT OLEH :
SOFWAN ROSIDI 103032330045 IT4702
AHMAD FAIZAL HANIF 103032330105 IT4702

PEMBAGIAN TUGAS :
LIST PARENT/BUKU (AHMAD FAIZAL HANIF)
LIST CHILD (SOFWAN ROSIDI)
RELATION (BARENGAN / DIBAGI 2)

INFO DARI DOSEN :
- TIDAK BOLEH MENGGUNAKAN BREAK PADA LOOPING
*/

// Define
#define next(P) P->next
#define info(P) P->info
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define relation(P) P->relation
#define nextPeminjam(P) P->nextPeminjam
#define relation_first(P) ((P)->relation.first)
#define nextRelation(P) P->nextRelation

//ADT
typedef struct elmBuku* adrBuku;
struct buku {
    string KodeBuku;
    string penulis;
    string judul;
    string status;
};

typedef struct elmPeminjam* adrPeminjam;
struct peminjam {
    string IDPeminjam;
    string nama;
    string TanggalPinjam;
    string TanggalKembali;
};

typedef struct elmRelation* adrRelation;

typedef buku infotype_buku;
typedef peminjam infotype_peminjam;


struct ListBuku{
    adrBuku first;
};

struct ListRelation {
    adrRelation first;
};

struct ListPeminjam{
    adrPeminjam first;
    adrPeminjam last;
};

struct elmRelation{
    adrRelation nextRelation;
    adrPeminjam nextPeminjam;
};

struct elmBuku {
    infotype_buku info;
    adrBuku next;
    ListRelation relation;
};

struct elmPeminjam {
    infotype_peminjam info;
    adrPeminjam next;
    adrPeminjam prev;
};


// DEKLARASI FUNGSI
void createListBuku(ListBuku &LB);
void createListPeminjam(ListPeminjam &LP);
void createListRelation(ListRelation &LR);

adrBuku createNewElemenBuku(infotype_buku X);
adrPeminjam createNewElemenPeminjam(infotype_peminjam X);
adrRelation createNewElemenRelation(adrPeminjam P);

void InsertBuku_first(ListBuku &LB, adrBuku B);
void InsertBuku_last(ListBuku &LB, adrBuku B);
void InsertBuku_after(ListBuku &LB, adrBuku B, adrBuku prec);

void InsertPeminjam_first(ListPeminjam &L, adrPeminjam P);
void InsertPeminjam_last(ListPeminjam &L, adrPeminjam P);
void InsertPeminjam_after(ListPeminjam &L, adrPeminjam P, adrPeminjam prec);

void InsertRelation_first(ListBuku &L, adrBuku B, adrRelation R);
void InsertRelation_last(ListBuku &L, adrBuku B, adrRelation R);
void InsertRelation_after(ListBuku &L, adrBuku B, adrRelation R, adrRelation prec);

void DeleteBuku_first(ListBuku &L, adrBuku &B);
void DeleteBuku_last(ListBuku &L, adrBuku &B);
void DeleteBuku_after(ListBuku &L, adrBuku &B, adrBuku prec);

void DeletePeminjam_first(ListPeminjam &LP, ListBuku &LB, adrPeminjam &P);
void DeletePeminjam_last(ListPeminjam &L,ListBuku LB, adrPeminjam &P);
void DeletePeminjam_after(ListPeminjam &L,ListBuku LB, adrPeminjam &P, adrPeminjam prec);

void DeleteRelation_first(ListRelation &L, adrRelation &R);
void DeleteRelation_last(ListRelation &L, adrRelation &R);
void DeleteRelation_after(ListRelation &L, adrRelation &R, adrRelation prec);

void findBuku(ListBuku L, string penulis, string judul);
void findPeminjam(ListPeminjam L, string IDPeminjam);
void findRelation_BukudanPeminjam(ListBuku L, adrBuku B, adrPeminjam P);

void showAllBuku(ListBuku L);
void showAllPeminjam(ListPeminjam L);
void ShowDataPeminjam_DariBuku(ListBuku L, string judul, string penulis);
void showDataBukuBesertaPeminjamnya(ListBuku L);
void showDataPeminjamBesertaBukuYangDiPinjam(ListPeminjam &LP, ListBuku &LB);
void showDataBukuDariListPeminjam(ListPeminjam &LP, ListBuku &LB, string IDPeminjam);

void hitungRelationDariSetiapBuku(ListBuku L);
void hitungRelationYangDimilikiPeminjam(ListPeminjam L,ListBuku LB, string IDPeminjamTarget);
void hitungPeminjamYangTidakBerrelasi(ListPeminjam LP, ListBuku LB);
void editRelasiDariParent(ListBuku &LB, ListPeminjam &LP, string kodeBuku, string idPeminjamBaru);

#endif // TUBES_H_INCLUDED
