/*
    基数排序，正整数适用，找到第一位不同的数的位置后比较大小，
    对每一位进行稳定排序（后续不会改变相对位置）
    如对如下数组进行排序：329 459 836 436 -- 836 436 329 459 -- 329 836 436 459 -- 329 436 459 836
    时间复杂度：O(nlogV) V为数组中最大数 , 空间复杂度O(n)
*/

#include <stdio.h>
#define max 100005

void baseSort(int);

int a[max], b[max];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    baseSort(n);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    return 0;
}

void baseSort(int n) {
    int maxVal = a[0];
    //先找最多多少位
    for(int i = 1; i < n; i++){
        if(maxVal < a[i]) maxVal = a[i];
    }

    int bucket[10];
    //exp = 1表个位，exp = 10表十位
    for(long long exp = 1; maxVal/exp > 0; exp *= 10) {
        for(int i = 0; i < 10; i++) {
            bucket[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            int index = (a[i]/exp) % 10;
            bucket[index]++;
        }

        for(int i = 0; i < 9; i++) {
            bucket[i+1] += bucket[i];
        }

        //必须逆序排列，可以用简单例子尝试下，原因在于bucket[i]存的是：当前位数字 ≤ i 的元素个数
        for(int i = n-1; i >= 0; i--) {
            int index = (a[i]/exp) % 10;
            b[--bucket[index]] = a[i];
        }

        for(int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
}