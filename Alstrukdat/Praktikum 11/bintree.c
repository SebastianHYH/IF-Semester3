/* Sebastian Hung Yansen */
/* 13523070 */
/* Pra-Praktikum bintree.c */
/* 19 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "boolean.h"

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree) {
   Address p = newTreeNode(root);
   if (p != NULL) {
      LEFT(p) = left_tree;
      RIGHT(p) = right_tree;
   }
   return p;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p) {
   *p = newTreeNode(root);
   if (p != NULL) {
      LEFT(*p) = left_tree;
      RIGHT(*p) = right_tree;
   }
}

Address newTreeNode(ElType val) {
   Address p = malloc(sizeof(TreeNode));
   if (p != NULL) {
      ROOT(p) = val;
      LEFT(p) = NULL;
      RIGHT (p) = NULL;
   }
   return p;
}

void deallocTreeNode (Address p) {
   free(p);
}

boolean isTreeEmpty (BinTree p) {
   return p == NULL;
}

boolean isOneElmt (BinTree p) {
   return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
}

boolean isUnerLeft (BinTree p) {
   return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p));
}

boolean isUnerRight (BinTree p) {
   return !isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

boolean isBinary (BinTree p) {
   return !isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p));
}

/* ****** Display Tree ***** */
void printPreorder(BinTree p) {
   if(isTreeEmpty(p)) {
      printf("()");
   } else {
      printf("(");
      printf("%d", ROOT(p));
      printPreorder(LEFT(p));
      printPreorder(RIGHT(p));
      printf(")");
   }
}

void printInorder(BinTree p) {
   if(isTreeEmpty(p)) {
      printf("()");
   } else {
      printf("(");
      printInorder(LEFT(p));
      printf("%d", ROOT(p));
      printInorder(RIGHT(p));
      printf(")");
   }
}

void printPostorder(BinTree p) {
   if (isTreeEmpty(p)) {
      printf("()");
   } else {
      printf("(");
      printPostorder(LEFT(p));
      printPostorder(RIGHT(p));
      printf("%d", ROOT(p));
      printf(")");
   }
}

void printTreeDepth(BinTree p, int h, int depth) {
   if (!isTreeEmpty(p)) {
      int i, space = depth * h;
      for (i = 0; i < space; i++) {
         printf(" ");
      }
      printf("%d\n", ROOT(p));
      printTreeDepth(LEFT(p), h, depth+1);
      printTreeDepth(RIGHT(p), h, depth+1);
   }
}

void printTree(BinTree p, int h) {
   printTreeDepth(p, h, 0);
}

boolean isEqual(BinTree p1, BinTree p2) {
   if (isTreeEmpty(p1) && isTreeEmpty(p2)) {
      return true;
   } else if (!isTreeEmpty(p1) && !isTreeEmpty(p2)) {
      return (ROOT(p1) == ROOT(p2)) && isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2));
   } else {
      return false;
   }
}

int getMaximumDepth(BinTree p) {
   if (isTreeEmpty(p)) {
      return 0;
   } else {
      int leftDepth = getMaximumDepth(LEFT(p));
      int rightDepth = getMaximumDepth(RIGHT(p));
      return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
   }
}

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end) {
   if (start > end) {
      return NULL;
   }
   ElType mid = (start + end) / 2;
   BinTree p = newTreeNode(arr[mid]);
   if (p != NULL) {
      LEFT(p) = createBinSearchTreeFromSortedArray(arr, start, mid - 1);
      RIGHT(p) = createBinSearchTreeFromSortedArray(arr, mid + 1, end);
   }
   return p;
}

int countNodes(BinTree p) {
   if (isTreeEmpty(p)) {
      return 0;
   } else {
      return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
   }
}

boolean isElmtInTree(BinTree p, ElType target) {
   if (isTreeEmpty(p)) {
      return false;
   } else if (ROOT(p) == target) {
      return true;
   } else {
      return isElmtInTree(LEFT(p), target) || isElmtInTree(RIGHT(p), target);
   }
}

void printPathToElement(BinTree p, ElType target) {
    if (isTreeEmpty(p)) {
        printf("-1\n");
        return;
    }

    // Fungsi bantu untuk mencetak jalur
    boolean printPath(BinTree p, ElType target) {
        if (isTreeEmpty(p)) {
            return false;
        }
        if (ROOT(p) == target) {
            printf("%d", ROOT(p));
            return true;
        }
        if (printPath(LEFT(p), target) || printPath(RIGHT(p), target)) {
            printf(" -> %d", ROOT(p));
            return true;
        }
        return false;
    }

    if (!printPath(p, target)) {
        printf("-1\n");
    } else {
        printf("\n");
    }
}