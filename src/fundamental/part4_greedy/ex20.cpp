/*  
    P1094 [NOIP 2007 普及组] 纪念品分组
*/
#include <iostream>
#include <algorithm>
#define max 30005

using namespace std;

int price[max];
int main(void) {
    int w, n;
    cin >> w >> n;

    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }

    sort(price, price+n);
    int l = 0, r = n-1, ans = 0;
    while(l <= r) {
        if(l == r) {
            ans += 1;
            break;
        }
        if(price[l]+price[r] <= w) {
            ans += 1;
            l++;
            r--;
        } else {
            ans += 1;
            r--;
        }
    }

    cout << ans;
    return 0;
}