/* Sebastian Hung Yansen */
/* 13523070 */
/* Praktikum bola.c */
/* 26 November 2024 */

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

void deleteAt(List *l, int pos, int *deletedValue) {
    Address p = FIRST(*l);
    Address prev = NULL;
    int i;

    // Traverse to the node at position pos
    for (i = 0; i < pos; i++) {
        prev = p;
        p = NEXT(p);
    }

    // Store the value to be deleted
    *deletedValue = INFO(p);

    // If the node to be deleted is the first node
    if (prev == NULL) {
        FIRST(*l) = NEXT(p);
    } else {
        NEXT(prev) = NEXT(p);
    }

    // If the list becomes empty after deletion
    if (FIRST(*l) == p) {
        FIRST(*l) = NULL;
    }

    // Free the memory of the deleted node
    free(p);
}

int main() {
    int N, listElmt, temp;
    boolean firstDeletion = true;
    int i;
    List l;
    scanf("%d", &N);
    CreateList(&l);
    
    // Mengisi List
    for (i = 1; i <= N; i++) {
        insertLast(&l, i);
    }
    
    int currentPos = 0; // Track the current position in the circular list
    
    for (i = 0; i < N-1; i++) {
        scanf("%d", &listElmt);
        if (listElmt > 0) {
            currentPos = (currentPos + listElmt) % N;
        } else if (listElmt < 0) {
            currentPos = (currentPos + listElmt + N) % N;
        }
        
        if (firstDeletion) {
            deleteAt(&l, currentPos, &temp);
            firstDeletion = false;
        } else {
            deleteAt(&l, currentPos, &temp);
            currentPos = (currentPos - 1 + N) % N; // Adjust position after deletion
        }
    }
    
    printf("%d\n", INFO(FIRST(l)));
    return 0;
}