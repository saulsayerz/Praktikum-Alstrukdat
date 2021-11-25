//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRA-PRAKTIKUM 2

#include <stdio.h>
#include "vector.h"
#include "vector.c"

int main(){
    VECTOR A,B; // INI ADALAH vectornya
    float x,y; // INI ADALAH KOMPONEN DARI TITIKNYA
    printf("MENGISI VEKTOR A: ");
    A = MakeVector(6,8) ;
    B = MakeVector(1,2) ;
    TulisVector(A) ;
    printf("\nUJICOBA FUNGSI Magnitude");
    printf("\n %f",Magnitude(A));
    printf("\nUJICOBA FUNGSI Add");
    TulisVector(Add(A,B));
    printf("\nUJICOBA FUNGSI Substract");
    TulisVector(Substract(A,B));
    printf("\nUJICOBA FUNGSI Dot");
    printf("\n %f",Dot(A,B));
    printf("\nUJICOBA FUNGSI Multiply");
    TulisVector(Multiply(A,10));
}