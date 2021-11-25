//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRA-PRAKTIKUM 2

#include <stdio.h>
#include "point.h"
#include "point.c"

int main(){
    POINT A,B; // INI ADALAH TITIKNYA
    float x,y; // INI ADALAH KOMPONEN DARI TITIKNYA
    printf("MENGISI TITIK A: ");
    BacaPOINT(&A);
    TulisPOINT(A);
    printf("\nMENGISI TITIK B: ");
    BacaPOINT(&B);
    TulisPOINT(B);
    printf("\nUJICOBA FUNGSI IsOrigin");
    printf("\n %d",IsOrigin(A));
    printf("\nUJICOBA FUNGSI IsOnSbX");
    printf("\n %d",IsOnSbX(A));
    printf("\nUJICOBA FUNGSI IsOnSbY");
    printf("\n %d",IsOnSbY(A));
    TulisPOINT(NextX(A));
    TulisPOINT(NextY(A));
    TulisPOINT(PlusDelta(A,5,5));
    TulisPOINT(MirrorOf(A, true));
    TulisPOINT(MirrorOf(A, false));
    printf("%f", Jarak0(A));
    printf("%f", Panjang(A, B));
    TulisPOINT(B);
    Geser(&B,5,5);
    TulisPOINT(B);
    GeserKeSbX(&B);
    TulisPOINT(B);
    GeserKeSbY(&B);
    TulisPOINT(B);
    Mirror(&A,true);
    TulisPOINT(A);
    Putar(&A, 90);
    TulisPOINT(A);
    return 0;
}