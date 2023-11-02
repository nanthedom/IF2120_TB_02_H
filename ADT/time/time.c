/* File: time.c */

#include <stdio.h>
#include "time.h"
#include <math.h>
#include <time.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M, int S)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59)); 
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int HH, int MM, int SS)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    /*KAMUS*/
    /*ALGORITMA*/
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid dari localtime */
{
    /*ALGORITMA*/
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    CreateTime(T, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
   
void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen T ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    /*KAMUS*/
    /*ALGORITMA*/
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    /*KAMUS*/ 
    /*ALGORITMA*/
    return (3600*Hour(T) + 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    /*KAMUS*/
    long N1;
    TIME T;
    /*ALGORITMA*/
    N1 = N % 86400;
    CreateTime (&T, (N1 / 3600), ((N1 % 3600) / 60), (N1 % 60));
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}
boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (TIMEToDetik(T1) != TIMEToDetik(T2));
}
boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}
boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (DetikToTIME(TIMEToDetik(T)+1));
}
TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return (DetikToTIME(TIMEToDetik(T)+N));
}
TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    /*KAMUS*/
    /*ALGORITMA*/
    if (TIMEToDetik(T) < 1)
    {
        return (DetikToTIME(86399));
    }
    else
    {
        return (DetikToTIME(TIMEToDetik(T)-1));
    }
}
TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
{
    /*KAMUS*/
    /*ALGORITMA*/
    if (TIMEToDetik(T) < N)
    {
        return (DetikToTIME(86400 + TIMEToDetik(T) - N));
    }
    else
    {
        return (DetikToTIME(TIMEToDetik(T)-N));
    }
}
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    /*KAMUS*/
    /*ALGORITMA*/
    if (TIMEToDetik(TAw) > TIMEToDetik(TAkh))
    {
        return (86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    }
    else
    {
        return (TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    }
}