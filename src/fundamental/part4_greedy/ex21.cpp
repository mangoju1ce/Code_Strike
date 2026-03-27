/*
    P1199 [NOIP 2010 普及组] 三国游戏

    蛮有意思的题目，小涵是必胜的，默契值最大的组合永远被打乱，小涵是不可能选到的这样的组合的，那么
    小涵想赢也应该学着计算机，每次不让计算机拿到最大的默契值，故只要小涵事先将所有次大值里的最大值找
    到，先将这对武将组合选择，而后贪心选择即可获胜。
    所以将所有组合里默契值次大的拿出来排序，里面的最大值即为答案

    例如，案例1：
    6 
    5 28 16 29 27 
    23 3 20 1 
    8 32 26 
    33 11 
    12 

    此时对1~6号武将，相应的最大默契值为29、23、32、33、33、27，次大默契值为28、20、28、16、32、26
    我们锁定次大默契值里最大值32，它是3号武将和5号武将的默契值，
    那么小涵就应该先选择5号武将，计算机会选择4号武将
    小涵接下来先将另外一个武将选出，即3号武将，计算机会选择1号武将
    小涵接下来贪心的选择6号武将，计算机选择2号武将
*/
#include <iostream>
#define MAX 505

using namespace std;

int a[MAX][MAX];
int main(void) {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n-1; i++) {
        for(int j = i+1; j <= n; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            a[j][i] = x;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int first = 0, second = 0;
        for(int j = 1; j <= n; j++) {
            if(j == i) continue;
            if(a[i][j] > first) first = a[i][j];
        }
        for(int j = 1; j <= n; j++) {
            if(j == i || a[i][j] == first) continue;
            if(a[i][j] > second) second = a[i][j];
        }
        ans = max(ans, second);
    }

    cout << 1 << endl <<  ans;
    return 0;
}