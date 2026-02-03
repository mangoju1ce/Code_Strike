/*
    p1083 借教室
    先暴力枚举看看, 11,12,15-20共8个测试点TLE，分析时间复杂度，对于最坏情况，即m次询问都遍历结束
    区间[s,t]均为[1,n]，时间复杂度为O(n*m),对于n,m取10^6时显然太大
    
    考虑使用差分数组和二分答案来优化：
    首先若第k次询问借教室没法供应，则k+1~m次肯定无法供应，故可以考虑对[1,m]进行二分答案，每次check
    是否可以供应，最终找到最大的k即可。
    对于每一个k，有对应的k个区间，对区间内每个点都要减相同的数，可以使用差分数组，每次只需更新头和尾
    最终求前缀和即可判断.即对于差分数组dif，对区间[l,r]的修改，只需dif[l] -= d,dif[r+1] += d即可
    时间复杂度为O(n*log2m)
*/
#include <iostream>
#include <cstring>
#define max 1000005

using namespace std;

bool check(int);

int a[max], dif[max], n, m;
int d[max], s[max], t[max];
int main(void) {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> d[i] >> s[i] >> t[i];
    }

    int l = 1, r = m, ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) l = mid+1;
        else {
            r = mid-1;
            ans = mid;
        }
    }

    if(ans) cout << -1 << endl << ans;
    else cout << 0;
    
    return 0;
}

bool check(int k) {
    memset(dif, 0, sizeof(dif));
    for(int i = 1; i <= n; i++) {
        dif[i] = a[i] - a[i-1];
    }

    //差分数组更新
    for(int i = 1; i <= k; i++) {
        dif[s[i]] -= d[i];
        dif[t[i]+1] += d[i];
    }

    //前缀和
    for(int i = 1; i <= n; i++) {
        dif[i] += dif[i-1];
        if(dif[i] < 0) return false;
    }
    return true;
}
/*
#include <iostream>
#define max 1000005
using namespace std;

int a[max];
int main(void) {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= m; i++) {
        int d, s, t;
        cin >> d >> s >> t;
        for(int j = s; j <= t; j++) {
            a[j] -= d;
            if(a[j] < 0){
                cout << -1 << endl;
                cout << i;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
*/
