/*
    P1091 [NOIP 2004 提高组] 合唱队形
    dp1[i] 表示1~i的最长升序列
    dp2[i] 表示i~n的最长降序列

    最终的答案就是MAX(dp1[i]+dp2[i]-1)
*/
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dp1[MAX], dp2[MAX], h[MAX];
int main(void) {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        int maxLength = 0;
        for(int j = 1; j < i; j++) {
            if(h[j] < h[i]) {
                maxLength = max(maxLength, dp1[j]);
            }
        }
        dp1[i] += maxLength;
    }

    for(int i = n-1; i >= 1; i--) {
        int maxLength = 0;
        for(int j = n; j > i; j--) {
            if(h[j] < h[i]) {
                maxLength = max(maxLength, dp2[j]);
            }
        }
        dp2[i] += maxLength;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp1[i]+dp2[i]-1);
    }

    /*
    for(int i = 1; i <= n; i++) cout << dp1[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << dp2[i] << " ";
    cout << endl;*/
    cout << n-ans;
    return 0;
}