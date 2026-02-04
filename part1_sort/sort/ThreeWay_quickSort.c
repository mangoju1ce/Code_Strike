/*
    三路快排，随机数为基准，平均时间复杂度为O(n*logn),最坏时间复杂度为O(n*n)，空间复杂度O(n)
    注意事项：
    1、1e5这样的科学计数法表示默认double，我先前#define max时使用，报错
    2、rand()函数,srand()函数位于头函数stdlib.h，其中rand函数根据随机数种子生成伪随机数，
    srand函数设置随机数种子，在main中先使用srand函数，否则可能造成每次rand同一个值。         
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100005

void quickSort(int ,int );
int randomInt(int ,int );

int a[max], b[max], c[max], d[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(0, n-1);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n",a[n-1]);
    return 0;
}

int randomInt(int l, int r) {
    return rand()%(r-l+1)+l;
}

void quickSort(int l, int r) {
    if(l >= r) return;
    int x = randomInt(l, r);
    int size_b = 0, size_c = 0, size_d = 0;
    for(int i = l; i <= r; i++) {
        if(a[i] < a[x]) {
            b[size_b++] = a[i];
        } else if(a[i] == a[x]) {
            c[size_c++] = a[i];
        } else {
            d[size_d++] = a[i];
        }
    }

    for(int i = 0; i < size_b; i++) {
        a[l+i] = b[i];
    }
    for(int i = 0; i < size_c; i++) {
        a[l+size_b+i] = c[i];
    }
    for(int i = 0; i < size_d; i++) {
        a[l+size_b+size_c+i] = d[i];
    }

    quickSort(l, l+size_b-1);
    quickSort(l+size_b+size_c, r);
}