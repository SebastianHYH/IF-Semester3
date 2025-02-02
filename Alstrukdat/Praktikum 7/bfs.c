/* Sebastian Hung Yansen */
/* 13523070 */
/* Latihan Praktikum bfs.c */
/* 21 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;

int main()
{
    int N;
    ElType start, dest;
    char arr[MXN][MXN];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'A')
            {
                // Start
                start.row = i;
                start.col = j;
            }
            else if (arr[i][j] == 'B')
            {
                // Destination
                dest.row = i;
                dest.col = j;
            }
        }
    }

    // Start code here...
    int dist[100][100];
    boolean found =false;
    Queue q;
    CreateQueue(&q);
    ElType CurrentEl;
    CurrentEl = start;
    arr[CurrentEl.row][CurrentEl.col] = 'V';
    while (true){
        if (CurrentEl.row == dest.row && CurrentEl.col == dest.col){
            found = true;
            break;
        }
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (i == 0 && j == 0){
                    continue;
                }
                if (i != 0 && j != 0){
                    continue;
                }
                if (CurrentEl.row+i >= 0 && CurrentEl.row+i < N && CurrentEl.col+j >= 0 && CurrentEl.col+j < N){
                    if (arr[CurrentEl.row+i][CurrentEl.col+j] == '.' || arr[CurrentEl.row+i][CurrentEl.col+j] == 'B'){
                        arr[CurrentEl.row+i][CurrentEl.col+j] = 'V';
                        dist[CurrentEl.row+i][CurrentEl.col+j] = dist[CurrentEl.row][CurrentEl.col] + 1;
                        ElType temp;
                        temp.row = CurrentEl.row+i;
                        temp.col = CurrentEl.col+j;
                        enqueue(&q, temp);
                    }
                }
            }
        }
        if (isEmpty(q)){
            break;
        }
        dequeue(&q, &CurrentEl);
    }
    if (found){printf("Ya\n%d\n", dist[dest.row][dest.col]);}
    else {printf("Tidak\n");}
    return 0;
}