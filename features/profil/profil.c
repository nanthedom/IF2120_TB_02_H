#include "profil.h"
#include "../inisialisasi/inisialisasi.h"
#include <stdio.h>
#include "../../ADT/wordmachine/wordmachine.h"
#include "../teman/teman.h"

extern AdjMatrix matrixPertemanan;
extern ListPengguna ListUser;
extern Pengguna *currentUser;

void CreateMatrixFoto(MatrixFoto *M)
{
    Foto F;
    Warna(F) = 'R';
    Karakter(F) = '*';
    int i, j;
    for (i = 0; i < ROW_CAP; i++)
    {
        for (j = 0; j < COL_CAP; j++)
        {
            PIXEL(*M, i, j) = F;
        }
    }
}

void CreateProfil(Profil *P)
{
    Word bio, noHP, weton;
    MatrixFoto M;
    CreateWord(&bio);
    CreateWord(&noHP);
    CreateWord(&weton);
    CreateMatrixFoto(&M);
    Bio(*P) = bio;
    NoHP(*P) = noHP;
    Weton(*P) = weton;
    isPublic(*P) = true;
    Profpic(*P) = M;
}

void CreateProfilFile(Profil *P, Word bio, Word noHP, Word weton, boolean isPub, MatrixFoto M){
    Bio(*P) = bio;
    NoHP(*P) = noHP;
    Weton(*P) = weton;
    isPublic(*P) = isPub;
    Profpic(*P) = M;
}

void ReadBio(Profil *P)
{
    Word bio;
    int MaxChar = 135;
    printf("\nMasukkan Bio Akun:\n");
    ReadWord();
    bio = currentWord;
    while (bio.Length > MaxChar)
    {
        printf("\nBio tidak dapat melebihi 135 karakter\n");
        printf("\nMasukkan Bio Akun:\n");
        ReadWord();
        bio = currentWord;
    }
    if(bio.Length > 0)
        Bio(*P) = bio;
}
boolean isValidNoHP(Word w){
    return (w.Length > 0 && w.Length <= 15 && isNumber(w)) ;
}
void ReadNoHP(Profil *P)
{
    Word noHP;
    printf("\nMasukkan No HP:\n");
    ReadWord();
    noHP = currentWord;
    while (noHP.Length != 0 && !isValidNoHP(noHP))
    {
        printf("\nNo HP tidak valid. Masukkan lagi yuk!\n");
        printf("\nMasukkan No HP:\n");
        ReadWord();
        noHP = currentWord;
    }
    if(noHP.Length > 0)
        NoHP(*P) = noHP;
}

boolean isPahing(Word weton)
{
    if (weton.Length == 6)
    {
        boolean valid = true;
        int i = 0;
        while (valid && i < 6)
        {
            if (i == 0)
            {
                if (weton.TabWord[i] != 'P' && weton.TabWord[i] != 'p')
                {
                    valid = false;
                }
            }
            else if (i == 1)
            {
                if (weton.TabWord[i] != 'A' && weton.TabWord[i] != 'a')
                {
                    valid = false;
                }
            }
            else if (i == 2)
            {
                if (weton.TabWord[i] != 'H' && weton.TabWord[i] != 'h')
                {
                    valid = false;
                }
            }
            else if (i == 3)
            {
                if (weton.TabWord[i] != 'I' && weton.TabWord[i] != 'i')
                {
                    valid = false;
                }
            }
            else if (i == 4)
            {
                if (weton.TabWord[i] != 'N' && weton.TabWord[i] != 'n')
                {
                    valid = false;
                }
            }
            else
            {
                if (weton.TabWord[i] != 'G' && weton.TabWord[i] != 'g')
                {
                    valid = false;
                }
            }
            i++;
        }
        return valid;
    }
    return false;
}
boolean isKliwon(Word weton)
{
    if (weton.Length == 6)
    {
        boolean valid = true;
        int i = 0;
        while (valid && i < 6)
        {
            if (i == 0)
            {
                if (weton.TabWord[i] != 'K' && weton.TabWord[i] != 'k')
                {
                    valid = false;
                }
            }
            else if (i == 1)
            {
                if (weton.TabWord[i] != 'L' && weton.TabWord[i] != 'l')
                {
                    valid = false;
                }
            }
            else if (i == 2)
            {
                if (weton.TabWord[i] != 'I' && weton.TabWord[i] != 'i')
                {
                    valid = false;
                }
            }
            else if (i == 3)
            {
                if (weton.TabWord[i] != 'W' && weton.TabWord[i] != 'w')
                {
                    valid = false;
                }
            }
            else if (i == 4)
            {
                if (weton.TabWord[i] != 'O' && weton.TabWord[i] != 'o')
                {
                    valid = false;
                }
            }
            else
            {
                if (weton.TabWord[i] != 'N' && weton.TabWord[i] != 'n')
                {
                    valid = false;
                }
            }
            i++;
        }
        return valid;
    }
    return false;
}

boolean isWage(Word weton)
{
    if (weton.Length == 4)
    {
        boolean valid = true;
        int i = 0;
        while (valid && i < 4)
        {
            if (i == 0)
            {
                if (weton.TabWord[i] != 'W' && weton.TabWord[i] != 'w')
                {
                    valid = false;
                }
            }
            else if (i == 1)
            {
                if (weton.TabWord[i] != 'A' && weton.TabWord[i] != 'a')
                {
                    valid = false;
                }
            }
            else if (i == 2)
            {
                if (weton.TabWord[i] != 'G' && weton.TabWord[i] != 'g')
                {
                    valid = false;
                }
            }
            else
            {
                if (weton.TabWord[i] != 'E' && weton.TabWord[i] != 'e')
                {
                    valid = false;
                }
            }
            i++;
        }
        return valid;
    }
    return false;
}

boolean isLegi(Word weton)
{
    if (weton.Length == 4)
    {
        boolean valid = true;
        int i = 0;
        while (valid && i < 4)
        {
            if (i == 0)
            {
                if (weton.TabWord[i] != 'L' && weton.TabWord[i] != 'l')
                {
                    valid = false;
                }
            }
            else if (i == 1)
            {
                if (weton.TabWord[i] != 'E' && weton.TabWord[i] != 'e')
                {
                    valid = false;
                }
            }
            else if (i == 2)
            {
                if (weton.TabWord[i] != 'G' && weton.TabWord[i] != 'g')
                {
                    valid = false;
                }
            }
            else
            {
                if (weton.TabWord[i] != 'I' && weton.TabWord[i] != 'i')
                {
                    valid = false;
                }
            }
            i++;
        }
        return valid;
    }
    return false;
}

boolean isPon(Word weton)
{
    if (weton.Length == 3)
    {
        boolean valid = true;
        int i = 0;
        while (valid && i < 3)
        {
            if (i == 0)
            {
                if (weton.TabWord[i] != 'P' && weton.TabWord[i] != 'p')
                {
                    valid = false;
                }
            }
            else if (i == 1)
            {
                if (weton.TabWord[i] != 'O' && weton.TabWord[i] != 'o')
                {
                    valid = false;
                }
            }
            else
            {
                if (weton.TabWord[i] != 'N' && weton.TabWord[i] != 'n')
                {
                    valid = false;
                }
                i++;
            }
        }
        return valid;
    }
    return false;
}

boolean isWetonValid(Word weton)
{
    if (weton.Length > 0)
    {
        return isPahing(weton) | isKliwon(weton) | isPon(weton) | isLegi(weton) | isWage(weton);
    }
    return true;
}

void ReadWeton(Profil *P)
{
    Word weton;
    printf("\nMasukkan weton:\n");
    ReadWord();
    weton = currentWord;
    while (!isWetonValid(weton))
    {
        printf("\nWeton anda tidak valid.\n");
        printf("\nMasukkan weton:\n");
        ReadWord();
        weton = currentWord;
    }
    if(isPahing(weton)){
        strToWord("Pahing", &weton);
    } else if(isPon(weton)){
        strToWord("Pon", &weton);
    } else if (isLegi(weton)){
        strToWord("Legi", &weton);
    } else if (isKliwon(weton)){
        strToWord("Kliwon", &weton);
    } else if (isWage(weton)){
        strToWord("Wage", &weton);
    }
    if(weton.Length > 0)
        Weton(*P) = weton;
}

void ReadFoto(Profil *P)
{
    Word format;
    MatrixFoto M;
    Foto F;
    printf("\nMasukkan foto profil yang baru:\n");
    ReadWord();
    format = currentWord;
    int i = 0, j = 0, k = 0;
    while (i < 5)
    {
        while (j < 5)
        {
            while (format.TabWord[k] == BLANK)
            {
                k++;
            }
            Warna(F) = format.TabWord[k];
            k++;
            while (format.TabWord[k] == BLANK)
            {
                k++;
            }
            Karakter(F) = format.TabWord[k];
            k++;
            PIXEL(M, i, j) = F;
            j++;
        }
        if (i < 4)
        {
            k++; // Remove enter;
        }
        i++;
        j = 0;
    }
    Profpic(*P) = M;
}

MatrixFoto ReadFotoFile(Word w){
    Word format;
    MatrixFoto M;
    Foto F;

    format = w;
    int i = 0, j = 0, k = 0;
    while (i < 5)
    {
        while (j < 5)
        {
            while (format.TabWord[k] == BLANK)
            {
                k++;
            }
            Warna(F) = format.TabWord[k];
            k++;
            while (format.TabWord[k] == BLANK)
            {
                k++;
            }
            Karakter(F) = format.TabWord[k];
            k++;
            PIXEL(M, i, j) = F;
            j++;
        }
        if (i < 4)
        {
            k++; // Remove enter;
        }
        i++;
        j = 0;
    }
    return M;
}

void PrintFoto(Profil P)
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (Warna(PIXEL(Profpic(P), i, j)) == 'R')
            {
                print_red(Karakter(PIXEL(Profpic(P), i, j)));
            }
            if (Warna(PIXEL(Profpic(P), i, j)) == 'G')
            {
                print_green(Karakter(PIXEL(Profpic(P), i, j)));
            }
            if (Warna(PIXEL(Profpic(P), i, j)) == 'B')
            {
                print_blue(Karakter(PIXEL(Profpic(P), i, j)));
            }
        }
        printf("\n");
    }
}

void displayProfil(Pengguna p)
{
    if (isLogin)
    {
        printf("\n");
        printf("| Nama : ");
        printWord(Nama(p));
        printf("\n");
        printf("| Bio akun: ");
        printWord(Bio(Profil(p)));
        printf("\n");
        printf("| No HP: ");
        printWord(NoHP(Profil(p)));
        printf("\n");
        printf("| Weton: ");
        printWord(Weton(Profil(p)));
        printf("\n\n");
    }
}

void GantiProfil()
{
    displayProfil(*currentUser);
    ReadBio(&(Profil(*currentUser)));
    ReadNoHP(&(Profil(*currentUser)));
    ReadWeton(&(Profil(*currentUser)));
    printf("\nProfil Anda sudah berhasil diperbarui!\n\n");
}

void LihatProfil(Word Nama)
{
    int id = indexOf(ListUser, Nama);
    if (id != IDX_UNDEF)
    {
        if (isPublic(Profil(ELMT(ListUser, id))))
        {
            displayProfil(ELMT(ListUser, id));
            printf("\nFoto profil: \n");
            PrintFoto(Profil(ELMT(ListUser, id)));
        }
        else
        {
            if(isKataEqual(Nama,Nama(*currentUser)))
            {
                displayProfil(ELMT(ListUser, id));
                printf("\nFoto profil: \n");
                PrintFoto(Profil(ELMT(ListUser, id)));
            } 
            else if (isFriendsWith(Nama))
            {
                displayProfil(ELMT(ListUser, id));
                printf("\nFoto profil: \n");
                PrintFoto(Profil(ELMT(ListUser, id)));
            } 
            else
            {
                printf("\nWah akun ");
                printWord(Nama);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printWord(Nama);
                printf("!\n\n");
            }
        }
    }
    else
    {
        printf("\nAkun ");
        printWord(Nama);
        printf(" tidak ditemukan\n\n");
    }
}

void AturJenisAkun()
{
    Word confirm, temp;
    if (isPublic(Profil(*currentUser)))
    {
        printf("\nSaat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");
        ReadWord();
        confirm = currentWord;
        strToWord("YA", &temp);
        if (isKataEqual(confirm, temp))
        {
            isPublic(Profil(*currentUser)) = false;
            printf("\nAkun anda sudah diubah menjadi akun Privat.\n\n");
        }
    }
    else
    {
        printf("\nSaat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");
        ReadWord();
        confirm = currentWord;
        strToWord("YA", &temp);
        if (isKataEqual(confirm, temp))
        {
            isPublic(Profil(*currentUser)) = true;
            printf("\nAkun anda sudah diubah menjadi akun Publik.\n\n");
        }
    }
}

void UbahFotoProfil()
{
    printf("\nFoto profil Anda saat ini adalah: \n");
    PrintFoto(Profil(*currentUser));
    ReadFoto(&(Profil(*currentUser)));
    printf("\nFoto profil Anda sudah berhasil diganti!\n\n");
}
