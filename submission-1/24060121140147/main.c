/************************************/
/* Program   : maintabel.c */
/* Deskripsi : aplikasi driver modul Tabel */
/* NIM/Nama  : 24060121140147/Aretha Khansa Maritza*/
/* Tanggal   : Selasa,13 September 2022  */
/***********************************/

#include "tabel.h"

int main() {
	// Kamus main
	Tabel T;
	int Pos, Byk;

	// Algoritma
	//1
	createTable(&T);
	//2
	printf("1. Tabel:\n");
	printTable(T);
	//3
	printf("2. Melihat Tabel : \n");
	viewTable(T);
	//4
	printf("\n3. Ukuran Tabel tersebut adalah : %d\n", getSize(T));
	//5
	printf("4. Tempat pada tabel yang belum terisi : %d\n", countEmpty(T));
	//6
	printf("5. Apakah Tabel kosong? : %s \n", isEmptyTable(T) == 1? "TRUE" : "FALSE");
	//7
	printf("6. Apakah Tabel Penuh? : %s \n", isFullTable(T) == 1? "TRUE" : "FALSE");
	//8
	printf("7.");
	populate1(&T, 6);
	printf("##  Tabel Baru :  ##\n");
	printTable(T);
	printf("Maka ukuran Tabel sekarang adalah :  %d\n", getSize(T));
	//9
	searchX1(T, 4, &Pos);
	printf("8. X terdapat dalam elemen ke-%d  \n", Pos);
	//10
	countX(T, 2, &Byk);
	printf("9. Jumlah X pada tabel : %d  \n", Byk);
	//11
	printf("10. Jumlah total seluruh tabel : %d  \n", SumEl(T));
	//12
	printf("11. Rata-rata Tabel : %d  \n", AverageEl(T));
	//13
	printf("12. Nilai MAX : %d  \n", getMaxEl(T));
	//14
	printf("13. Nilai MIN : %d  \n", getMinEl(T));
	//15
	populate2(&T);
	printf("##  Tabel Baru :  ##\n");
	printTable(T);
	//16
	addXTable(&T, 4);
	printf("________________________________\n");
	//17
	delXTable(&T, 2);
	printf("##  Tabel Baru :  ##\n");
	printTable(T);
	//18
	delAllXTable(&T, 2);
	printf("##  Tabel Baru :  ##\n");
	printTable(T);
	//19
	printf("14. Modus : %d\n", Modus(T));
	return 0;
}
