/*
    p1429 平面最近点对（加强版）
    1.暴力枚举每组点对，时间复杂度为O(n^2)
    2.分治解决，用一条线将平面分为s1，s2两个集合，取s1，s2中点对最短距离分别为d1，d2
    则d = min(d1,d2, d[p,q])其中p在s1中，q在s2中
    则T(n) = 2T(n/2) + O(n^2)得时间复杂度为O(n^2 * log2n)负优化
    取d = min(d1,d2) 则p，q都必在与直线距离d范围内

    考虑采用分治方法解决，将点的横坐标从小到大排序，每次取竖直线x = t,其中t为一组点横坐标的中位数，
    这时候取d = min(d1,d2)，只需要考虑区间[t-d,t+d]内的点即可。将这里的点按纵坐标排序，对于每一个
    p，暴力枚举每一个满足纵坐标之差小于d的q（q是有限的，小于6，可以证明）
    则分治时间复杂度T(n) = 2T(n/2) + O(nlogn),得T = O(nlogn*logn)
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> // 使用其中的setprecison函数，设置输出实数的小数位数
#define MAX 200005

using namespace std;
struct Node{
    int x;
    int y;
};

bool cmp_x(Node a, Node b){
    return a.x < b.x;
}

bool cmp_y(Node a, Node b){
    return a.y < b.y;
}

inline long long distance(Node a, Node b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx*dx + dy*dy;
} // 内联函数，对于比较常用的函数或者希望开销较小的函数使用，告诉编译器不要调用函数，直接替换文本内容

long long solve(int l, int r);
Node nodes[MAX], L[MAX], R[MAX];
int main(void) {
    int n;
    cin >> n;

    for(int i = 0; i < n ; i++) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    sort(nodes, nodes+n, cmp_x);

    cout << fixed << setprecision(4) << sqrt(solve(0, n-1));
    return 0;
}

long long solve(int l, int r){
    if(l >= r) return LLONG_MAX;
    if(l+1 == r) return distance(nodes[l], nodes[r]);

    int mid = (l+r) >> 1, mid_x = nodes[mid].x;
    long long d = min(solve(l, mid), solve(mid+1, r));

    int ln = 0, rn = 0;
    for(int i = mid; i >= l; i--) {
        long long dx = nodes[i].x - mid_x;
        if(dx * dx > d) break;
        L[ln++] = nodes[i]; 
    }
    for(int i = mid+1; i <= r; i++) {
        long long dx = nodes[i].x - mid_x;
        if(dx*dx > d) break;
        R[rn++] = nodes[i]; 
    }

    sort(L, L+ln, cmp_y);
    sort(R, R+rn, cmp_y);
    for(int i = 0; i < ln; i++) {
        for(int j = 0; j < rn; j++) {
            long long dy = R[j].y - L[i].y ;
            //L和R已经按y排序，这里去掉头和尾
            if(dy * dy >= d) {
                if(dy < 0) continue;
                else break;
            }
            d = min(d, distance(L[i], R[j]));
        }
    }
    return d;
}