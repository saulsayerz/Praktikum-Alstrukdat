//Nama   : Saul Sayers
//NIM    : 13520094
//Kelas  : K02
//Praktikum 4 

#include <stdio.h>
#include "listdinpos.h"
#include <stdlib.h>

void CreateListDin(ListDin *l, int capacity){
    int i;
    BUFFER(*l) = (ElType*) malloc (capacity * sizeof(ElType));
    for (i = 0; i < capacity ; i++) {
        ELMT(*l, i) = VAL_UNDEF;
    CAPACITY(*l) = capacity;
    }
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity + 1 */
/* Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF */

void dealocate(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. TI(l) dikembalikan ke system, CAPACITY(l)=0; nEff(l)=0 */

int length(ListDin l){
    int panjang;
    panjang = 0;
    while (panjang < CAPACITY(l) && ELMT(l, panjang)!= VAL_UNDEF) {
            panjang += 1;
    }
    return panjang;
}

IdxType getLastIdx(ListDin l){
    return (length(l) - 1);
}

boolean isIdxValid(ListDin l, IdxType i){
    return ((i>=0) && (i<CAPACITY(l)));
}

boolean isIdxEff(ListDin l, IdxType i){
    return ((i>=0) && (i<length(l)));
}

boolean isEmpty(ListDin l){
    return (length(l) == 0);
}

boolean isFull(ListDin l){
    return (length(l) == CAPACITY(l));
}

void readList(ListDin *l){
    int N,i ;
    do {
        scanf("%d", &N) ;
    } while ((N < 0 ) || (N > CAPACITY(*l)));
    for (i=0; i<N ; i++) {
        scanf("%d", &ELMT(*l, i)) ;
    }
}

void displayList(ListDin l) {
    int i;
    printf("[");
	for (i = 0; isIdxEff(l,i) ; i++) {
		if (i != 0) {
			printf(",");
		}
		printf("%d", ELMT(l,i));
	}
	printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    ListDin total;
    int i;
    CreateListDin(&total,CAPACITY(l1));
    for (i=0;(i<length(l1));i++){
		if (plus){
			ELMT(total,i) = ELMT(l1,i) + ELMT(l2,i);
		}
		else{
			ELMT(total,i) = ELMT(l1,i) - ELMT(l2,i);
		}
	}
    return total;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    int i = 0; 
    boolean sama = true;
    if (length(l1) != length(l2)){
        sama = false;
    }
    else{
        while ((i<length(l1)) && (sama)) {
            if (ELMT(l1,i) != ELMT(l2,i)) {
                sama = false;
            }
            i++ ;
        }
    }
    return sama;
}

IdxType indexOf(ListDin l, ElType val){
    int indeks = IDX_UNDEF;
    int i = 0 ;
    boolean ketemu=false ;
    while ((i<length(l)) && !(ketemu)) {
        if (ELMT(l,i) == val) {
            ketemu = true ;
            indeks = i ;
        }
        i++ ;
    }
    return indeks;
}

void extremes(ListDin l, ElType *max, ElType *min){
    *min = ELMT(l, 0);
    *max = ELMT(l, 0);
    int i;
    for (i=1;isIdxEff(l,i);i++){
        if (ELMT(l,i) > *max) {
            *max = ELMT(l,i);
        }
        if (ELMT(l,i) < *min) {
            *min = ELMT(l,i);
        }
    }
}    

void copyList(ListDin lIn, ListDin *lOut) {
    int i;
    CreateListDin(lOut, CAPACITY(lIn));
    for (i = 0; i < CAPACITY(lIn); i++) {
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
}

ElType sumList(ListDin l){
    int total = 0;
    int i = 0;
    while (isIdxEff(l,i)) {
        total += ELMT(l,i);
        i++;
    }
    return total ;
}

int countVal(ListDin l, ElType val){
    int banyak = 0;
    int i ;
    for (i = 0; isIdxEff(l,i); i ++) {
        if (ELMT(l,i) == val) {
            banyak++ ;
        }
    }
    return banyak;
}

boolean isAllEven(ListDin l) {
    boolean genap = true ;
    int i = 0 ;
    while ((isIdxEff(l,i)) && (genap)) {
        if ((ELMT(l,i) % 2) != 0) {
            genap = false;
        }
        i++ ;
    }
    return genap ;
}

void sort(ListDin *l, boolean asc) {
    int i, j, temp;
    for (i = 0; i < length(*l)-1; i++){
        for (j = 0; j < length(*l)-i-1; j++){
            if (asc) {
                if (ELMT(*l,j) > ELMT(*l,j+1)){
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }
            else {
                if (ELMT(*l,j) < ELMT(*l,j+1)){
                    temp = ELMT(*l,j) ;
                    ELMT(*l,j) = ELMT(*l,j+1);
                    ELMT(*l,j+1) = temp;
                }
            }
        }
    }
}

void insertLast(ListDin *l, ElType val) {
    ELMT(*l,length(*l)) = val;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, length(*l)-1);
    ELMT(*l, length(*l)-1) = VAL_UNDEF;
}

void growList(ListDin *l, int num) {
    ListDin sementara;
    int capacitybaru = CAPACITY(*l) + num ;
    copyList(*l, &sementara) ;
    CAPACITY(sementara) = capacitybaru;
    dealocate(l);
    copyList(sementara, l);
}

void shrinkList(ListDin *l, int num) {
    ListDin sementara;
    int capacitybaru = CAPACITY(*l) - num ;
    copyList(*l, &sementara) ;
    CAPACITY(sementara) = capacitybaru;
    dealocate(l);
    copyList(sementara, l);
}

void compactList(ListDin *l) {
    ListDin sementara;
    int capacitybaru = length(*l) ;
    copyList(*l, &sementara) ;
    CAPACITY(sementara) = capacitybaru;
    dealocate(l);
    copyList(sementara, l);
}