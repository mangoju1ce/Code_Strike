/*
    洛谷p1059 简单桶排序即可
*/

#include <stdio.h>

int arr[1005], a[105];
int main(void) {
    int n;
    scanf("%d", &n);

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(!arr[a[i]]) {
            arr[a[i]]++;
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int i = 1; i <= 1000; i++) {
        if(arr[i]) printf("%d ", i);
    }
    return 0;
}