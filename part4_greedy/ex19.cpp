/*
    P4995 跳跳！
*/
#include <iostream>
#include <algorithm>
#define max 305

using namespace std;

int h[max];
int main(void) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    sort(h, h+n+1);
    int l = 0, r = n, flg = 0; 
    long long ans = 0;
    while(l <= r) {
        long long dh = h[r] - h[l];
        ans += dh*dh;

        if(flg % 2) r--;
        else l++;

        flg++;
    }

    cout << ans;
    return 0;
}