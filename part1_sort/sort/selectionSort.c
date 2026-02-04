/*
    选择排序，每次选择后面最小的一个数放在当前开头位置
    时间复杂度：O(n*n) 空间复杂度：O(n)
*/
#include <stdio.h>
#define max 100005

void selectionSort(int);

int a[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectionSort(n);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

void selectionSort(int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int tmp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = tmp;
        }
    }
}