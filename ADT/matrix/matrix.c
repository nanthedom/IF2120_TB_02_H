#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (i >= 0) && (i < ROWM_CAP) && (j >= 0) && (j < COLM_CAP);
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m)-1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m)-1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return (i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMTMAT(m,i,i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    int i,j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for(i = 0; i <= getLastIdxRow(mIn); i++){
        for(j = 0; j <= getLastIdxCol(mIn); j++){
            ELMTMAT(*mOut,i,j) = ELMTMAT(mIn,i,j);
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    if(isMatrixIdxValid(nRow,nCol)){
        int i, j;
        createMatrix(nRow,nCol,m);
        for(i = 0; i <= getLastIdxRow(*m); i++){
            for(j = 0; j <= getLastIdxCol(*m); j++){
                scanf("%d", &ELMTMAT(*m,i,j));
            }
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i, j;
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            printf("%d", ELMTMAT(m,i,j));
            if(j < getLastIdxCol(m)){
                printf(" ");
            }
        }
        printf("\n");
        // if(i < getLastIdxRow(m)){
        //     printf("\n");
        // }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    int i,j;
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m1); j++){
            ELMTMAT(m3,i,j) = ELMTMAT(m1,i,j) + ELMTMAT(m2,i,j);
        }
    }
    return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    int i,j;
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m1); j++){
            ELMTMAT(m3,i,j) = ELMTMAT(m1,i,j) - ELMTMAT(m2,i,j);
        }
    }
    return m3;   
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    int i,j,k;
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m2),&m3);
    for(i = 0; i <= getLastIdxRow(m1); i++){
        for(j = 0; j <= getLastIdxCol(m2); j++){
            ELMTMAT(m3,i,j) = 0;
            for(k = 0; k <= getLastIdxCol(m1); k++){
                ELMTMAT(m3,i,j) += ELMTMAT(m1,i,k)*ELMTMAT(m2,k,j); 
            }
        }
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix m3; int i, j;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    m3 = multiplyMatrix(m1,m2);
    for(i = 0; i <= getLastIdxRow(m3); i++){
        for(j = 0; j <= getLastIdxCol(m3); j++){
            ELMTMAT(m3,i,j) %= mod;
        }
    }
    return m3;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
Matrix multiplyByConst(Matrix m, ElType x){
    int i, j;
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            ELMTMAT(m,i,j) *= x;
        }
    }
    return m;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    int i, j;
    for(i = 0; i <= getLastIdxRow(*m); i++){
        for(j = 0; j <= getLastIdxCol(*m); j++){
            ELMTMAT(*m,i,j) *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2)){
        int  i, j; boolean check;
        check = true;
        for(i = 0; i <= getLastIdxRow(m1); i++){
            for(j = 0; j <= getLastIdxCol(m1); j++){
                if(ELMTMAT(m1,i,j) != ELMTMAT(m2,i,j)){
                    check = false;
                    break;
                }
            }
        }
        return check;
    }
    return false;

}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !(isMatrixEqual(m1,m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return ROW_EFF(m)*COL_EFF(m);
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m){
    if(isSquare(m)){
        boolean sym; int i,j;
        sym = true;
        for (i = 0; i < ROW_EFF(m); i++){
            for (j = 0; j < i; j++){
                if(ELMTMAT(m,i,j) != ELMTMAT(m,j,i)){
                    sym = false;
                    break;
               }    
            }
        }
        return sym;
    }
    return false;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m){
    if(isSquare(m)){
        boolean check; int i,j;
        check = true;
        for(i = 0; i <= getLastIdxRow(m); i++){
            for(j = 0; j <= getLastIdxCol(m); j++){
                if(i != j && ELMTMAT(m,i,j) != 0){
                    check = false;
                    break;
                }
                if (i == j && ELMTMAT(m,i,j) != 1){
                    check = false;
                    break;
                }
            }
        }
        return check;
    }
    return false;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m){
    int i, j;
    float countNotZero = 0;
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            if(ELMTMAT(m,i,j) != 0){
                countNotZero++;
            }
        }
    }
    return (countNotZero <= countElmt(m)*0.05);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    return multiplyByConst(m,-1);
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    pMultiplyByConst(m,-1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

Matrix minor(Matrix m, int i, int j){
    /*Mengembalikan minor dari elemen matriks ke-ij*/
    Matrix minor; int a,b,c,d;
    c = 0; 
    createMatrix(ROW_EFF(m)-1, COL_EFF(m)-1, &minor);
    for(a = 0; a <= getLastIdxRow(m); a++){
        d = 0;
        for(b = 0; b <= getLastIdxCol(m); b++){
            if(b != j && a != i){
                ELMTMAT(minor,c,d) = ELMTMAT(m,a,b);
                d++;
            }
        }
        if(a != i){
            c++;
        }
    }
    return minor;
}

float determinant(Matrix m){
    int i,sign; float det;
    det = 0; sign = 1;
    if(ROW_EFF(m) == 1 && COL_EFF(m) == 1){
        det = (float) ELMTMAT(m,0,0);
    } else {
        for(i = 0; i <= getLastIdxRow(m); i++){
            det += sign*ELMTMAT(m,i,0)*determinant(minor(m,i,0));
            sign *= -1;
        }
    }
    return det;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    int i,j ; Matrix M;
    createMatrix(ROW_EFF(m), COL_EFF(m), &M);
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            ELMTMAT(M,i,j) = ELMTMAT(m,j,i);
        }
    }
    return M;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    int i, j, temp;
    for(i = 0; i <= getLastIdxRow(*m); i++){
        for(j = 0; j < i; j++){
            temp = ELMTMAT(*m,i,j);
            ELMTMAT(*m,i,j) = ELMTMAT(*m,j,i);
            ELMTMAT(*m,j,i) = temp;
        }
    }
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

void RotateMat(Matrix *m){
    int i,j,a,b,lastRow;
    i = 0; j = getLastIdxCol(*m);
    while(i < ROW_EFF(*m)/2 && j < COL_EFF(*m)/2){
        lastRow = ELMTMAT(*m,i,COL_EFF(*m)-1);
        for(b = COL_EFF(*m); b > 0 ; b--){
            ELMTMAT(*m,i,b)  = ELMTMAT(*m,i,b-1);
        }
        ELMTMAT(*m,i,j) = lastRow;
        for(a = getLastIdxRow(*m); a > 0; a--){
            ELMTMAT(*m,a,j) = ELMTMAT(*m,a-1,j);
        }
    }
}


/*
a b c    d a b
d e f    g e c
g h i    h i f
*/
