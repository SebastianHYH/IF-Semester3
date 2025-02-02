/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum susun_ulang.c */
/* 12 Desember 2024 */

#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

List rearrangeList(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        // Basis: List kosong atau hanya 1 elemen
        return copy(l);
    } else {
        // Rekurens: Pisahkan elemen pertama dan terakhir, susun ulang sisanya
        ElType first = head(l);
        List withoutFirst = tail(l);
        ElType last = head(reverseList(withoutFirst));
        List withoutLast = deleteLast(withoutFirst);

        // Gabungkan elemen pertama dan terakhir ke dalam hasil rekursi
        List rearranged = rearrangeList(withoutLast);
        return konsb(konso(rearranged, first), last);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    List l = NIL;
    for (int i = 0; i < n; i++) {
        ElType x;
        scanf("%d", &x);
        l = konsb(l, x);
    }

    List rearranged = rearrangeList(l);
    displayList(rearranged);

    return 0;
}