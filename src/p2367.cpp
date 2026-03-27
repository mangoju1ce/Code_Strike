/*
    P2367 语文成绩

    差分：考虑数组 1 2 3 4 5，相应差分数组为 1 1 1 1 1,若想将数组中第1~3个数加1
    则只需要dif[1]+=1, dif[4]-=1,得到2 1 1 0 1 然后做前缀和即可 2 3 4 4 5。

    注意成绩最高分就是100分
*/
#include <iostream>

using namespace std;

const int MAX = 5e6+5;
int a[MAX], dif[MAX];
int main(void) {
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        dif[i] = a[i]-a[i-1];
    }

    int x, y, z;
    for(int i = 0; i < p; i++) {
        cin >> x >> y >> z;
        dif[x] += z;
        dif[y+1] -= z;
    }

    int ans = 100;
    for(int i = 1; i <= n; i++) {
        a[i] = a[i-1]+dif[i];
        ans = min(ans, a[i]);
    }

    cout << ans;
    return 0;
}