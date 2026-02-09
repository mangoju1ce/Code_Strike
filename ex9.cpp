#include<iostream>  
#define MAX 25

bool control(int x, int y, int xh, int yh){
    return abs(x-xh)==1 && abs(y-yh)==2 || abs(x-xh)==2 && abs(y-yh) == 1 || x==xh && y == yh;
}

using namespace std;

int main(void){
    long long dp[MAX][MAX] = {0}, xb, yb, xh, yh;  
    cin>>xb>>yb>>xh>>yh;

    dp[0][0] = 1;
    for(int i=0; i<=xb; i++){
        for(int j=0; j<=yb; j++){
            if(control(i, j, xh, yh)){
                dp[i][j] = 0;
                continue;
            }
            
            if(i>0){
                dp[i][j] += dp[i-1][j];
            }
            if(j>0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    cout<<dp[xb][yb];
}