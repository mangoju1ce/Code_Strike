/*
    2026/1/28
    p1177 模板题，快速排序
    对序列a1,a2,a3,...an,进行从小到大排序，每次选定一个数组a中的一个数x，将该数组分为3个数组b，c，d
    将小于x的数放入数组b，大于x的数放入数组d，等于x的数放入数组c，递归地对数组b与数组d进行快速排序
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100005

void qsort_(int, int);
int rand_(int l, int r);//从l到r之间选择随机数

int a[max],b[max],c[max],d[max];

int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort_(0, n-1);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

int rand_(int l, int r) {
    return rand()%(r-l+1)+l;
}

void qsort_(int l, int r) {
    if(l >= r) return;//当数组大小为0或1时无需排序
    int x = rand_(l,r), size1 = 0, size2 = 0, size3 = 0;
    for(int i = l; i <= r; i++) {
        if(a[i] < a[x]){
            b[size1++] = a[i];
        } else if(a[i] == a[x]) {
            c[size2++] = a[i];
        } else {
            d[size3++] = a[i];
        }
    }

    for(int i = 0; i < size1; i++) {
        a[i+l] = b[i]; 
    }
    for(int i = 0; i < size2; i++) {
        a[i+l+size1] = c[i];
    }
    for(int i = 0; i < size3; i++) {
        a[i+l+size1+size2] = d[i];
    }

    qsort_(l, l+size1-1);
    qsort_(l+size1+size2, r);
}