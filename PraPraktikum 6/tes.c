#include <stdio.h>

extern int angka=0;

void kali2(int x){
    x = x*2;
}

void tambah2(int x){
    x = x+2;
}

int main() {
    angka = 1;
    kali2(angka);
    tambah2(angka);
    printf("%d", angka);
    return 0;
}