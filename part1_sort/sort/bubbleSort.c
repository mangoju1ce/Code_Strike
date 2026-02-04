/*
    冒泡排序，相邻对比，将大的往后推，每次确定一个最大值在末尾
    时间复杂度O(n*n) 空间复杂度O(n)
*/
#include <stdio.h>
#define max 100005

void bubbleSort(int);

int a[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubbleSort(n);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

void bubbleSort(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        } 
    }
}