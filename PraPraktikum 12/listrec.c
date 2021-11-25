// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 12 November 2021
// Topik     : ADT Linked List secara rekursif
// Deskripsi : Implementasi ADT Linked list secara rekursif dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x) 
{
    Address baru = (Address) malloc(sizeof(Node));
    if (baru!=NULL) {
        INFO(baru) = x;
        NEXT(baru) = NULL;
    }
    return baru;
}

boolean isEmpty(List l)
{
    return (l == NULL);
}

int isOneElmt(List l)
{
    boolean bener = 0;
    if (l != NULL)
    {
        if (NEXT(l) == NULL)
        {
            bener = 1;
        }
    }
    return bener ;
}

ElType head(List l)
{
    return INFO(l);
}

List tail(List l)
{
    return NEXT(l);
}

List konso(List l, ElType e)
{
    Address baru ;
    baru = newNode(e);
    if (baru != NULL) {
        NEXT(baru) = l;
        l = baru;
    }
    return l;
}

List konsb(List l, ElType e)
{
    Address alamat, akhir,baru ;
    if (l == NULL) {
        baru = newNode(e);
        if (baru != NULL) {
            NEXT(baru) = l;
            l = baru;
        }
    }
    else {
        alamat = newNode(e) ;
        if (alamat != NULL) {
            akhir = l ;
            while (NEXT(akhir) != NULL ) {
                akhir = NEXT(akhir);
            }
            NEXT(akhir) = alamat;
        }
    }
    return l;
}

int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}