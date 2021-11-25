#include "garis.c"
#include "point.c"

int main(){
    GARIS A,B;
    POINT P,Q ; 
    float x,y,n,m; // INI ADALAH KOMPONEN DARI TITIKNYA
    printf("MENGISI Garis P: ");
    BacaGARIS(&A);
    TulisGARIS(A);
    printf("\nMENGISI Garis B: ");
    BacaGARIS(&B);
    TulisGARIS(B);
    printf("\nUJICOBA FUNGSI PanjangGARIS");
    printf("\n %.2f",PanjangGARIS(A));
    printf("\nUJICOBA FUNGSI GeserGARIS");
    GeserGARIS(&A,10,10);
    TulisGARIS(A) ;
    GeserGARIS(&A,-10,-10);
    printf("\nUJICOBA FUNGSI IsTegakLurus");
    printf("\n %d",IsTegakLurus(A,B));
    printf("\nUJICOBA FUNGSI IsSejajar");
    printf("\n %d",IsSejajar(A,B));
    return 0;
}
