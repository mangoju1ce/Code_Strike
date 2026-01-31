#include<iostream> 
#define SIZE 6 
#define IS_ILLEGAL_MASK(x) (((x) & ((x) << 1)) != 0)

#define IS_COMPATIBLE_MASK(x,y) ((((x) & ((y)<<1)) == 0) && (((x)&(y)) == 0) && (((x)&(y)>>1) == 0))  // check two mask are compatible on neighbouring row

using namespace std;

/*
    一道状态压缩dp的例题 

    状态压缩dp是指 用一个二进制数保存状态 用dp方式 实现旧状态推导新状态 最终得到所有状态下的解

    在这个题目里面，状态就是每一行怎么选数字。用dp的方法 可以通过上一行在不同选法下的最大数字和 推得这一行在不同选法下的最大数字和。 

    具体来说 我们由上往下，一行行选数字    则 
        dp[row][mask] 表示 选完第row行且第row行状态为mask（二进制数）时 最大数字和  
        我们所求就是dp[N][m] 的最大值 m为所有可能mask
        dp转移的方式是：
            dp[row][mask] = mask对应的本行数字和 + MAX( dp[row-1][m] ) // m要遍历row-1行的所有可能选法

*/
int main(void){
    int query, row, col, mat[SIZE+1][SIZE+1]; 
    cin>>query;

    for(int q=0; q<query; q++){ // process a query
        int dp[2][1<<SIZE] = {0};  // scrolling dp array: i%2 is current row, 1-i%2 is last row

        cin>>row>>col;  

        for(int i=1;i<=row;i++){  // read the matrix
            for(int j=1;j<=col;j++){
                cin>>mat[i][j];
            }
        }

        for(int i=1; i<=row; i++){  // pick number row by row
            //cout<<"row "<<i<<endl;
            for(int mask = 0; mask < (1<<col); mask++){      // go through every possible solution
                if(IS_ILLEGAL_MASK(mask)){continue;}  //invalid mask
                int last_max = 0;
                for(int m=0; m< (1<<col); m++){
                    if(IS_ILLEGAL_MASK(m) || !IS_COMPATIBLE_MASK(mask, m)){continue;}  // skip illegal or incompatible solution for last row 
                    last_max = max(last_max, dp[1-i%2][m]);
                }
                int cur = 0;  // added num for current row
                for(int j=0; j<col; j++){
                    if(((1<<j) & mask) != 0){
                        cur += mat[i][j+1];
                    }
                }
                dp[i%2][mask] = cur + last_max;
                //cout<<" mask "<<mask<<" dp "<<dp[i%2][mask];
            }
            //cout<<endl;
        }

        int ans = 0;
        for (int j = 0; j < (1<<col); j++)
        {
            ans = max(ans, dp[row%2][j]);
        }
        
        cout<<ans<<endl;
    }
    return 0;
}