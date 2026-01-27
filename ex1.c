/*  
    2026/1/26

    洛谷 P3166 [CQOI2014] 数三角形

    题目描述
    给定一个 N×M 的网格，请计算三点都在格点上的三角形共有多少个。注意三角形的三点不能共线。

    输入格式
    输入一行，包含两个空格分隔的正整数 M 和 N。

    输出格式
    输出一个正整数，为所求三角形数量。

    输入输出样例
    输入 6 9
    输出 52758

    对于全部的测试点，保证 1≤N,M≤1000。
*/

/*
    说明：
    随机选择三个点后去掉三点共线数即可；对于三点共线情况，横竖非常容易解决，主要问题在于如何数满
    斜率存在且非零的情况，我尝试过对斜率进行遍历或者尝试递归，都没有得到正确答案，总有遗漏，以下
    代码采用比较巧妙的向量法。

    对于斜线，先考虑斜率大于0，小于0部分与其完全对称，末尾乘2即可。
    考虑任意可取向量（i,j）其中i>0,j>0，若以(0,0)为起点，易得该向量可以经过网格的gcd(i,j)+1个整数点。
    对所有可能的向量(i,j)进行遍历，固定头和尾（即我们所选的三个点一个是向量头一个是向量尾），则中间点
    有gcd(i,j)-1种选择可能
    考虑到该向量可以上下左右平移，固共有(M-i+1)*(N-j+1)种向量选择
    故对于向量(i,j),共线数为(M-i+1)*(N-j+1)*(gcd(i,j)-1)*2
*/
#include <stdio.h>
#include <stdlib.h>

long long CountTriangle(int , int);
long long Combination_Of_3(long long);
int gcd(int , int );

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%lld\n", CountTriangle(N, M));
    return 0;
}

long long CountTriangle(int N, int M) {
    long long ans = Combination_Of_3((M+1)*(N+1));

    ans -= Combination_Of_3(N+1) * (M+1);// 竖，即斜率不存在
    ans -= Combination_Of_3(M+1) * (N+1);// 横，即斜率为零
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            ans -= (M-i+1)*(N-j+1)*(gcd(i,j)-1)*2;
        }
    }
    return ans;
}

//C(n,3),其中当n小于3时返回0
long long Combination_Of_3(long long x){
    if(x <= 2) return 0; // 特殊地，N = 1
    return x*(x-1)*(x-2)/6;
}

// 最大公因数，要求x >= y成立
int gcd(int x, int y) {
    if(x < y) {int t = x; x = y; y = t;}
    while(y) {
        int t = x%y;
        x = y;
        y = t;
    }
    return x;
}