#ifndef   tabel_c
#define   tabel_c
#include <stdio.h>
#include "tabel.h"
#include "boolean.h"

/************************************/
/* Program   : tabel.h */
/* Deskripsi : aplikasi driver modul Tabel */
/* Pembuat   : 24060121140147/Aretha Khansa Maritza*/
/* Tanggal   : Selasa, 13 September 2022 */
/************************************/

/*procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah=-999}
	{Proses: menginisialisasi T} */
void createTable (Tabel *T) {
  /*Kamus lokal*/
  int i;
  // Algoritma
  (*T).size = 0;
  for (i = 1; i < 11; i++) (*T).wadah[i] = -999;
}

/*procedure printTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable (Tabel T) {
  /*Kamus lokal*/
  int i;
  // Algoritma
  printf("[");
  for (i = 1; i < 11; i++) printf(" %d ", T.wadah[i]);
  printf("]\n");
}

/*procedure viewTable ( input T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable (Tabel T){
    /*Kamus lokal*/
    int i;
    //Algoritma
    printf("[");
    for (i = 1; i < 11; i++) if (T.wadah[i] != -999) printf(" %d ", T.wadah[i]);
    printf("]");
}

/*function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize (Tabel T){
    /*Kamus lokal*/

    //Algoritma
    return T.size;
}

/*function countEmpty( T: Tabel) -> integer
	{mengembalikan banyak elemen T yang belum terisi } */
int countEmpty (Tabel T) {
  /*Kamus lokal*/

  // Algoritma
  return 10 - T.size;
}

/*function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable (Tabel T) {
  /*Kamus lokal*/

  // Algoritma
  if (T.size == 0){
      return true;
  }
  else (T.size != 0);{
      return false;
  }
}

/*function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable (Tabel T) {
  /*Kamus lokal*/

  // Algoritma
  if (T.size == 10){
      return true;
  }
  else (T.size != 10);{
      return false;
  }
}

/*procedure populate1 ( input/output T:Tabel, input N: integer )
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate1 (Tabel *T, int N) {
	/*Kamus lokal*/
	int i;

	// Algoritma
	for (int i = 1; i <= N; i++) {
    printf("Masukkan elemen ke-%d: ", i);
    scanf("%d", &(*T).wadah[i]);
        if (((*T).wadah[i])>0){
	           (*T).size++;
        }
        else {
            printf("Masukan angka > 0\n");
            printf("Masukkan elemen ke-%d: ", i);
            scanf("%d", &(*T).wadah[i]);
        }
    }
}

/*procedure searchX1 ( input T:Tabel, input X: integer, output Pos: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai X dalam T.wadah}*/
void searchX1 (Tabel T, int X, int *Pos) {
    /*Kamus lokal*/
    int i;

    // Algoritma
    *Pos = -999;
        for (i = 1; i < 11; i++){
	        if (T.wadah[i] == X){
	        *Pos = i;
	   }
    }
}

/*procedure countX ( input T:Tabel, input X: integer, output Byk: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: Byk berisi banyaknya X di T.wadah, atau 0 jika tidak ketemu }
	{Proses: menghitung elemen bernilai X dalam T.wadah}*/
void countX (Tabel T, int X, int *Byk) {
    /*Kamus lokal*/
    int i, c;
    // Algoritma
    c = 0;
        for (i = 1; i < 11; i++){
	        if (T.wadah[i] == X){
	        c++;
	        *Byk = c;
	    }
    }
}

/*function SumEl ( T:Tabel ) -> integer
	{mengembalikan jumlah semua elemen pengisi T } */
int SumEl(Tabel T) {
    /*Kamus lokal*/
    int i, sum;
    // Algoritma
    sum = 0;
    for (i = 1; i <= T.size; i++){
        sum += T.wadah[i];
    }
    return sum;
}

/*function AverageEl ( T:Tabel ) -> integer
	{mengembalikan nilai rata-rata elemen pengisi T } */
int AverageEl(Tabel T) {
    /*Kamus lokal*/

    // Algoritma
    return SumEl(T)/T.size;
}

/*function getMaxEl (T: Tabel) -> integer
	{mengembalikan nilai elemen terbesar } */
int getMaxEl(Tabel T) {
    /*Kamus lokal*/
    int i, max;

    // Algoritma
    max = T.wadah[1];
    for (i = 2; i <= T.size; i++)
        if (T.wadah[i] > max){
            max = T.wadah[i];
        }
    return max;
}

/*function getMinEl ( T: Tabel) -> integer
	{mengembalikan nilai elemen terkecil } */
int getMinEl (Tabel T) {
    /*Kamus lokal*/
    int i, min;

    // Algoritma
    min = T.wadah[1];
    for (i = 2; i <= T.size; i++){
        if (T.wadah[i] < min)
            min = T.wadah[i];
        }
    return min;
}

/*procedure populate2 ( input/output T:Tabel )
	{I.S.: T terdefinisi}
	{F.S.: T.wadah terisi beberapa elemen positif}
	{Proses: mengisi elemen T.wadah berulang, bila angka
	dari keyboard <=0 maka berhenti, tidak diproses}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populate2(Tabel *T) {
    /*Kamus lokal*/
    int i, iD;

    // Algoritma
    i = 1;
    while ((*T).wadah[i] != -999){
        i++;
    }
    printf("Masukkan elemen ke-%d: ", i);
    scanf("%d", &iD);
    while (iD > 0 && i < 11) {
        (*T).wadah[i] = iD;
        (*T).size++;
        i++;
    printf("Masukkan elemen ke-%d: ", i);
    scanf("%d", &iD);
  }
}

/*procedure addXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi, X terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai X}*/
void addXTable (Tabel *T, int X) {
    /*Kamus lokal*/
    int i;

    // Algoritma
    i = 1;
    for (i = 1; i < 11; i++)
        if ((*T).wadah[i] == -999) {
            (*T).wadah[i] = X;
            (*T).size++;
        return;
    }
}

/*procedure delXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai X, geser semua elemen sisa}*/
void delXTable (Tabel *T, int X) {
    /*Kamus lokal*/
    int i, a;

    // Algoritma
    i = 1;
    while ((*T).wadah[i] != X){
        i++;
  }
    for (a = i; a < (*T).size; a++) {
        (*T).wadah[a] = (*T).wadah[a+1];
  }
  (*T).wadah[(*T).size] = -999;
  (*T).size--;
}

/*procedure delAllXTable ( input/output T:Tabel, input X: integer )
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable (Tabel *T, int X) {
  // Kamus lokal
  int i;
  // Algoritma
    for (i = 1; i < 11; i++){
        if ((*T).wadah[i] == X){
            delXTable(T, X);
        }
    }
}



/*function Modus ( T:Tabel ) -> integer
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama
  [1, 2, 3, 3, 3, 4, 7, 8, 9, 9]*/
int Modus (Tabel T) {
  // Kamus lokal
  int i, a, modus, jum, jumax;
  // Algoritma
  modus = 0;
  jumax = 0;
  for (i = 1; i <= T.size; i++) {
    jum = 0;
    for (a = 1; a <= T.size; a++)
      if (T.wadah[i] == T.wadah[a])
        jum++;

    if (jum > jumax) {
      jumax = jum;
      modus = i;
    }
  }
  return T.wadah[modus];
}

#endif
