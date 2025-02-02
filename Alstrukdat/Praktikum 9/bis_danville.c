/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum bis_danville.c */
/* 4 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list_circular.h"

int main(){
    List l;
    CreateList(&l);
    int N,a;

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &a);
        insertLast(&l, a);
    }

    ElType val;
    boolean clockwise = true, counter_clock = true;
    Address p = FIRST(l);
    while(NEXT(p) != FIRST(l) && clockwise){
        if((INFO(p) % N) != (INFO(NEXT(p)) - 1)){
            clockwise = false;
        }
        p = NEXT(p);
    }
    if((INFO(p) % N) != (INFO(NEXT(p)) - 1) && clockwise){
        clockwise = false;
    }


    p = FIRST(l);
    while(NEXT(p) != FIRST(l) && counter_clock){
        if((INFO(p)-1) != (INFO(NEXT(p))% N)){
            counter_clock = false;
        }
        p = NEXT(p);
    }
    if(INFO(p) != ((INFO(NEXT(p)) + 1) % N) && counter_clock){
        counter_clock = false;
    }


    if(clockwise || counter_clock){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}