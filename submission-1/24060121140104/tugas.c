/* Program   : tugas.c */
/* Deskripsi : driver file modul ADT Matriks untuk tugas submission 1*/
/* NIM/Nama  : 24060121140104/Divia Shinta Sukarsaatmadja*/
/* Tanggal   : 13 September 2022*/
/***********************************/
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matriks.h"


int main() {
	/*kamus*/
	Matriks A;
	int barisA;
	int kolomA;
	Matriks B;
	Matriks C;
	Matriks D;


	/*algoritma*/
	makeMatriks(&A);
	makeMatriks(&B);
	setMatriks(&A,2,2);
	printf("=============MATRIKS A==============\n");
	viewMatriks(A);
	setMatriks(&B,3,2);
	printf("=============MATRIKS B==============\n");
	viewMatriks(B);
	C = MulMatriks(A, B);
	printf("\n=============MATRIKS C==============\n");
	viewMatriks(C);
	printf("\n");
	printf("Apakah ukuran matriks A sama dengan matriks B? %s\n", isEqualMatriks(A, B)? "true":"false");
	printf("Apakah matriks A termasuk square matriks? %s\n", IsSquareMatriks(A)? "true":"false");
    setMatriks(&D,2,2);
    viewMatriks(D);
    printf("Apakah matriks D termasuk matriks satuan? %s\n", IsSatuanMatriks(D)? "true":"false");
    IsSparseMatriks(A);
    printf("Apakah matriks A merupakan matriks sparse? %s\n", IsSparseMatriks(A)? "true":"false");




	return 0;
}


