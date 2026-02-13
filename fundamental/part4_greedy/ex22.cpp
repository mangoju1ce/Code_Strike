/*
    P2672 [NOIP 2015 普及组] 推销员

    将n户人家按疲劳值从大到小排序，对于需要推销X户人家，每次先选择排序后的前X户人家，保证销售疲劳值
    最大，再来考虑距离疲劳值，记录1~X户人家中最大距离为S1，对X+1~N户人家，寻找是否存在距离大于S1的
    住户，若存在，假设记为S2，对比(S2-S1)*2 与 A1-A2，其中前式表示因为距离增长而多出的疲劳值，后式
    中A1表示1~X户人家中销售疲劳值的最小值，即第X户人家的销售疲劳值，A2表示X+1~N户人家中距离大于S1的
    住户的销售疲劳值，该式表示因替换第X户人家而减少的疲劳值，若式子比较为大于，则替换，替换后更新前X户
    人家的最大距离，继续遍历

    第一版代码，排序时间复杂度为O(nlgn) 遍历时间复杂度为O(n*n)，第10~13个测试点TLE

    考虑采用前缀和数组优化1~X-1户人家的疲劳值之和，最后1户其实就是剩余人家中2*s+a最大的，选出了X户人家
    只需解决最远距离然后计算即可
*/
#include <iostream>
#include <algorithm>
#define MAX 100005

struct Node {
    int s;// 距离
    int a;// 疲劳值
};
using namespace std;

bool cmp(Node x, Node y) {
    return x.a > y.a;
}

Node nodes[MAX];
int S[MAX], T[MAX], Q[MAX];
//其中S数组为排序后对疲劳值的前缀和数组,T[i]表示i~N中贡献值2*s+a最大值,Q[i]表示1~i中s最大值
int main(void) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nodes[i].s;
    }
    for(int i = 1; i <= n; i++) {
        cin >> nodes[i].a;
    }

    sort(nodes+1, nodes+n+1, cmp);
    //计算nodes[i].a的前缀和数组
    for(int i = 1; i <= n; i++) {
        S[i] = S[i-1] + nodes[i].a;
    }

    //计算nodes[i].s的最大值数组
    for(int i = 1; i <= n; i++) {
        Q[i] = max(Q[i-1], nodes[i].s);
    }

    for(int i = n; i >= 1; i--) {
        T[i] = max(T[i+1], 2*nodes[i].s+nodes[i].a);
    }

    for(int x = 1; x <= n; x++) {
        int ans = 0;
        ans += S[x];
        if(T[x+1] > 2*Q[x]+nodes[x].a){
            ans = ans + T[x+1] - nodes[x].a; 
        } else {
            ans = ans + 2*Q[x];
        }
        cout << ans << endl;
    }
    return 0;

}
/*
#include <iostream>
#include <algorithm>
#define MAX 100005

struct Node {
    int s;// 距离
    int a;// 疲劳值
};
using namespace std;

bool cmp(Node x, Node y) {
    return x.a > y.a;
}

Node nodes[MAX];
int main(void) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nodes[i].s;
    }
    for(int i = 1; i <= n; i++) {
        cin >> nodes[i].a;
    }

    sort(nodes+1, nodes+n+1, cmp);
    int x = 1;
    while(x <= n) {
        int ans = 0, max = 0, index = x;
        for(int i = 1; i <= x; i++) {
            ans += nodes[i].a;
            if(nodes[i].s > max) max = nodes[i].s;
        }
        for(int i = x+1; i <= n; i++) {
            if(nodes[i].s > max) {
                if(2*(nodes[i].s-max) > nodes[index].a - nodes[i].a){
                    ans = ans + nodes[i].a - nodes[index].a;
                    max = nodes[i].s;
                    index = i;
                }
            }
        }
        ans += 2*max;
        cout << ans << endl;
        x++;
    }
    return 0;

}
*/