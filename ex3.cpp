#include<iostream>
#include<vector>
using namespace std;


/*
    luogu P1616
    无限背包 每个物品可以装入无数个的背包问题 
    可以把它想成两层嵌套问题 
        0. 给定一个新物品k 和旧物品求得的dp数组dp  求背包最高价值 
            dp[i + w[k] ]  = max(dp[i+w[k]], dp[i] + val[k])   //用一维数组  

            如果用二维数组 应该是 
            dp[k][i+w[k]] = max( dp[k-1][i + w[k]], dp[k][i] + val[k]);  

            重点是要求i从低向高遍历 这样可以重复放入k
        

        1. 有物品序列arr 求背包最高价值 重复调用问题0的解即可

*/
int main(void){
    int time, num;
    cin>>time>>num;
    vector<int> val(num + 1,0);
    vector<int> t(num + 1,0);
    vector<long long> dp(time+1, 0);

    for(int i=1; i <= num; i++){
        cin>>t[i]>>val[i];
    }

    for(int i=1; i<=num; i++){
        for(int j = 0; j<=time; j++){
            if(j+t[i] <= time){  // have enough time to pick herb i
                dp[j + t[i]] = max(dp[j+t[i]],  dp[j] + val[i]);
            }
        }
    }
    cout<<dp[time];

}



/* 下面附上一个不用滚动数组 用二维数组的版本 在luogu会爆内存 */

/*
#include<iostream>
#include<vector>
using namespace std;


int main(void){
    int time, num;
    cin>>time>>num;
    vector<int> val(num + 1,0);
    vector<int> t(num + 1,0);
    vector<vector<long long>> dp(num + 1, vector<long long>(time + 1,0) );

    for(int i=1; i <= num; i++){
        cin>>t[i]>>val[i];
    }

    for(int i=1; i<=num; i++){
        for(int j = 1; j<=time; j++){
            if(j < t[i]){  // not enough time to pick herb i
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i][j-t[i]] + val[i] , dp[i-1][j]);
            }
        }
    }
    cout<<dp[num][time];

}

*/