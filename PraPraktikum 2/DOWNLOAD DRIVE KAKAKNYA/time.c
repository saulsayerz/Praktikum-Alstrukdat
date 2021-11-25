//Nama : Saul Sayers
//NIM  : 13520094 / 16520075
//Kelas: K02
//PRA-PRAKTIKUM 2

#include <stdio.h>
#include "time.h"
#include <math.h>

boolean IsTIMEValid (int H, int M, int S){
    return (0<=H) && (H<24) && (0<=M) && (M<60) && (0<=S) && (S<60);
}

TIME MakeTIME (int HH, int MM, int SS){
    TIME time;
    if (IsTIMEValid(HH,MM,SS)){
        Hour(time)=HH;
        Minute(time)=MM;
        Second(time)=SS;
        return time;
    }
    else {
        printf("Waktu yang diinput tidak valid\n");
    }
}

void BacaTIME (TIME * T){
    boolean benar=false;
    int j,m,d;
    while(benar == false){
        scanf("%d %d %d", &j,&m,&d);
        benar=IsTIMEValid(j,m,d);
    }
    *T=MakeTIME(j,m,d);
}

void TulisTIME (TIME T){
   printf("%2d:%2d:%2d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T){
    return (3600*Hour(T)+ 60*Minute(T) + Second(T));
}

TIME DetikToTIME (long N){
    TIME time ;
    int j,m,d;
    N = N%86400; //mengatasi agar maksimal adalah jam 24 (sehari ada 86400 detik)
    j = N/3600;
    m = (N%3600)/60;
    d = N - 3600*j - 60*m;
    time = MakeTIME(j,m,d);
    return time ;
}

boolean TEQ (TIME T1, TIME T2){
    return (Hour(T1)==Hour(T2)) && (Minute(T1)==Minute(T2)) && (Second(T1)==Second(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return (Hour(T1)!=Hour(T2)) || (Minute(T1)!=Minute(T2)) || (Second(T1)!=Second(T2));
}

boolean TLT (TIME T1, TIME T2){
    return TIMEToDetik(T1)<TIMEToDetik(T2);
}

boolean TGT (TIME T1, TIME T2){
    return TIMEToDetik(T1)>TIMEToDetik(T2);
}

TIME NextDetik (TIME T){
    int detik;
    detik = TIMEToDetik(T);
    detik = detik+1 ;
    T = DetikToTIME(detik);
    return T;
}

TIME NextNDetik (TIME T, int N){
    int detik;
    detik = TIMEToDetik(T);
    detik = detik + N;
    T = DetikToTIME(detik);
    return T;
}

TIME PrevDetik (TIME T){
    int detik;
    detik = TIMEToDetik(T);
    detik = detik-1 ;
    T = DetikToTIME(detik);
    return T;
}

TIME PrevNDetik (TIME T, int N){
    int detik;
    detik = TIMEToDetik(T);
    detik = detik-N ;
    T = DetikToTIME(detik);
    return T;
}

long Durasi (TIME TAw, TIME TAkh){
    if(TGT(TAkh,TAw)){
        return TIMEToDetik(TAkh)-TIMEToDetik(TAw);
    } else {
        return TIMEToDetik(TAkh) + 86400 - TIMEToDetik(TAw);
    }
}
