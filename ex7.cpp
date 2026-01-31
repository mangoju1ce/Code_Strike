#include<iostream>  

using namespace std;

/*
    luogu P1833 
    又一个背包问题 承接ex2的01背包 ex3的无限背包 
    这道题需要综合考虑01, 多重，无限三种背包  
    01背包 反向更新dp数组 
    多重背包 多次重复01背包  
    无限背包 正向更新dp数组 

    值得注意的是 luogu题解给出了几种多重背包的时间优化方法  
        1.二进制拆分
            如果一个物品可以放入n次 不要简单地做n次01背包  
            而是把n做二进制拆分 比如可以放入7次的物品 由于7= 1+2+4 
            我们只考虑放1次 放2次 放4次三类情况 相当于生成了三种物品 考虑这三种物品的01背包  
        2.单调队列  
            没看懂 脑子转不动了 
*/

int main(void){
    int h1,m1,h2,m2,n, total_time;
    int t, val, cnt;
    int dp[1001] = {0};
    char c;
    cin>>h1>>c>>m1>>h2>>c>>m2>>n;
    total_time = (h2-h1) * 60 + m2 - m1;
    for(int i=0; i<n;i++){
        cin>> t >> val >>cnt;
        if(cnt == 0){  // infinity backpack
            for(int begin = 0; begin + t <= total_time; begin ++){
                dp[begin + t] = max(dp[begin+t], dp[begin] + val);
            }
        }
        else{ //finite backpack, do 0-1 backpack of the same tree for multiple times
            for(int look=0; look<cnt; look++){
                for(int end = total_time; end >= t; end--){
                    dp[end] = max(dp[end], dp[end-t] + val);
                }
            }
        }
    }
    cout<<dp[total_time];

}