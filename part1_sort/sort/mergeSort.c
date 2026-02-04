/*
    归并排序，对a1,a2,...an进行排序时，取mid = (1+n)/2,对a1,a2,...a[mid]进行排序与a[mid+1],
    a[mid+2],....a[n]进行排序，然后将两者合并进行排序

    时间复杂度O(nlogn) 空间复杂度O(n)
*/

#include <stdio.h>
#define max 100005

void mergesort(int, int);
void merge(int, int);

int a[max], b[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(0, n-1);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

void mergesort(int l, int r) {
    if(l >= r) return;

    int mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merge(l, r);
}

void merge(int l, int r){
    if(l >= r) return;

    int mid = (l+r)/2, i = l, j = mid+1, index = 0;
    while(i <= mid && j <= r) {
        if(a[i] > a[j]){
            b[index++] = a[j++];
        }else {
            b[index++] = a[i++];
        }
    }

    while(i <= mid) {
        b[index++] = a[i++];
    }
    while(j <= r) {
        b[index++] = a[j++];
    }

    for(int i = 0; i < index; i++) {
        a[l+i] = b[i];
    }
}