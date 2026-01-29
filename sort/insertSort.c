/*
    插入排序：前面保持有序，每次进入一个元素，插入到相应位置，初始时有序序列还没有元素
    故每次操作相当于将大于自身的数往后放
    时间复杂度: O(n*n) 空间复杂度：O(1)
*/
#include <stdio.h>
#define max 100005

void insertSort(int);

int a[max];
int main(void) {
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertSort(n);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

void insertSort(int n) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i-1;
        
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}