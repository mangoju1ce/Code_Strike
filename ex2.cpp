#include<iostream>
#include<vector>
using namespace std;


/*
    luogu P1048
    简单01背包 
*/
int main(void){
    int time, num;
    cin>>time>>num;
    vector<int> val(num + 1,0);
    vector<int> t(num + 1,0);
    vector<vector<int>> dp(num + 1, vector<int>(time + 1,0) );

    for(int i=1; i <= num; i++){
        cin>>t[i]>>val[i];
    }

    for(int i=1; i<=num; i++){
        for(int j = 1; j<=time; j++){
            if(j < t[i]){  // not enough time to pick herb i
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-t[i]] + val[i] , dp[i-1][j]);
            }
        }
    }
    cout<<dp[num][time];

}