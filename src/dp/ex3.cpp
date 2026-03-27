/*
    P1095 [NOIP 2007 普及组] 守望者的逃离
    dp[i] 表示第i秒能跑的最远距离；flg[i] 记录第i秒的行为，1表普通前进，0表魔法前进

    对于最远距离，我们来考虑魔法值带来的价值：
    若 m >= 10, 这代表我们这一步就可以魔法前进，速度期望为 60
    若 m >= 6，这代表我们只需停一步就可以获得魔法前进，速度期望为 30
    若 m >= 2，这代表我们需要停两步就可以获得魔法前进，速度期望为 20
    若 m < 2，发现需要4步才能魔法前进，速度期望为15，甚至不如普通前进，但当你可以走满7步时，速度期望就为120/7 = 17.3
    
    因此，首先对初始魔法值，走到m<10为止，然后的每一步都对魔法值进行讨论，这里要注意，例如m>=6时，停的那一步在计算dp时依旧
    采用普通前进，因为dp代表的是能走的最远距离，我们希望每一步都在走。区别在与当前步你可以以i-2为跳板走的更远。
    
    而这里采用flg来标志魔法前进和普通前进的原因在于，如m>=2的情况下，等待的两步中先前走的是魔法前进的情况下，停下来去走
    后面的魔法前进显然是期望更小的
*/
#include <bits/stdc++.h>
#define MAX 30005
using namespace std;

int dp[MAX], flg[MAX];
int main(void) {
    int m, s, t;
    cin >> m >> s >> t;

    int i;
    for(i = 1; i <= m/10; i++) {
        dp[i] = dp[i-1] + 60;
        //cout << "time:" << i << " move:" << flg[i] << " s:" << dp[i] << " m:" << m << endl;
        if(dp[i] >= s) {
            cout << "Yes" << endl << i;
            return 0;
        }
        if(i >= t && dp[i] < s) {
            cout << "No" << endl << dp[i];
            return 0;
        } 
    }
    m %= 10;
    
    //默认普通前进，往前看能否魔法前进
    while(i <= t) {
        if(i > 2 && flg[i-1] == 1 && m >= 6) {
            if(dp[i-2]+60 > dp[i-1]+17) {
                dp[i] = dp[i-2]+60;
                m -= 6;
            }
        }
        else if(i > 3 && flg[i-2] == 1 && flg[i-1] == 1 && m >= 2) {
            if(dp[i-3]+60 > dp[i-1]+17 && dp[i-3]+60 > dp[i]) {
                dp[i] = dp[i-3]+60;
                m -= 2;
            }
        }
        else if(m < 2 && t-i>=6 && s-dp[i-1] >= 120) {
            for(int j = i; j <= i+3; j++) dp[j] = dp[i-1]+60;
            for(int j = i+4; j <= i+6; j++) dp[j] = dp[i-1]+120;
            i = i+6;
        }
        else{
            dp[i] = dp[i-1]+17;
            flg[i] = 1;
        }

       // cout << "time:" << i << " move:" << flg[i] << " s:" << dp[i] << " m:" << m << endl;
        if(dp[i] >= s) {
            cout << "Yes" << endl << i;
            return 0;
        }
        i++;
    }
    cout << "No" << endl << dp[i-1];
    return 0;
}