/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum listrec.c */
/* 12 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return length(l) == 1;
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p == NIL) {
        return l;
    } else {
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e) {
    Address p = newNode(e);
    if (p == NIL) {
        return l;
    } else {
        if (isEmpty(l)) {
            return p;
        } else {
            NEXT(l) = konsb(NEXT(l), e);
            return l;
        }
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else if (head(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx) {
    if (idx == 0) {
        return konso(l, e);
    } else if (isEmpty(l)) {
        return l;
    } else {
        List rest = insertAt(tail(l), e, idx - 1);
        return konso(rest, head(l));
    }
}

List deleteFirst(List l) {
    if (isEmpty(l)) {
        return l;
    } else {
        return tail(l);
    }
}

List deleteAt(List l, int idx) {
    if (idx == 0) {
        return tail(l);
    } else if (isEmpty(l)) {
        return l;
    } else {
        List rest = deleteAt(tail(l), idx - 1);
        return konso(rest, head(l));
    }
}

List deleteLast(List l) {
    if (isOneElmt(l)) {
        return NIL;
    } else if (isEmpty(l)) {
        return l;
    } else {
        List rest = deleteLast(tail(l));
        return konso(rest, head(l));
    }
}

List reverseList(List l) {
    if (isEmpty(l)) {
        return l;
    } else {
        List rest = reverseList(tail(l));
        return konsb(rest, head(l));
    }
}

void splitOddEven(List l, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else {
        List rest1, rest2;
        splitOddEven(tail(l), &rest1, &rest2);
        if (head(l) % 2 == 0) {
            *l1 = konso(rest1, head(l));
            *l2 = rest2;
        } else {
            *l1 = rest1;
            *l2 = konso(rest2, head(l));
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2) {
    if (isEmpty(l)) {
        *l1 = NIL;
        *l2 = NIL;
    } else if (head(l) == x) {
        *l1 = NIL;
        *l2 = copy(l);
    } else {
        List rest1, rest2;
        splitOnX(tail(l), x, &rest1, &rest2);
        *l1 = konso(rest1, head(l));
        *l2 = rest2;
    }
}

ElType getMiddle(List l) {
    int len = length(l);
    int midIdx = len / 2;
    List temp = l;
    for (int i = 0; i < midIdx; i++) {
        temp = tail(temp);
    }
    return head(temp);
}