/*
    P5194 [USACO05DEC] Scales S

    看似n<=1000，但其实根据斐波那契数列，n最大不超过46，使用01背包的时间复杂度和空间复杂度都太大，
    故此题使用搜索减枝来做
*/
#include <iostream>
#include <climits>

using namespace std;

void dfs(int index, long long s);

const int MAX = 50;
int n, a[MAX];
long long c, sum[MAX], ans;
int main(void) {
    cin >> n >> c;
    int t = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i];
    }
    //前缀和sum[i] = a[1]+a[2]+...+a[i]
    for(int i = 0; i < n; i++) {
        sum[i+1] += sum[i];
    }
    
    dfs(n, 0);

    cout << ans;
    return 0;
}

void dfs(int index, long long s) {
    //cout << index << " " << s << endl;
    if(s > c) return;

    if(index == 0) {
        ans = max(ans, s);
        return;
    }

    //如果把之后的所有砝码都选也无法超过当前最大值，则不继续搜索
    if(s + sum[index] <= ans) return;

    // 选
    if(s + a[index] <= c)
        dfs(index-1, s + a[index]);

    // 不选
    dfs(index-1, s);    
}
/*
int main(void) {
    int index = 2;
    long long a = 1, b = 1;
    while(b < INT_MAX) {
        b = a+b;
        a = b-a;
        index++;
    }
    cout << "Fib[" << index-1 << "] = " << a; 
    return 0;
}
输出：Fib[46] = 1836311903
*/
