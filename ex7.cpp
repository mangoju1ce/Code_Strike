/*
    p1908
    本质考察归并排序，对每次合并[a0,a1,..a[mid]],[a[mid+1],a[mid+2],...an]，其中前后两数组均已顺序
    且对他们的逆序对已经计数，此时i指示前数组，j指示后数组，遍历i<=mid,j<=n，双指针每次选择较小值存入
    原数组，每次存入时有逆序对(mid+1-i)个，即ans += (mid+1-i)，归并结束，逆序对统计也结束。

    以下用示例直接说明：
    输入：
    6
    5 4 3 6 3 1
    第一轮：对区间(0,5)进行归并排序，l = 0，r = 5，则mid = 2，数组：[5,4,3],[6,3,1]
    第二轮：对区间(0,2), l = 0, r = 2, mid = 1, 数组：[5,4],[3]
            对区间(3,5), l = 3, r = 5, mid = 4, 数组：[6,3],[1]
    第三轮：对区间(0,1), l = 0, r = 1, mid = 0, 数组：[5] [4]
            对区间(3,4), l = 3, r = 4, mid = 3, 数组：[6] [3]
    第四轮：l>=r成立即仅单个元素，返回， 开始合并，计数逆序对(5,4)，将其顺序存回原数组
            同理，计数逆序对(6,3),将其顺序存回原数组
    第五轮：对[4,5][3]进行合并，计数逆序对(4,3)(5,3)，顺序存回原数组
            对[3,6],[1]进行合并，计数逆序对(3,1) (6,1),顺序存回
    第六轮：对[3,4,5]，[1,3,6]进行合并，计数逆序对(3,1)(4,1)(5,1)(4,3)(5,3)

    注意：洛谷中测试点的答案超过int，ans应开long long。
    时间复杂度：O(nlogn)
*/

#include <iostream>
#define max 500005

using namespace std;
void mergeSort(int , int);

int a[max], b[max];
long long ans;
int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(0, n-1);
    cout << ans;
    return 0;
}

void mergeSort(int l, int r) {
    if(l >= r) return ;
    
    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);

    int i = l, j = mid+1, index = 0;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j]) {
            b[index++] = a[i++];
        }else {
            b[index++] = a[j++];
            ans += (mid+1-i);
        }
    }
    while(i <= mid) {
        b[index++] = a[i++];
    }
    while(j <= r) {
        b[index++] = a[j++];
    }

    for(int i = 0; i < index; i++) {
        a[i+l] = b[i];
    }
}