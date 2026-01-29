/*
    希尔排序，插入排序的优化算法，原插入排序以1为gap，这里初始gap为n/2，且逐次除2
    时间复杂度：O(nlogn)  空间复杂度：O(1) 是一个原地算法
*/
#include <stdio.h>
#define max 100005

void shellSort(int );

int a[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    shellSort(n);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n",a[n-1]);
    return 0;
}

void shellSort(int n) {
    for(int gap = n/2; gap >= 1; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int key = a[i], j = i;
            while(j >= gap && a[j-gap] > key){
                a[j] = a[j-gap];
                j -= gap;
            }
            a[j] = key;
        }
    }
}