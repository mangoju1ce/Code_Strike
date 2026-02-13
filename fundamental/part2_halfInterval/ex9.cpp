/*
    洛谷p2678 跳石头
    求最短跳跃距离中的最大值，二分答案，d最小为1，最大为L，不断二分检查是否成立
*/
#include <iostream>
#define max 50005

using namespace std;
bool check(int);

int a[max], ans, L, N, M;
int main(void) {
    cin >> L >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

    int l = 1, r = L;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << ans;
    return 0;
}

//贪心检查d是否符合
bool check(int d) {
    //last记录上一个石头
    int last = 0, removeCnt = 0;
    for(int i = 1; i <= N ; i++){
        //必须拿掉这个石头
        if(a[i] - last < d){
            removeCnt++;
        } else {
            last = a[i];
        }
    }

    if(L - last < d) removeCnt++;
    return removeCnt <= M;

}