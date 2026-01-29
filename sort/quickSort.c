//快速排序，双指针版，以首节点为基准
#include <stdio.h>
#define max 100005

void quickSort(int l, int r);

int a[max];
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

void quickSort(int l, int r) {
    if(l >= r) return;

    int base = a[l], i = l, j = r;
    while(i < j) {
        //从右往左找比base小的放在左边
        while(i < j  && a[j] >= base) j--;
        if(i < j) a[i++] = a[j];
        //从左往右找比base大的放在右边
        while(i < j && a[i] <= base) i++;
        if(i < j) a[j--] = a[i];
    }
    a[i] = base;//base放在中间

    quickSort(l, i-1);
    quickSort(i+1, r);/*注意一定是i+1，而不是i，从表面上看在进行上面双指针遍历后，左边都是比a[i]小的
    右边都是比a[i]大的，加不加无所谓；但如果第一个数就是数组中最小的数，会造成重复的遍历这个数组。*/
}