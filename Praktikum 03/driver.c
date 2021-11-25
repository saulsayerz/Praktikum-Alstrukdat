#include "listpos.c"

int main () {
    int s  =1;
    int *t ;
    t = &s;
    *t = 2;
    printf("%d",s);
    return 0;
}