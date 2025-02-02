/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum merge_sorted_unique.c */
/* 12 Desember 2024 */

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    List temp1 = l1;
    List temp2 = l2;
    *res = NULL;
    List *lastPtr = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (INFO(temp1) < INFO(temp2)) {
            if (*lastPtr == NULL || INFO(*lastPtr) != INFO(temp1)) {
                *lastPtr = (List)malloc(sizeof(Node));
                INFO(*lastPtr) = INFO(temp1);
                NEXT(*lastPtr) = NULL;
                lastPtr = &NEXT(*lastPtr);
            }
            temp1 = NEXT(temp1);
        } else if (INFO(temp1) > INFO(temp2)) {
            if (*lastPtr == NULL || INFO(*lastPtr) != INFO(temp2)) {
                *lastPtr = (List)malloc(sizeof(Node));
                INFO(*lastPtr) = INFO(temp2);
                NEXT(*lastPtr) = NULL;
                lastPtr = &NEXT(*lastPtr);
            }
            temp2 = NEXT(temp2);
        } else {
            if (*lastPtr == NULL || INFO(*lastPtr) != INFO(temp1)) {
                *lastPtr = (List)malloc(sizeof(Node));
                INFO(*lastPtr) = INFO(temp1);
                NEXT(*lastPtr) = NULL;
                lastPtr = &NEXT(*lastPtr);
            }
            temp1 = NEXT(temp1);
            temp2 = NEXT(temp2);
        }
    }

    while (temp1 != NULL) {
        if (*lastPtr == NULL || INFO(*lastPtr) != INFO(temp1)) {
            *lastPtr = (List)malloc(sizeof(Node));
            INFO(*lastPtr) = INFO(temp1);
            NEXT(*lastPtr) = NULL;
            lastPtr = &NEXT(*lastPtr);
        }
        temp1 = NEXT(temp1);
    }

    while (temp2 != NULL) {
        if (*lastPtr == NULL || INFO(*lastPtr) != INFO(temp2)) {
            *lastPtr = (List)malloc(sizeof(Node));
            INFO(*lastPtr) = INFO(temp2);
            NEXT(*lastPtr) = NULL;
            lastPtr = &NEXT(*lastPtr);
        }
        temp2 = NEXT(temp2);
    }
}