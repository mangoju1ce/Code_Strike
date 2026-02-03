/*
    二分答案,时间复杂度O(log2(1e14) * l), 当l较大时，O(l)
*/
#include <iostream>
#include <climits>
#define MAX 100005

using namespace std;
long long work(long long );

int l, k, a[MAX];
int main(void) {
    cin >> l >> k;

    for(int i = 0; i < l; i++) {
        cin >> a[i];
    }

    long long left = 1, right = 1e14, min = 0, max = 0;
    while(left <= right) {
        long long mid = (left+right)/2;
        if(work(mid) >= k){
            left = mid+1;
            if(work(mid) == k) max = mid;
        } else {
            right = mid-1;
        }
    }

    left = 1;
    right = 1e14;
    while(left <= right) {
        long long mid = (left+right)/2;
        if(work(mid) <= k) {
            right = mid-1;
            if(work(mid) == k) min = mid;
        }
        else {
            left = mid+1;
        }
    }
    
    if(max == 0 && min == 0) cout << -1;
    else cout << min << " " << max;
    return 0;
}

//对于固定长度length，返回刷题数
long long work(long long length) {
    int index = 0;
    long long sum = 0, cnt = 0;
    while(index < l){
        sum += a[index];
        if(sum >= length){
            cnt++;
            sum = 0;
        }
        if(sum < 0) sum = 0;
        index++;
    }
    return cnt;
}