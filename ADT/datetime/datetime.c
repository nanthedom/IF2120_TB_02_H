#include <stdio.h>
#include "../boolean/boolean.h"
#include "datetime.h"
#include "../time/time.h"
#include <time.h>

int GetMaxDay(int M, int Y)
{
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
    {
        return 31;                
    }
    else if (M == 4 || M == 6 || M == 9 || M == 11)
    {
        return 30;
    }
    else
    {
        if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return ((1 <= D) && (D <= GetMaxDay(M, Y)) && (1 <= M) && (M <= 12) && (1900 <= Y) && (Y <= 2030) && (h >= 0) && (h <= 23) && (m >= 0) && (m <= 59) && (s >= 0) && (s <= 59));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Hour(Time(*D)) = hh;
    Minute(Time(*D)) = mm;
    Second(Time(*D)) = ss;
}

void BacaDATETIME(DATETIME *D)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    CreateDATETIME(D, tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void TulisDATETIME(DATETIME D)
{
    printf("%02d/%02d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

boolean DEQ(DATETIME D1, DATETIME D2)
{
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && Hour(Time(D1)) == Hour(Time(D2)) && Minute(Time(D1)) == Minute(Time(D2)) && Second(Time(D1)) == Second(Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return (Day(D1) != Day(D2) || Month(D1) != Month(D2) || Year(D1) != Year(D2) || Hour(Time(D1)) != Hour(Time(D2)) || Minute(Time(D1)) != Minute(Time(D2)) || Second(Time(D1)) != Second(Time(D2)));
}

boolean DLT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) < Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) < Month(D2))
        {
            return true;
        }
        else if (Month(D1) == Month(D2))
        {
            if (Day(D1) < Day(D2))
            {
                return true;
            }
            else if (Day(D1) == Day(D2))
            {
                if (Hour(Time(D1)) < Hour(Time(D2)))
                {
                    return true;
                }
                else if (Hour(Time(D1)) == Hour(Time(D2)))
                {
                    if (Minute(Time(D1)) < Minute(Time(D2)))
                    {
                        return true;
                    }
                    else if (Minute(Time(D1)) == Minute(Time(D2)))
                    {
                        if (Second(Time(D1)) < Second(Time(D2)))
                        {
                            return true;
                        }
                    } 
                }
            }
        }        
    }
    return false;
}

boolean DGT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) > Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) > Month(D2))
        {
            return true;
        }
        else if (Month(D1) == Month(D2))
        {
            if (Day(D1) > Day(D2))
            {
                return true;
            }
            else if (Day(D1) == Day(D2))
            {
                if (Hour(Time(D1)) > Hour(Time(D2)))
                {
                    return true;
                }
                else if (Hour(Time(D1)) == Hour(Time(D2)))
                {
                    if (Minute(Time(D1)) > Minute(Time(D2)))
                    {
                        return true;
                    }
                    else if (Minute(Time(D1)) == Minute(Time(D2)))
                    {
                        if (Second(Time(D1)) > Second(Time(D2)))
                        {
                            return true;
                        }
                    } 
                }
            }
        }        
    }
    return false;
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    DATETIME Dt;
    long s = TIMEToDetik(Time(D)) + N;
    if (s / 86400 > 0)
    {
        int plusday = s / 86400;
        Day(D) += plusday;
        while (Day(D) > GetMaxDay(Month(D), Year(D)))
        {
            Day(D) -= GetMaxDay(Month(D), Year(D));
            Month(D)++;
            if (Month(D) > 12)
            {
                Month(D) = 1;
                Year(D)++;
            }
        } 
    }
    TIME NewT = DetikToTIME(s % 86400);
    CreateDATETIME(&Dt, Day(D), Month(D), Year(D), Hour(NewT), Minute(NewT), Second(NewT));
    return Dt;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    DATETIME Dt;
    TIME NewT;
    int sisa = N % 86400;
    if (TIMEToDetik(Time(D)) < sisa)
    {
        sisa = 86400 + TIMEToDetik(Time(D)) - sisa;
        Day(D)--;
        if (Day(D) < 1)
        {
            Month(D)--;
            if (Month(D) < 1)
            {
                Month(D) = 12;
                Year(D)--;
            }
            Day(D) = GetMaxDay(Month(D), Year(D));
        }
        NewT = DetikToTIME(sisa);
    }
    else
    {
        sisa = TIMEToDetik(Time(D)) - sisa;
        NewT = DetikToTIME(sisa);
    }
    
    if (N / 86400 > 0)
    {
        int minusday = N / 86400;
        while (minusday > Day(D))
        {
            minusday -= Day(D);
            Month(D)--;
            if (Month(D) < 1)
            {
                Month(D) = 12;
                Year(D)--;
            }
            Day(D) = GetMaxDay(Month(D), Year(D));
        }
        Day(D) -= minusday;
    }
    CreateDATETIME(&Dt, Day(D), Month(D), Year(D), Hour(NewT), Minute(NewT), Second(NewT));
    return Dt;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    int i;
    int d1 = Day(DAw);
    for (i = 1; i < Month(DAw); i++)
    {
        d1 = d1 + GetMaxDay(i, Year(DAw));
    }

    int minusday = 0;
    if (TGT(Time(DAw), Time(DAkh)))
    {
        minusday = -1;
    }

    int d2 = Day(DAkh) + minusday;
    for (i = 1; i < Month(DAkh); i++)
    {
        d2 = d2 + GetMaxDay(i, Year(DAkh));
    }
    
    int selisihd = 0;
    if (Year(DAkh) == Year(DAw))
    {
        selisihd = d2 - d1;
    }
    
    while (Year(DAw) < Year(DAkh))
    {
        if (Year(DAw) % 400 == 0 && Year(DAw) % 4 == 0)
        {
            selisihd = selisihd + 366 - d1 + d2;
        }
        else
        {
            selisihd = selisihd + 365 - d1 + d2;
        }
        d2 = 0;
        d1 = 0;
        Year(DAw)++;
    }
    long int duration = 86400 * selisihd + Durasi(Time(DAw), Time(DAkh));
    return duration;
}
