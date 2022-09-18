/* Program   : matriks.c */
/* Deskripsi : realisasi body file modul ADT Matriks */
/* NIM/Nama  : 24060121140167 / Agung Surya Permana */
/* Tanggal   : 18 September 2022*/
/***********************************/

/*Importing inclue*/
#include <stdio.h>
#include <stdbool.h>
#include "matriks.h"
/*importing end*/

/*KONSTRUKTOR*/
/* procedure makeMatriks(output M:Matriks)*/
/* {I.S: -} */
/* {F.S: M terdefinisi, M.nbbar=0, M.nbkol=0 } */
/* {Proses: menginisialisasi semua cell matriks M dengan -999 } */
/*makeMatrix Start*/
void makeMatriks(Matriks *M){
	(*M).nbbar = 0;
	M->nbkol = 0;
	for (int i = 0; i < 10; i++)
	{
		for(int j=0;j<10;j++){
			(*M).wadah[i][j] = -999;
		}
	}
}
/*makeMatrix End*/

/***SELEKTOR***/
/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
/*getNbbar Start*/
int getNbbar(Matriks M){
	return M.nbbar;
}
/*getNbbar End*/

/*function getNbbar(M:Matriks)->integer*/
/*{mengembalikan nilai banyak baris matriks M}*/
/*getNbkol Start */
int getNbkol(Matriks M){
	return M.nbkol;
}
/*getNbkol End */

/*function getInfoCell(M:Matriks,X:integer,Y:integer)->integer*/
/*{mengembalikan nilai/isi elemen baris X, kolom Y, matriks M}*/
/*getInfoCell Start */
int getInfoCell(Matriks M, int X, int Y){
	return M.wadah[X][Y];
}
/*getInfoCell End */

/***MUTATOR***/
/*procedure setNbbar(input/output M:Matriks, input X:integer)*/
/*{I.S.: M,X terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak baris efektif dengan X}*/
/*setNbbar Start */
void setNbbar(Matriks *M, int X){
	M->nbbar = X;
}
/*setNbbar End */

/*procedure setNbkol(input/output M:Matriks, input Y:integer)*/
/*{I.S.: M,Y terdefinisi}*/
/*{F.S.: -}*/
/*{proses: mengisi banyak kolom efektif dengan Y}*/
/*setNbkol Start */
void setNbkol(Matriks *M, int Y){
	M->nbkol = Y;
}
/* setNbkol End */

/*procedure setInfoCell(input/output M:Matriks,
  input X:integer, input Y:integer, input C:integer)*/
/*{I.S.: M,X,Y,C terdefinisi, C=nilai/info pengganti}*/
/*{F.S.: cell (X,Y) berisi C }*/
/*{proses: mengisi cell pada baris X, kolom Y dengan C }*/
/*setInfoCell Start */
void setInfoCell(Matriks *M, int X, int Y, int C){
	M->wadah[X][Y] = C;
}
/*setInfoCell End */

/***PREDIKAT***/
/*function isEmptyMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M kosong}*/
/*isEmptyMatriks Start */
bool isEmptyMatriks(Matriks M){
	return M.nbbar == 0 || M.nbkol == 0;
}
/*isEmptyMatriks*/

/*function isFullMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M penuh}*/
/*isFullMatriks Start*/
bool isFullMatriks(Matriks M){
	return M.nbbar == 10 && M.nbkol == 10;
}
/*isFullMatriks End */

/***SUBRUTIN LAIN***/
/*procedure printMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks ke layar, termasuk sel kosong}*/
/*printMatriks Start */
void printMatriks(Matriks M)
{
	for (int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++){
			printf("%d ",(M).wadah[i][j]);
		}
		printf("\n");
	}
}
/*printMatriks End */

/*procedure viewMatriks(input M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{Proses: mencetak info cell matriks yang tidak kosong ke layar}*/
/*viewMatriks Start*/
void viewMatriks(Matriks M)
{
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				printf("%d ",(M).wadah[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Matriks Kosong!\n");
	}
}
/*viewMatriks End*/

/*function sumCellMatriks(M:Matriks)->integer*/
/*{mengembalikan jumlah nilai elemen matriks M}*/
/* sumCellMatriks Start */
int sumCellMatriks(Matriks M){
	int sum;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar ; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				sum += M.wadah[i][j];
			}
		}
	}
	return sum;
}
/* sumCellMatriks End */

/*function avgCellMatriks(M:Matriks)->real*/
/*{mengembalikan rataan nilai elemen matriks M}*/
/* avgCellMatriks Start*/
float avgCellMatriks(Matriks M){
	return (!isEmptyMatriks(M)?sumCellMatriks(M)/(M.nbbar*M.nbkol) : '\0');
}
/* avgCellMatriks End */

/*function maxCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terbesar elemen matriks M}*/
/* maxCellMatriks */
int maxCellMatriks(Matriks M){
	int max = M.wadah[0][0];
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(max<M.wadah[i][j]){
					max = M.wadah[i][j];
				}
			}
		}
	}
	return max;
}
/* maxCellMatriks End */

/*function minCellMatriks(M:Matriks)->integer*/
/*{mengembalikan nilai terkecil elemen matriks M}*/
/*minCellMatriks Start */
int minCellMatriks(Matriks M){
	int min = M.wadah[0][0];
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(min>M.wadah[i][j]){
					min = M.wadah[i][j];
				}
			}
		}
	}
	return min;
}
/*minCellMatriks End */

/*function countA(M:Matriks,A:integer)->integer*/
/*{mengembalikan banyak elemen bernilai A dalam matriks M}*/
/* countA Start */
int countA(Matriks M, int A){
	int count;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(M.wadah[i][j]==A){
					count++;
				}
			}
		}
	}
	return count;
}
/* countA End */

/*procedure searchMatriks(input M:Matriks, input A:integer,
output X:integer, output Y:integer)*/
/*{I.S.: M,A terdefinisi, A=nilai/info cell yang dicari}*/
/*{F.S.: X=indeks baris, Y=indeks kolom, tempat ditemukannya A}*/
/*{proses: mencari nilai A dalam cell matriks M}*/
/*{bila tidak ketemu, X=Y=-999}*/
/* searchMatriks Start */
void searchMatriks(Matriks M, int A){
	int X=-999;
	int Y=-999;
	if(!isEmptyMatriks(M)){
		for (int i = 0; i < M.nbbar; i++)
		{
			for(int j = 0; j < M.nbkol; j++){
				if(M.wadah[i][j]==A){
					X=i+1;
					Y=j+1;
				}
			}
		}

	}
	printf("Nilai %d ada di baris ke- %d kolom ke- %d\n",A,X,Y);
}
/* searchMatriks End */

/*procedure transpose(input/output M:Matriks)*/
/*{I.S.: M terdefinisi}*/
/*{F.S.: }*/
/*{proses: mengubah susunan cell matriks,
baris menjadi kolom dan sebaliknya}*/
/*{misal: M=[1,2] menjadi [1,4]
____________[4,5]         [2,5] }*/
/*transpose Start */
void transpose(Matriks *M){
	if(!isEmptyMatriks(*M)){
		for( int i = 0; i < M->nbbar; i++)
		{
			for ( int j = i+1; j < M->nbkol; j++ )
			{
				int buffer = M->wadah[i][j];
				M->wadah[i][j] = M->wadah[j][i];
				M->wadah[j][i] = buffer;
			}
		}
		int buffer = M->nbbar;
		M->nbbar = M->nbkol;
		M->nbkol = buffer;
	}
}
/* transpose End */

/*procedure setMatriks(input/output M:Matriks,
  input X:integer, input Y:integer)*/
/*{I.S.: M,X,Y, terdefinisi}*/
/*{F.S.: M terdefinisi, M.nbbar=X, M.nbkol=Y }*/
/*{proses: membuat matriks dengan baris dan kolom efektif yang diinputkan }*/
/* setMatriks Start */
void setMatriks(Matriks *M, int X, int Y){
	int valBar, valKol;
	for (int i = 0; i < X; i++)
	{
		for(int j=0;j<Y;j++){
			printf("Matriks [%d][%d] : ",i,j);
			scanf("%d",&M->wadah[i][j]);
		}
	}
}
/* setMatriks End */

/*******TUGAS*******/
/* No 1 */
/*function MulMatriks(M1:Matriks,M2:Matriks)->Matriks*/
/*{proses: Mengirim hasil perkalian matriks: salinan M1 * M2 }*/
Matriks MulMatriks (Matriks M1, Matriks M2){
    /* Kamus Lokal*/
    Matriks kali;
    int dlm;
    int i;
    int j;
    int k;

    /*Algoritma*/
    makeMatriks(&kali);
    if( getNbkol(M1) != getNbkol(M2)){
        printf("Panjang kolom M1 tidak sama dengan Baris M2\n");
    } else {
        setNbbar(&kali, getNbbar(M1));
        setNbkol(&kali, getNbkol(M2));
        for( i = 0; i < getNbbar(kali); i++){
            for( j = 0; j < getNbkol(M2); j++){
                dlm = 0;
                for( k = 0; k < getNbkol(M1); k++)
                    dlm += getInfoCell(M1, i, k) * getInfoCell(M2, k, j);
                setInfoCell(&kali, i, j, dlm);
            }
        }
    }

    return kali;
}

/*function isEqualMatriks(input M1:Matriks,M2:Matriks)->boolean*/
/*{proses: Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 }*/
bool isEqualMatriks (Matriks M1, Matriks M2){
    /*Kamus Lokal*/


    /*Algoritma*/
    return getNbbar(M1) == getNbbar(M2) && getNbkol(M1) == getNbkol(M2);
}

/*function IsSquareMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks dg ukuran baris dan kolom sama}*/
bool IsSquareMatriks (Matriks M){
    /*Kamus Lokal*/


    /*Algoritma*/
    return getNbbar(M) == getNbkol(M);
}

/*function DeterminanMatriks(M:Matriks)->float*/
/*{proses: Menghitung nilai determinan M}*/
float DeterminanMatriks (Matriks M){
    /*Kamus Lokal*/
    int i;
    int j;
    int k;
    int lompat;
    float total;
    int kofaktor;
    Matriks MN;

    /*Algoritma*/
    if(!IsSquareMatriks(M))
        printf("Bukan matriks persegi\n");
    else{
        if( getNbbar(M) == 1) return getInfoCell(M, 0, 0);
        total = 0;
        for( i = 0; i < getNbbar(M); i++){
            makeMatriks(&MN);
            setNbbar(&MN, getNbbar(M) - 1);
            setNbkol(&MN, getNbkol(M) - 1);
            lompat = 0;
            for( j = 0; j < getNbbar(M); j++){
                if( j == i) lompat++;
                else
                    for( k = 0; k < getNbkol(M); k++)
                        setInfoCell(&MN, k, j - lompat, getInfoCell(M, k + 1, j));
            }
            /*kofaktor*/
            kofaktor  = getInfoCell(M, 0, i);
            kofaktor *= (i%2) ? -1 : 1;
            total += kofaktor * DeterminanMatriks(MN);
        }
        return total;
    }

}

/*function IsSatuanMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks satuan
dg setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0}*/
bool IsSatuanMatriks (Matriks M){
    /*Kamus Lokal*/
    bool stuan;
    int i;
    int j;
    int ordo;

    /*Algoritma*/
    stuan = true;
    if(!IsSquareMatriks(M)){
        printf("Bukan matriks persegi\n");
        stuan = false;
    }else {
        ordo = getNbbar(M);
        for( i = 0; i < ordo; i++){
            for( j = 0; j < ordo; j++){
                if((i == j) || (i == ordo - j - 1) || (j == ordo - i - 1)){
                    stuan &= getInfoCell(M, i, j) == 1;
                } else {
                    stuan &= getInfoCell(M, i, j) == 0;
                }
            }
            printf("\n");
        }
    }
    return satuan;
}

/*function IsSparseMatriks(M:Matriks)->boolean*/
/*{mengembalikan true jika matriks M adalah matriks sparse: matriks “jarang” dengan definisi:
hanya maksimal 5% dari element matriks yang efektif bukan bernilai kosong(-999)}*/
bool IsSparseMatriks (Matriks M){
    /*Kamus Lokal*/

    /*Algoritma*/
    return isEmptyMatriks ? 0 : countA(M, 0) / (float)(getNbbar(M) * getNbkol(M)) < 0.05;
}











