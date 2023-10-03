//resource--https://www.youtube.com/watch?v=lPL-pmBm04Q
//ques-//https://www.hackerrank.com/contests/17cs1102/challenges/7a-circular-queue-using-arryas/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int f = -1;
    int r = -1;
    int n = 5;
    int arr[5]; // Assuming 'arr' is an integer array with size 'n'
    int size=0;

    while (1) {
        int k;
        scanf("%d", &k);

        if (k == 1){
            int m;
            scanf("%d", &m);
            if ((r + 1) % n == f) {
                printf("Queue Overflow\n");
            }
            else{
            r=(r+1)%n;
            arr[r] = m;size++;
            }
            if(f==-1){
                f=0;
            }
        }
        if (k == 2) {
            if (f == -1) {
                printf("Queue Underflow\n");
            }
            if (f == r) {
                r = -1;
                f = -1;size--;
            }
            else{
            f=(f+1)%n;size--;
            }
        }
        if (k == 3) {
            if(f==-1){
                printf("NULL\n");
            }
            else{
            for (int i = 0; i<size;i++) {
                int b=(f+i)%n;
                printf("%d ", arr[b]);
            }
            printf("\n");
        }}

        if (k == 4) {
            break;
        }
    }

    return 0;
}
